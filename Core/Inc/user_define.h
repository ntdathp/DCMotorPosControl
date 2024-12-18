#ifndef USERCODE_USER_DEFINE_H_
#define USERCODE_USER_DEFINE_H_

#include "main.h"

typedef struct {
    char type[4];
    float sp;
    float value1;
    float value2;
    float value3;
} UART_Data;

#define SAMPLING_TIME 0.01f // In second
#define NUMBER_OF_DEGREES_ON_A_CIRCLE 360.0f
#define THOUSAND 1000
#define ZERO 0.0f

#define ENCODER_COUNTER_REGISTER htim1.Instance->CNT
#define MOTOR_CONTROL_REGISTER htim3.Instance->CCR1

#define DIR_Port GPIOB
#define FOWARD_Pin GPIO_PIN_13
#define BACKWARD_Pin GPIO_PIN_14

#define PPR 11880

#define ECODER_TIMER htim1
#define PWM_TIMER htim3

#define INTERUPT_TIMER htim4
#define INTERUPT_TIMER_INSTANCE htim4.Instance

#define MAX_LEN 100
#define UART_COM huart4
#define UART_COM_INSTANCE huart4.Instance



#endif /* USERCODE_USER_DEFINE_H_ */
