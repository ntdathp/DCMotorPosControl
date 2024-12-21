using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ZedGraph;
using System.IO.Ports;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using System.IO;
using System.Timers;

namespace Motor_PosCtrl
{

    public partial class Form1 : Form
    {
        private System.Timers.Timer dataTimeoutTimer;
        private System.Timers.Timer checkTimeoutTimer;
        private bool isReceivingData = false;
        int TickStart, intMode = 1;
        public double uk, yk, uk1, yk1, uk2, yk2;
        public double temp, slpit_rcv, set_value;
        public double Kp, Ki, Kd, K1, K2;
        bool isdraw=false;
        bool butcon = true;
        bool firsttime = true;
        bool PID_Mode, STR_Mode, LQR_Mode, ready_flag;
        private void butConnect_Click(object sender, EventArgs e)
        {
            if (butcon==true)
            {
                butConnect.Text = "Connected";
                serialPort1.PortName = cbCOMport.Text;
                serialPort1.BaudRate = Convert.ToInt32(cbBaudrate.Text);
                serialPort1.Open();
                butcon = false;

                // Dừng timer trước khi reset
                timer1.Stop();
                // Đặt lại thời gian khởi đầu
                TickStart = Environment.TickCount;
                // Khởi động lại timer nếu cần
                timer1.Start();

                checkTimeoutTimer = new System.Timers.Timer(2000); // 1 giây
                checkTimeoutTimer.Elapsed += CheckTimeoutTimer_Elapsed;
                checkTimeoutTimer.AutoReset = false; // Chỉ chạy 1 lần, sẽ khởi động lại khi cần
                checkTimeoutTimer.Start();
                isReceivingData = true;

            }
            else {
                butConnect.Text = "Disconnected";
                serialPort1.Close();
                butcon = true;
                isdraw = false;
                checkTimeoutTimer.Stop();
                firsttime = true;
                isReceivingData = true;
            }  
        }
        private void CheckPortStatus()
        {
            // Lấy danh sách cổng COM hiện tại
            var availablePorts = SerialPort.GetPortNames();

            if (!availablePorts.Contains(serialPort1.PortName))
            {
                // Cổng COM đã bị mất
                OnPortDisconnected();
            }
            else if (!serialPort1.IsOpen)
            {
                // Cổng vẫn tồn tại nhưng bị đóng

            }
        }
        private void OnPortDisconnected()
        {

                serialPort1.Close();
                butConnect.Text = "Disconnected";
                butcon = true;
                isdraw = false;
                checkTimeoutTimer.Stop();
                firsttime = true;
            Invoke(new Action(() =>
            {
                MessageBox.Show("Clinet not found. Disconnect");
            }));

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (isdraw == true) 
            {
                Draw("set_value", "500"); 
            }
            textBox10.Text = isdraw.ToString();
            textBox11.Text = butcon.ToString();

            if (butcon == true)
            {
                var currentPorts = cbCOMport.Items.Cast<string>().ToList();

                // Lấy danh sách cổng COM mới
                var newPorts = SerialPort.GetPortNames().ToList();

                // So sánh danh sách
                if (!currentPorts.SequenceEqual(newPorts))
                {
                    // Nếu khác, cập nhật lại DataSource
                    cbCOMport.DataSource = newPorts;
                }
            }
            if (butcon == false)
            {
                CheckPortStatus();
            }
        }
        private void serialPort1_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
       {
            isReceivingData = true;
            if(isdraw == false)
            {
                checkTimeoutTimer.Stop();
                checkTimeoutTimer.Start();
            }    
            if(isdraw == true)
            { 
                dataTimeoutTimer.Stop(); // Dừng timer để tránh timeout
                dataTimeoutTimer.Start(); // Khởi động lại timer
            }
            slpit_rcv = 100;
            //Chia 2 thông số bởi dấu phẩy và lưu vào buffer sub_data
            string[] sub_data = serialPort1.ReadLine().Split(',');
            textBox2.Text = sub_data[1];
            //Chia giá trị nhận được cho 100 để nhận giá trị thập phân đúng
            double.TryParse(textBox2.Text, out temp);
            yk = temp;
            textBox12.Text = sub_data[2];
            //Nhận giá trị set_value cho đồ thị và xác nhận truyền setpoint cho stm đã thành công
            set_value = double.Parse(textBox12.Text);
        }
        private void CheckTimeoutTimer_Elapsed(object sender, System.Timers.ElapsedEventArgs e)
        {
            if (butcon == false && isdraw == false)
            {
                    serialPort1.WriteLine("C" + '\r');
                    checkTimeoutTimer.Start();

                if (isReceivingData == false && firsttime == false)
                {
                    if (serialPort1.IsOpen)
                    {
                        serialPort1.Close();
                        butConnect.Text = "Disconnected";
                        butcon = true;
                        isdraw = false;
                        firsttime = true;
                        checkTimeoutTimer.Stop();
                        isReceivingData = true;
                        Invoke(new Action(() =>
                        {
                            MessageBox.Show("The client did not respond. Disconnect");
                        }));
                    }
                }
                isReceivingData = false;
                firsttime = false;
            }
        }
            private void DataTimeoutTimer_Elapsed(object sender, System.Timers.ElapsedEventArgs e)
        {
            if (!isReceivingData)
            {
                if (serialPort1.IsOpen)
                {
                    serialPort1.Close();
                    butConnect.Text = "Disconnected";
                    butcon = true;
                    isdraw = false;
                    firsttime = true;
                    isReceivingData = true;
                    dataTimeoutTimer.Stop();

                    Invoke(new Action(() =>
                    {
                        MessageBox.Show("No data received. Disconnect");
                    }));
                }
            }
            // Reset trạng thái
            isReceivingData = false;
            if (isdraw)
            {
                dataTimeoutTimer.Start();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (!double.TryParse(textBox1.Text, out double inputValue))
            {
                MessageBox.Show("Invalid input.");
                return; 
            }
            if (!serialPort1.IsOpen)
            {
                MessageBox.Show("COMport not connected");
                return;
            }
            if (ready_flag)
                {
                    isdraw = true;
                    foreach (var curve in zed.GraphPane.CurveList)
                    {
                        if (curve is LineItem lineItem)
                        {
                            if (lineItem.Points is IPointListEdit pointList)
                            {
                                pointList.Clear(); // Xóa toàn bộ điểm trong danh sách
                            }
                        }
                    }
                    GraphPane myPane = zed.GraphPane;
                    myPane.XAxis.Scale.Min = 0;   // Đặt giá trị Min của trục X
                    myPane.XAxis.Scale.Max = 30; // Đặt giá trị Max của trục X
                    myPane.XAxis.Scale.MinorStep = 1;
                    myPane.XAxis.Scale.MajorStep = 5;

                    // Làm mới đồ thị
                    zed.AxisChange();
                    zed.Invalidate();
                    isdraw = true;
                    set_value = double.Parse(textBox1.Text);
                    if (PID_Mode == true)
                    {
                        textBox3.Text = "PID" + " " + textBox1.Text + " " + textBox4.Text + " " + textBox5.Text + " " + textBox6.Text + '\r';
                        serialPort1.WriteLine(textBox3.Text.ToString());
                    }
                    else if (STR_Mode == true)
                    {
                        textBox3.Text = "STR" + " " + textBox1.Text + '\r';
                        serialPort1.WriteLine(textBox3.Text.ToString());
                    }
                    else if (LQR_Mode == true)
                    {
                        textBox3.Text = "LQR" + " " + textBox1.Text + " " + textBox7.Text + " " + textBox8.Text + '\r';
                        serialPort1.WriteLine(textBox3.Text.ToString());
                    }
                    TickStart = Environment.TickCount;
                    dataTimeoutTimer = new System.Timers.Timer(1000); // 1 giây
                    dataTimeoutTimer.Elapsed += DataTimeoutTimer_Elapsed;
                    dataTimeoutTimer.AutoReset = false; // Chỉ chạy 1 lần, sẽ khởi động lại khi cần
                    dataTimeoutTimer.Start();
                    checkTimeoutTimer.Stop();
                }
                else
                {
                    MessageBox.Show("Please set plant parameters first!");
                }
            
            }

        private void button3_Click(object sender, EventArgs e)
        {
            // Dừng timer trước khi reset
            timer1.Stop();

            // Đặt lại thời gian khởi đầu
            TickStart = Environment.TickCount;

            // Reset đồ thị hoặc các dữ liệu khác nếu cần
            isdraw = false;

            // Khởi động lại timer nếu cần
            timer1.Start();

            serialPort1.WriteLine("STOP");
            checkTimeoutTimer.Start();
            dataTimeoutTimer.Stop();
        }
        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                if (cbPID.Checked == true && cbSTR.Checked == false && cbLQR.Checked == false)
                {
                    PID_Mode = true;
                    STR_Mode = false;
                    LQR_Mode = false;
                    ready_flag = true;
                    Kp = double.Parse(textBox4.Text);
                    Ki = double.Parse(textBox5.Text);
                    Kd = double.Parse(textBox6.Text);
                }
                else if (cbSTR.Checked == true && cbPID.Checked == false && cbLQR.Checked == false)
                {
                    PID_Mode = false;
                    STR_Mode = true;
                    LQR_Mode = false;
                    ready_flag = true;
                }
                else if (cbLQR.Checked == true && cbPID.Checked == false && cbPID.Checked == false)
                {
                    PID_Mode = false;
                    STR_Mode = false;
                    LQR_Mode = true;
                    ready_flag = true;
                    K1 = double.Parse(textBox7.Text);
                    K2 = double.Parse(textBox8.Text);
                }
                else
                {
                    MessageBox.Show("More than One mode is checked OR No Mode is Checked");
                }
                textBox9.Text = PID_Mode.ToString() + ";" + STR_Mode.ToString() + ";" + LQR_Mode.ToString();
            }
            catch
            {
                MessageBox.Show("Invalid Input");
            }
        }
        private void Draw(string setpoint, string current)
        {
            //Tao 1 curves
            double intsetpoint;
            double intcurrent;
            double.TryParse(setpoint, out intsetpoint);
            double.TryParse(current, out intcurrent);
            if (zed.GraphPane.CurveList.Count <= 0)
                return;
            // Tao item curve trong do thi
            LineItem curve = zed.GraphPane.CurveList[0] as LineItem;
            LineItem curve1 = zed.GraphPane.CurveList[1] as LineItem;
            if (curve == null)
                return;
            if (curve1 == null)
                return;

            //Lay pointpairlist2a
            IPointListEdit list = curve.Points as IPointListEdit;
            IPointListEdit list1 = curve1.Points as IPointListEdit;

            if (list == null)
                return;
            if (list1 == null)
                return;
            double time = (Environment.TickCount - TickStart) / 1000.0;
            list.Add(time,set_value);
            list1.Add(time, yk);

            Scale xScale = zed.GraphPane.XAxis.Scale;
            if (time > xScale.Max - xScale.MajorStep)
            {
                if (intMode == 1)
                {
                    xScale.Max = time + xScale.MajorStep;
                    xScale.Min = xScale.Max - 30.0;
                }
                else
                {
                    xScale.Max = time + xScale.MajorStep;
                    xScale.Min = 0;
                }
            }
            zed.AxisChange();
            zed.Invalidate();
        }
        private void textBox1_TextChanged(object sender, EventArgs e)
        {}
        private void textBox9_TextChanged(object sender, EventArgs e)
        {}
        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {}
        private void cbLQR_CheckedChanged(object sender, EventArgs e)
        {}
        private void textBox3_TextChanged(object sender, EventArgs e)
        {}
        private void groupBox2_Enter(object sender, EventArgs e)
        {}
        public Form1()
        {
            InitializeComponent();
            string[] baudrate = { "2400", "4800", "9600", "14400", "115200" };
            cbBaudrate.Items.AddRange(baudrate);
            Control.CheckForIllegalCrossThreadCalls = false;
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            cbCOMport.DataSource = SerialPort.GetPortNames();
            cbBaudrate.Text = "9600";
            Control.CheckForIllegalCrossThreadCalls = false;
           
            // Phan nay dat ten cho do thi va ten cho cac truc X Y
            GraphPane myPane = zed.GraphPane;
            myPane.Title.Text = "Position of Motor";
            myPane.XAxis.Title.Text = "Time";
            myPane.YAxis.Title.Text = "Position";

            //Tao khung thong bao 2 duong xanh do
            RollingPointPairList list = new RollingPointPairList(60000);
            RollingPointPairList list1 = new RollingPointPairList(60000);

            LineItem curve = myPane.AddCurve("Set Value", list, Color.Blue, SymbolType.None);
            LineItem curve1 = myPane.AddCurve("Current Value", list1, Color.Red, SymbolType.None);

            //Tao scale cho truc X
            myPane.XAxis.Scale.Min = 0;
            myPane.XAxis.Scale.Max = 30;
            myPane.XAxis.Scale.MinorStep = 1;
            myPane.XAxis.Scale.MajorStep = 5;
            zed.AxisChange();
            TickStart = Environment.TickCount;
        }
    }
}
