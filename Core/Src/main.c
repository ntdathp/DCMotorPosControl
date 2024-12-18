/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "Motor_Control_STR.h"
#include "Motor_Control_STR_private.h"
#include "user_define.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;

UART_HandleTypeDef huart4;

UART_Data t_data;

uint8_t urx_index = 0;
uint8_t urx = 0;
uint8_t urx_buff[MAX_LEN];
uint8_t utx_buff[MAX_LEN];

int16_t icounter;
float dposition;
int iu;

char cposition[10];
char csp[10];
char txbuf[50];
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_UART4_Init(void);
static void MX_TIM1_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM4_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(Motor_Control_STR_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  Motor_Control_STR_step();

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

void float_to_string(float number, char *buffer) {
    int int_part = (int)number;
    int decimal_part = (int)((number - int_part) * 100);
    if (decimal_part < 0) decimal_part = -decimal_part;

    int index = 0;

    if (number < 0) {
        buffer[index++] = '-';
        int_part = -int_part;
    }

    int temp = int_part;
    int len = 0;
    while (temp > 0) {
        temp /= 10;
        len++;
    }

    for (int i = len - 1; i >= 0; i--) {
        buffer[index + i] = (int_part % 10) + '0';
        int_part /= 10;
    }
    index += len > 0 ? len : 1;
    buffer[index++] = '.';

    buffer[index++] = (decimal_part / 10) + '0';
    buffer[index++] = (decimal_part % 10) + '0';
    buffer[index] = '\0';
}

void process_buffers(float dposition, float sp, char *cposition, char *csp, char *result) {
    if (dposition != 0) {
        float_to_string(dposition, cposition);
    } else {
        cposition[0] = '\0';
    }

    if (sp != 0) {
        float_to_string(sp, csp);
    } else {
        csp[0] = '\0';
    }

    result[0] = '\0';
    strcat(result, "Y, ");
    if (cposition[0] != '\0') {
        strcat(result, cposition);
        strcat(result, ", ");
    }
    if (csp[0] != '\0') {
        strcat(result, csp);
    }
    strcat(result, "\r\n");
}

bool StrCompare(char *pBuff, uint8_t *pSample, uint8_t nSize)
{
    for (int i = 0; i < nSize; i++)
    {
        if(pBuff[i] != pSample[i])
        {
            return false;
        }
    }
    return true;
}

void process_uart_string(char *uart_string, UART_Data *data) {
    char *token;

    memset(data, 0, sizeof(UART_Data));

    token = strtok(uart_string, ",");
    if (token) {
        strncpy(data->type, token, 3);
        data->type[3] = '\0';
    }

    token = strtok(NULL, ",");
    if (token) data->sp = atof(token);

    if (StrCompare(data->type, (uint8_t *)"PID", 3)) {
        Case = 1.0;
        token = strtok(NULL, ",");
        if (token) data->value1 = atof(token);

        token = strtok(NULL, ",");
        if (token) data->value2 = atof(token);

        token = strtok(NULL, ",");
        if (token) data->value3 = atof(token);
    }
    else if (StrCompare(data->type, (uint8_t *)"STR", 3)) {
        Case = 2.0;
    }
    else if (StrCompare(data->type, (uint8_t *)"LQR", 3)) {
        Case = 3.0;
        token = strtok(NULL, ",");
        if (token) data->value1 = atof(token);

        token = strtok(NULL, ",");
        if (token) data->value2 = atof(token);
    }
    else if (StrCompare(data->type, (uint8_t *)"C", 1)) {
    	int count = 0;
    	process_buffers(0.0, 0.0, cposition, csp, txbuf);
    	while (txbuf[count] != '\0' && txbuf[count] != '\n') {
    		count++;
    	}
    	HAL_UART_Transmit(&UART_COM, (uint8_t*)txbuf, (count+1), HAL_MAX_DELAY);
    }
}


void motor_set_duty(int32_t iduty)
{
    if (iduty >= 0)
    {
    	MOTOR_CONTROL_REGISTER = iduty;
    	HAL_GPIO_WritePin(DIR_Port, FOWARD_Pin, 1);
    	HAL_GPIO_WritePin(DIR_Port, BACKWARD_Pin, 0);
    }
    else
    {
    	MOTOR_CONTROL_REGISTER = abs(iduty);
    	HAL_GPIO_WritePin(DIR_Port, FOWARD_Pin, 0);
    	HAL_GPIO_WritePin(DIR_Port, BACKWARD_Pin, 1);
    }
}

void motor_read_encoder(float dpos, TIM_HandleTypeDef *htim)
{
	icounter = htim->Instance->CNT;
	dpos += (float)icounter / (float)PPR * NUMBER_OF_DEGREES_ON_A_CIRCLE;
	htim->Instance->CNT = 0;
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_UART4_Init();
  MX_TIM1_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&INTERUPT_TIMER);
  HAL_TIM_Encoder_Start(&ECODER_TIMER, TIM_CHANNEL_1);
  HAL_TIM_Encoder_Start(&ECODER_TIMER, TIM_CHANNEL_2);
  HAL_TIM_PWM_Start(&PWM_TIMER, TIM_CHANNEL_1);

  Motor_Control_STR_initialize();

  xi = 0.99;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  Motor_Control_STR_terminate();
  return 0;
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 192;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = 2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_Encoder_InitTypeDef sConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 0;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 65535;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI12;
  sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC1Filter = 0;
  sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC2Filter = 0;
  if (HAL_TIM_Encoder_Init(&htim1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 111;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 65535;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

}

/**
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 8399;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 99;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */

}

/**
  * @brief UART4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_UART4_Init(void)
{

  /* USER CODE BEGIN UART4_Init 0 */

  /* USER CODE END UART4_Init 0 */

  /* USER CODE BEGIN UART4_Init 1 */

  /* USER CODE END UART4_Init 1 */
  huart4.Instance = UART4;
  huart4.Init.BaudRate = 9600;
  huart4.Init.WordLength = UART_WORDLENGTH_8B;
  huart4.Init.StopBits = UART_STOPBITS_1;
  huart4.Init.Parity = UART_PARITY_NONE;
  huart4.Init.Mode = UART_MODE_TX_RX;
  huart4.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart4.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART4_Init 2 */

  /* USER CODE END UART4_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13|GPIO_PIN_14, GPIO_PIN_RESET);

  /*Configure GPIO pins : PB13 PB14 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

// Timer In
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == INTERUPT_TIMER_INSTANCE)
  {
	  int count = 0;
	 // Read encoder
	  motor_read_encoder(dposition, &ECODER_TIMER);
	 // switch case
	  switch ((int)Case) {
	          case 1:
	        	  Setpoint = t_data.sp;
	        	  Sensor = dposition;
	              Kp = t_data.value1;
	              Ki = t_data.value2;
	              Kd = t_data.value3;
	              rt_OneStep();
	              iu = (int)pwm1;
	              motor_set_duty(iu);


	        	  process_buffers(dposition, t_data.sp, cposition, csp, txbuf);
	        	  while (txbuf[count] != '\0' && txbuf[count] != '\n') {
	        	  	        count++;
	        	  	    }
	        	  HAL_UART_Transmit(&UART_COM, (uint8_t*)txbuf, (count+1), HAL_MAX_DELAY);
	              break;
	          case 2:
	        	  Setpoint = t_data.sp;
	        	  Sensor = dposition;
	        	  rt_OneStep();
	        	  iu = (int)pwm2;
	        	  motor_set_duty(iu);

	        	  process_buffers(dposition, t_data.sp, cposition, csp, txbuf);
	        	  while (txbuf[count] != '\0' && txbuf[count] != '\n') {
	        	  	        count++;
	        	  	    }
	        	  HAL_UART_Transmit(&UART_COM, (uint8_t*)txbuf, (count+1), HAL_MAX_DELAY);
	              break;
	          case 3:
	        	  Setpoint = t_data.sp;
	        	  Sensor = dposition;
	              K1 = t_data.value1;
	              K2 = t_data.value2;
	        	  rt_OneStep();
	        	  iu = (int)pwm3;
	        	  motor_set_duty(iu);

	        	  process_buffers(dposition, t_data.sp, cposition, csp, txbuf);
	        	  while (txbuf[count] != '\0' && txbuf[count] != '\n') {
	        	  	        count++;
	        	  	    }
	        	  HAL_UART_Transmit(&UART_COM, (uint8_t*)txbuf, (count+1), HAL_MAX_DELAY);
	              break;
	          default:
	        	  dposition = 0;
	        	  Motor_Control_STR_terminate();
	              break;
	      }

  }
}

// UART Interupt
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == UART_COM_INSTANCE)
	{
		if (urx != '\n')
		{
			urx_buff[urx_index] = urx;
			urx_index++;
		}
		else
		{
			urx_buff[urx_index] = urx;
			urx_index++;
			process_uart_string((char *)urx_buff, &t_data);
		}
	}
	HAL_UART_Receive_IT(&UART_COM, &urx, 1);
}


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
