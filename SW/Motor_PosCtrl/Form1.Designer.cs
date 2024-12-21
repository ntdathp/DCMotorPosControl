namespace Motor_PosCtrl
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.butStop = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.cbLQR = new System.Windows.Forms.CheckBox();
            this.button2 = new System.Windows.Forms.Button();
            this.cbSTR = new System.Windows.Forms.CheckBox();
            this.cbPID = new System.Windows.Forms.CheckBox();
            this.zed = new ZedGraph.ZedGraphControl();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.label9 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.textBox8 = new System.Windows.Forms.TextBox();
            this.textBox7 = new System.Windows.Forms.TextBox();
            this.textBox6 = new System.Windows.Forms.TextBox();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.textBox9 = new System.Windows.Forms.TextBox();
            this.cbBaudrate = new System.Windows.Forms.ComboBox();
            this.cbCOMport = new System.Windows.Forms.ComboBox();
            this.label10 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.butConnect = new System.Windows.Forms.Button();
            this.textBox12 = new System.Windows.Forms.TextBox();
            this.textBox11 = new System.Windows.Forms.TextBox();
            this.textBox10 = new System.Windows.Forms.TextBox();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.butStop);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.button1);
            this.groupBox1.Controls.Add(this.textBox2);
            this.groupBox1.Controls.Add(this.textBox1);
            this.groupBox1.Location = new System.Drawing.Point(28, 15);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox1.Size = new System.Drawing.Size(356, 159);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Setpoint";
            // 
            // butStop
            // 
            this.butStop.Location = new System.Drawing.Point(229, 131);
            this.butStop.Name = "butStop";
            this.butStop.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.butStop.Size = new System.Drawing.Size(105, 28);
            this.butStop.TabIndex = 12;
            this.butStop.Text = "Stop";
            this.butStop.UseVisualStyleBackColor = true;
            this.butStop.Click += new System.EventHandler(this.button3_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(39, 106);
            this.label2.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(87, 16);
            this.label2.TabIndex = 4;
            this.label2.Text = "Current Value";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(52, 42);
            this.label1.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(65, 16);
            this.label1.TabIndex = 3;
            this.label1.Text = "Set Value";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(82, 131);
            this.button1.Margin = new System.Windows.Forms.Padding(4);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(100, 28);
            this.button1.TabIndex = 2;
            this.button1.Text = "Start";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(141, 98);
            this.textBox2.Margin = new System.Windows.Forms.Padding(4);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(132, 22);
            this.textBox2.TabIndex = 1;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(141, 39);
            this.textBox1.Margin = new System.Windows.Forms.Padding(4);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(132, 22);
            this.textBox1.TabIndex = 0;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // groupBox2
            // 
            this.groupBox2.BackColor = System.Drawing.Color.Transparent;
            this.groupBox2.Controls.Add(this.cbLQR);
            this.groupBox2.Controls.Add(this.button2);
            this.groupBox2.Controls.Add(this.cbSTR);
            this.groupBox2.Controls.Add(this.cbPID);
            this.groupBox2.Location = new System.Drawing.Point(392, 15);
            this.groupBox2.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox2.Size = new System.Drawing.Size(276, 159);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Control Mode";
            this.groupBox2.Enter += new System.EventHandler(this.groupBox2_Enter);
            // 
            // cbLQR
            // 
            this.cbLQR.AutoSize = true;
            this.cbLQR.Location = new System.Drawing.Point(49, 102);
            this.cbLQR.Margin = new System.Windows.Forms.Padding(4);
            this.cbLQR.Name = "cbLQR";
            this.cbLQR.Size = new System.Drawing.Size(56, 20);
            this.cbLQR.TabIndex = 6;
            this.cbLQR.Text = "LQR";
            this.cbLQR.UseVisualStyleBackColor = true;
            this.cbLQR.CheckedChanged += new System.EventHandler(this.cbLQR_CheckedChanged);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(142, 39);
            this.button2.Margin = new System.Windows.Forms.Padding(4);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(100, 28);
            this.button2.TabIndex = 5;
            this.button2.Text = "Select";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // cbSTR
            // 
            this.cbSTR.AutoSize = true;
            this.cbSTR.Location = new System.Drawing.Point(49, 69);
            this.cbSTR.Margin = new System.Windows.Forms.Padding(4);
            this.cbSTR.Name = "cbSTR";
            this.cbSTR.Size = new System.Drawing.Size(57, 20);
            this.cbSTR.TabIndex = 1;
            this.cbSTR.Text = "STR";
            this.cbSTR.UseVisualStyleBackColor = true;
            this.cbSTR.CheckedChanged += new System.EventHandler(this.checkBox2_CheckedChanged);
            // 
            // cbPID
            // 
            this.cbPID.AutoSize = true;
            this.cbPID.Location = new System.Drawing.Point(49, 39);
            this.cbPID.Margin = new System.Windows.Forms.Padding(4);
            this.cbPID.Name = "cbPID";
            this.cbPID.Size = new System.Drawing.Size(51, 20);
            this.cbPID.TabIndex = 0;
            this.cbPID.Text = "PID";
            this.cbPID.UseVisualStyleBackColor = true;
            // 
            // zed
            // 
            this.zed.Location = new System.Drawing.Point(28, 181);
            this.zed.Margin = new System.Windows.Forms.Padding(5);
            this.zed.Name = "zed";
            this.zed.ScrollGrace = 0D;
            this.zed.ScrollMaxX = 0D;
            this.zed.ScrollMaxY = 0D;
            this.zed.ScrollMaxY2 = 0D;
            this.zed.ScrollMinX = 0D;
            this.zed.ScrollMinY = 0D;
            this.zed.ScrollMinY2 = 0D;
            this.zed.Size = new System.Drawing.Size(908, 431);
            this.zed.TabIndex = 2;
            // 
            // serialPort1
            // 
            this.serialPort1.BaudRate = 115200;
            this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort1_DataReceived);
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 200;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(963, 256);
            this.textBox3.Margin = new System.Windows.Forms.Padding(4);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(132, 22);
            this.textBox3.TabIndex = 3;
            this.textBox3.TextChanged += new System.EventHandler(this.textBox3_TextChanged);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.label9);
            this.groupBox3.Controls.Add(this.label8);
            this.groupBox3.Controls.Add(this.label7);
            this.groupBox3.Controls.Add(this.label6);
            this.groupBox3.Controls.Add(this.label5);
            this.groupBox3.Controls.Add(this.label4);
            this.groupBox3.Controls.Add(this.label3);
            this.groupBox3.Controls.Add(this.textBox8);
            this.groupBox3.Controls.Add(this.textBox7);
            this.groupBox3.Controls.Add(this.textBox6);
            this.groupBox3.Controls.Add(this.textBox5);
            this.groupBox3.Controls.Add(this.textBox4);
            this.groupBox3.Location = new System.Drawing.Point(729, 15);
            this.groupBox3.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox3.Size = new System.Drawing.Size(509, 159);
            this.groupBox3.TabIndex = 4;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Value for Controller";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(329, 114);
            this.label9.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(94, 16);
            this.label9.TabIndex = 11;
            this.label9.Text = "LQR Controller";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(95, 134);
            this.label8.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(89, 16);
            this.label8.TabIndex = 10;
            this.label8.Text = "PID Controller";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(263, 87);
            this.label7.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(22, 16);
            this.label7.TabIndex = 9;
            this.label7.Text = "K2";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(263, 44);
            this.label6.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(22, 16);
            this.label6.TabIndex = 8;
            this.label6.Text = "K1";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(8, 110);
            this.label5.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(23, 16);
            this.label5.TabIndex = 7;
            this.label5.Text = "Kd";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(8, 74);
            this.label4.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(18, 16);
            this.label4.TabIndex = 6;
            this.label4.Text = "Ki";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(8, 34);
            this.label3.Margin = new System.Windows.Forms.Padding(4, 0, 4, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(23, 16);
            this.label3.TabIndex = 5;
            this.label3.Text = "Kp";
            // 
            // textBox8
            // 
            this.textBox8.Location = new System.Drawing.Point(312, 84);
            this.textBox8.Margin = new System.Windows.Forms.Padding(4);
            this.textBox8.Name = "textBox8";
            this.textBox8.Size = new System.Drawing.Size(132, 22);
            this.textBox8.TabIndex = 4;
            // 
            // textBox7
            // 
            this.textBox7.Location = new System.Drawing.Point(312, 39);
            this.textBox7.Margin = new System.Windows.Forms.Padding(4);
            this.textBox7.Name = "textBox7";
            this.textBox7.Size = new System.Drawing.Size(132, 22);
            this.textBox7.TabIndex = 3;
            // 
            // textBox6
            // 
            this.textBox6.Location = new System.Drawing.Point(73, 106);
            this.textBox6.Margin = new System.Windows.Forms.Padding(4);
            this.textBox6.Name = "textBox6";
            this.textBox6.Size = new System.Drawing.Size(132, 22);
            this.textBox6.TabIndex = 2;
            // 
            // textBox5
            // 
            this.textBox5.Location = new System.Drawing.Point(73, 68);
            this.textBox5.Margin = new System.Windows.Forms.Padding(4);
            this.textBox5.Name = "textBox5";
            this.textBox5.Size = new System.Drawing.Size(132, 22);
            this.textBox5.TabIndex = 1;
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(73, 31);
            this.textBox4.Margin = new System.Windows.Forms.Padding(4);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(132, 22);
            this.textBox4.TabIndex = 0;
            // 
            // textBox9
            // 
            this.textBox9.Location = new System.Drawing.Point(963, 302);
            this.textBox9.Margin = new System.Windows.Forms.Padding(4);
            this.textBox9.Name = "textBox9";
            this.textBox9.Size = new System.Drawing.Size(132, 22);
            this.textBox9.TabIndex = 5;
            this.textBox9.TextChanged += new System.EventHandler(this.textBox9_TextChanged);
            // 
            // cbBaudrate
            // 
            this.cbBaudrate.FormattingEnabled = true;
            this.cbBaudrate.Location = new System.Drawing.Point(109, 96);
            this.cbBaudrate.Name = "cbBaudrate";
            this.cbBaudrate.Size = new System.Drawing.Size(121, 24);
            this.cbBaudrate.TabIndex = 7;
            // 
            // cbCOMport
            // 
            this.cbCOMport.FormattingEnabled = true;
            this.cbCOMport.Location = new System.Drawing.Point(109, 38);
            this.cbCOMport.Name = "cbCOMport";
            this.cbCOMport.Size = new System.Drawing.Size(121, 24);
            this.cbCOMport.TabIndex = 8;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(6, 46);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(60, 16);
            this.label10.TabIndex = 9;
            this.label10.Text = "COMport";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(6, 104);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(62, 16);
            this.label11.TabIndex = 10;
            this.label11.Text = "Baudrate";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.butConnect);
            this.groupBox4.Controls.Add(this.label11);
            this.groupBox4.Controls.Add(this.cbCOMport);
            this.groupBox4.Controls.Add(this.label10);
            this.groupBox4.Controls.Add(this.cbBaudrate);
            this.groupBox4.Location = new System.Drawing.Point(1115, 256);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(236, 227);
            this.groupBox4.TabIndex = 11;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Connect";
            // 
            // butConnect
            // 
            this.butConnect.Location = new System.Drawing.Point(66, 158);
            this.butConnect.Name = "butConnect";
            this.butConnect.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.butConnect.Size = new System.Drawing.Size(146, 28);
            this.butConnect.TabIndex = 11;
            this.butConnect.Text = "Connect";
            this.butConnect.UseVisualStyleBackColor = true;
            this.butConnect.Click += new System.EventHandler(this.butConnect_Click);
            // 
            // textBox12
            // 
            this.textBox12.Location = new System.Drawing.Point(963, 517);
            this.textBox12.Name = "textBox12";
            this.textBox12.Size = new System.Drawing.Size(100, 22);
            this.textBox12.TabIndex = 6;
            // 
            // textBox11
            // 
            this.textBox11.Location = new System.Drawing.Point(963, 451);
            this.textBox11.Name = "textBox11";
            this.textBox11.Size = new System.Drawing.Size(100, 22);
            this.textBox11.TabIndex = 6;
            // 
            // textBox10
            // 
            this.textBox10.Location = new System.Drawing.Point(963, 393);
            this.textBox10.Name = "textBox10";
            this.textBox10.Size = new System.Drawing.Size(100, 22);
            this.textBox10.TabIndex = 6;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.ClientSize = new System.Drawing.Size(1385, 687);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.textBox12);
            this.Controls.Add(this.textBox11);
            this.Controls.Add(this.textBox10);
            this.Controls.Add(this.textBox9);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.zed);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.CheckBox cbSTR;
        private System.Windows.Forms.CheckBox cbPID;
        private ZedGraph.ZedGraphControl zed;
        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBox8;
        private System.Windows.Forms.TextBox textBox7;
        private System.Windows.Forms.TextBox textBox6;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.TextBox textBox9;
        private System.Windows.Forms.ComboBox cbBaudrate;
        private System.Windows.Forms.ComboBox cbCOMport;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Button butConnect;
        private System.Windows.Forms.CheckBox cbLQR;
        private System.Windows.Forms.Button butStop;
        private System.Windows.Forms.TextBox textBox12;
        private System.Windows.Forms.TextBox textBox11;
        private System.Windows.Forms.TextBox textBox10;
    }
}

