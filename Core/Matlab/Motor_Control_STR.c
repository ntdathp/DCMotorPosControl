/*
 * File: Motor_Control_STR.c
 *
 * Code generated for Simulink model 'Motor_Control_STR'.
 *
 * Model version                  : 12.10
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Tue Dec 17 22:47:01 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Motor_Control_STR.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include <string.h>

/* Exported block signals */
real_T Sensor;                         /* '<Root>/Sensor' */
real_T Case;                           /* '<Root>/Case' */
real_T Setpoint;                       /* '<Root>/Setpoint' */
real_T Kp;                             /* '<Root>/Kp' */
real_T Ki;                             /* '<Root>/Ki' */
real_T Kd;                             /* '<Root>/Kd' */
real_T K1;                             /* '<Root>/K1' */
real_T K2;                             /* '<Root>/K2' */
real_T xi;                             /* '<Root>/xi' */
real_T pwm3;                           /* '<S3>/Saturation' */
real_T pwm2;                           /* '<S1>/Saturation' */
real_T pwm1;                           /* '<S2>/Saturation' */

/* Block signals (default storage) */
B_Motor_Control_STR_T Motor_Control_STR_B;

/* Block states (default storage) */
DW_Motor_Control_STR_T Motor_Control_STR_DW;

/* Real-time model */
static RT_MODEL_Motor_Control_STR_T Motor_Control_STR_M_;
RT_MODEL_Motor_Control_STR_T *const Motor_Control_STR_M = &Motor_Control_STR_M_;

/* Model step function */
void Motor_Control_STR_step(void)
{
  real_T Theta_tmp_0[16];
  real_T tmp[16];
  real_T PHI[4];
  real_T Theta_tmp[4];
  real_T PHI_0;
  real_T Theta_tmp_1;
  real_T b_gamma;
  real_T d1;
  real_T q2;
  real_T rtb_NProdOut;
  real_T rtb_Sum;
  real_T rtb_Sum_o;
  real_T rtb_UnitDelay3_b;
  real_T rtb_UnitDelay_j;
  int32_T PHI_tmp;
  int32_T i;
  int32_T tmp_0;
  int32_T tmp_1;

  /* SwitchCase: '<Root>/Switch Case' incorporates:
   *  Inport: '<Root>/Case'
   */
  rtb_Sum = trunc(Case);
  if (rtIsNaN(rtb_Sum) || rtIsInf(rtb_Sum)) {
    rtb_Sum = 0.0;
  } else {
    rtb_Sum = fmod(rtb_Sum, 4.294967296E+9);
  }

  switch (rtb_Sum < 0.0 ? -(int32_T)(uint32_T)-rtb_Sum : (int32_T)(uint32_T)
          rtb_Sum) {
   case 1:
    /* Outputs for IfAction SubSystem: '<Root>/Switch Case Action Subsystem1' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    /* Sum: '<S2>/Sum' incorporates:
     *  Inport: '<Root>/Sensor'
     *  Inport: '<Root>/Setpoint'
     */
    rtb_Sum_o = Setpoint - Sensor;

    /* Product: '<S44>/NProd Out' incorporates:
     *  Constant: '<S2>/Constant'
     *  DiscreteIntegrator: '<S36>/Filter'
     *  Inport: '<Root>/Kd'
     *  Product: '<S35>/DProd Out'
     *  Sum: '<S36>/SumD'
     */
    rtb_NProdOut = (rtb_Sum_o * Kd - Motor_Control_STR_DW.Filter_DSTATE) * 100.0;

    /* Sum: '<S50>/Sum' incorporates:
     *  DiscreteIntegrator: '<S41>/Integrator'
     *  Inport: '<Root>/Kp'
     *  Product: '<S46>/PProd Out'
     */
    rtb_Sum = (rtb_Sum_o * Kp + Motor_Control_STR_DW.Integrator_DSTATE) +
      rtb_NProdOut;

    /* Saturate: '<S2>/Saturation' */
    if (rtb_Sum > 100.0) {
      /* Saturate: '<S2>/Saturation' */
      pwm1 = 100.0;
    } else if (rtb_Sum < -100.0) {
      /* Saturate: '<S2>/Saturation' */
      pwm1 = -100.0;
    } else {
      /* Saturate: '<S2>/Saturation' */
      pwm1 = rtb_Sum;
    }

    /* End of Saturate: '<S2>/Saturation' */

    /* Update for DiscreteIntegrator: '<S36>/Filter' */
    Motor_Control_STR_DW.Filter_DSTATE += 0.005 * rtb_NProdOut;

    /* Update for DiscreteIntegrator: '<S41>/Integrator' incorporates:
     *  Inport: '<Root>/Ki'
     *  Product: '<S38>/IProd Out'
     */
    Motor_Control_STR_DW.Integrator_DSTATE += rtb_Sum_o * Ki * 0.005;

    /* End of Outputs for SubSystem: '<Root>/Switch Case Action Subsystem1' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<Root>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S1>/Action Port'
     */
    /* UnitDelay: '<S5>/Unit Delay3' */
    rtb_Sum_o = pwm2;

    /* UnitDelay: '<S5>/Unit Delay6' */
    rtb_NProdOut = Motor_Control_STR_DW.UnitDelay6_DSTATE;

    /* MATLAB Function: '<S5>/Embedded MATLAB Function' incorporates:
     *  Inport: '<Root>/Sensor'
     *  UnitDelay: '<S5>/Unit Delay'
     *  UnitDelay: '<S5>/Unit Delay1'
     *  UnitDelay: '<S5>/Unit Delay2'
     *  UnitDelay: '<S5>/Unit Delay3'
     *  UnitDelay: '<S5>/Unit Delay5'
     *  UnitDelay: '<S5>/Unit Delay6'
     */
    PHI[0] = -Motor_Control_STR_DW.UnitDelay6_DSTATE;
    PHI[1] = -Motor_Control_STR_DW.UnitDelay5_DSTATE;
    PHI[2] = pwm2;
    PHI[3] = Motor_Control_STR_DW.UnitDelay2_DSTATE;
    rtb_Sum = Sensor - (((-Motor_Control_STR_DW.UnitDelay6_DSTATE *
                          Motor_Control_STR_DW.UnitDelay_DSTATE_j[0] +
                          -Motor_Control_STR_DW.UnitDelay5_DSTATE *
                          Motor_Control_STR_DW.UnitDelay_DSTATE_j[1]) + pwm2 *
                         Motor_Control_STR_DW.UnitDelay_DSTATE_j[2]) +
                        Motor_Control_STR_DW.UnitDelay2_DSTATE *
                        Motor_Control_STR_DW.UnitDelay_DSTATE_j[3]);
    q2 = 0.0;
    for (i = 0; i < 4; i++) {
      PHI_tmp = i << 2;
      q2 += (((Motor_Control_STR_DW.UnitDelay1_DSTATE[PHI_tmp + 1] *
               -Motor_Control_STR_DW.UnitDelay5_DSTATE +
               Motor_Control_STR_DW.UnitDelay1_DSTATE[PHI_tmp] *
               -Motor_Control_STR_DW.UnitDelay6_DSTATE) +
              Motor_Control_STR_DW.UnitDelay1_DSTATE[PHI_tmp + 2] * pwm2) +
             Motor_Control_STR_DW.UnitDelay1_DSTATE[PHI_tmp + 3] *
             Motor_Control_STR_DW.UnitDelay2_DSTATE) * PHI[i];
    }

    PHI_0 = 0.0;
    for (i = 0; i < 4; i++) {
      b_gamma = ((Motor_Control_STR_DW.UnitDelay1_DSTATE[i + 4] *
                  -Motor_Control_STR_DW.UnitDelay5_DSTATE +
                  Motor_Control_STR_DW.UnitDelay1_DSTATE[i] *
                  -Motor_Control_STR_DW.UnitDelay6_DSTATE) +
                 Motor_Control_STR_DW.UnitDelay1_DSTATE[i + 8] * pwm2) +
        Motor_Control_STR_DW.UnitDelay1_DSTATE[i + 12] *
        Motor_Control_STR_DW.UnitDelay2_DSTATE;
      Theta_tmp[i] = b_gamma;
      PHI_tmp = i << 2;
      PHI_0 += (((Motor_Control_STR_DW.UnitDelay1_DSTATE[PHI_tmp + 1] *
                  -Motor_Control_STR_DW.UnitDelay5_DSTATE +
                  Motor_Control_STR_DW.UnitDelay1_DSTATE[PHI_tmp] *
                  -Motor_Control_STR_DW.UnitDelay6_DSTATE) +
                 Motor_Control_STR_DW.UnitDelay1_DSTATE[PHI_tmp + 2] * pwm2) +
                Motor_Control_STR_DW.UnitDelay1_DSTATE[PHI_tmp + 3] *
                Motor_Control_STR_DW.UnitDelay2_DSTATE) * PHI[i];
      Motor_Control_STR_B.Theta[i] = b_gamma / (q2 + 0.99) * rtb_Sum +
        Motor_Control_STR_DW.UnitDelay_DSTATE_j[i];
    }

    /* Sum: '<S6>/Sum' incorporates:
     *  Inport: '<Root>/Sensor'
     *  Inport: '<Root>/Setpoint'
     */
    rtb_Sum = Setpoint - Sensor;

    /* UnitDelay: '<S6>/Unit Delay' */
    rtb_UnitDelay_j = Motor_Control_STR_DW.UnitDelay_DSTATE_c;

    /* UnitDelay: '<S6>/Unit Delay3' */
    rtb_UnitDelay3_b = Motor_Control_STR_DW.UnitDelay3_DSTATE_i;

    /* MATLAB Function: '<S6>/MATLAB Function' incorporates:
     *  Inport: '<Root>/xi'
     *  SignalConversion generated from: '<S8>/ SFunction '
     *  UnitDelay: '<S6>/Unit Delay'
     *  UnitDelay: '<S6>/Unit Delay1'
     *  UnitDelay: '<S6>/Unit Delay2'
     *  UnitDelay: '<S6>/Unit Delay3'
     */
    if (xi < 1.0) {
      d1 = exp(-xi * 4.0 * 0.005) * -2.0 * cos(sqrt(1.0 - xi * xi) * 0.02);
    } else {
      d1 = exp(-xi * 4.0 * 0.005) * -2.0 * cosh(sqrt(xi * xi - 1.0) * 0.02);
    }

    q2 = Motor_Control_STR_B.Theta[2] + Motor_Control_STR_B.Theta[3];
    q2 = (((exp(-2.0 * xi * 4.0 * 0.005) * Motor_Control_STR_B.Theta[2] -
            Motor_Control_STR_B.Theta[3] * d1) - Motor_Control_STR_B.Theta[3]) *
          Motor_Control_STR_B.Theta[3] + (Motor_Control_STR_B.Theta[0] *
           Motor_Control_STR_B.Theta[3] - Motor_Control_STR_B.Theta[1] *
           Motor_Control_STR_B.Theta[2]) * q2) * Motor_Control_STR_B.Theta[1] /
      (((Motor_Control_STR_B.Theta[0] * Motor_Control_STR_B.Theta[2] *
         Motor_Control_STR_B.Theta[3] - Motor_Control_STR_B.Theta[2] *
         Motor_Control_STR_B.Theta[2] * Motor_Control_STR_B.Theta[1]) -
        Motor_Control_STR_B.Theta[3] * Motor_Control_STR_B.Theta[3]) * q2);
    b_gamma = q2 * Motor_Control_STR_B.Theta[3] / Motor_Control_STR_B.Theta[1];
    d1 = ((((Motor_Control_STR_B.Theta[1] / Motor_Control_STR_B.Theta[3] -
             ((Motor_Control_STR_B.Theta[2] / Motor_Control_STR_B.Theta[3] -
               Motor_Control_STR_B.Theta[0] / Motor_Control_STR_B.Theta[1]) +
              1.0) * q2) * Motor_Control_STR_DW.UnitDelay_DSTATE_c + (((d1 + 1.0)
              - Motor_Control_STR_B.Theta[0]) - b_gamma) /
            Motor_Control_STR_B.Theta[2] * rtb_Sum) + q2 *
           Motor_Control_STR_DW.UnitDelay2_DSTATE_a) + (1.0 - b_gamma) *
          Motor_Control_STR_DW.UnitDelay3_DSTATE_i) + b_gamma *
      Motor_Control_STR_DW.UnitDelay1_DSTATE_j;

    /* End of MATLAB Function: '<S6>/MATLAB Function' */

    /* Saturate: '<S1>/Saturation' */
    if (d1 > 100.0) {
      /* Saturate: '<S1>/Saturation' */
      pwm2 = 100.0;
    } else if (d1 < -100.0) {
      /* Saturate: '<S1>/Saturation' */
      pwm2 = -100.0;
    } else {
      /* Saturate: '<S1>/Saturation' */
      pwm2 = d1;
    }

    /* End of Saturate: '<S1>/Saturation' */

    /* Update for UnitDelay: '<S5>/Unit Delay2' */
    Motor_Control_STR_DW.UnitDelay2_DSTATE = rtb_Sum_o;

    /* Update for UnitDelay: '<S5>/Unit Delay6' incorporates:
     *  Inport: '<Root>/Sensor'
     */
    Motor_Control_STR_DW.UnitDelay6_DSTATE = Sensor;

    /* Update for UnitDelay: '<S5>/Unit Delay5' */
    Motor_Control_STR_DW.UnitDelay5_DSTATE = rtb_NProdOut;

    /* MATLAB Function: '<S5>/Embedded MATLAB Function' incorporates:
     *  UnitDelay: '<S5>/Unit Delay1'
     */
    b_gamma = Theta_tmp[0];
    rtb_Sum_o = Theta_tmp[1];
    rtb_NProdOut = Theta_tmp[2];
    Theta_tmp_1 = Theta_tmp[3];
    for (i = 0; i < 4; i++) {
      q2 = PHI[i];
      PHI_tmp = i << 2;
      Theta_tmp_0[PHI_tmp] = b_gamma * q2;
      Theta_tmp_0[PHI_tmp + 1] = rtb_Sum_o * q2;
      Theta_tmp_0[PHI_tmp + 2] = rtb_NProdOut * q2;
      Theta_tmp_0[PHI_tmp + 3] = Theta_tmp_1 * q2;
    }

    for (i = 0; i < 4; i++) {
      b_gamma = Theta_tmp_0[i + 4];
      rtb_Sum_o = Theta_tmp_0[i];
      rtb_NProdOut = Theta_tmp_0[i + 8];
      Theta_tmp_1 = Theta_tmp_0[i + 12];
      for (PHI_tmp = 0; PHI_tmp < 4; PHI_tmp++) {
        tmp_0 = PHI_tmp << 2;
        tmp_1 = tmp_0 + i;
        tmp[tmp_1] = Motor_Control_STR_DW.UnitDelay1_DSTATE[tmp_1] -
          (((Motor_Control_STR_DW.UnitDelay1_DSTATE[tmp_0 + 1] * b_gamma +
             Motor_Control_STR_DW.UnitDelay1_DSTATE[tmp_0] * rtb_Sum_o) +
            Motor_Control_STR_DW.UnitDelay1_DSTATE[tmp_0 + 2] * rtb_NProdOut) +
           Motor_Control_STR_DW.UnitDelay1_DSTATE[tmp_0 + 3] * Theta_tmp_1) /
          (PHI_0 + 0.99);
      }
    }

    /* Update for UnitDelay: '<S5>/Unit Delay1' incorporates:
     *  MATLAB Function: '<S5>/Embedded MATLAB Function'
     */
    for (i = 0; i < 16; i++) {
      Motor_Control_STR_DW.UnitDelay1_DSTATE[i] = 1.0101010101010102 * tmp[i];
    }

    /* End of Update for UnitDelay: '<S5>/Unit Delay1' */

    /* Update for UnitDelay: '<S5>/Unit Delay' */
    Motor_Control_STR_DW.UnitDelay_DSTATE_j[0] = Motor_Control_STR_B.Theta[0];
    Motor_Control_STR_DW.UnitDelay_DSTATE_j[1] = Motor_Control_STR_B.Theta[1];
    Motor_Control_STR_DW.UnitDelay_DSTATE_j[2] = Motor_Control_STR_B.Theta[2];
    Motor_Control_STR_DW.UnitDelay_DSTATE_j[3] = Motor_Control_STR_B.Theta[3];

    /* Update for UnitDelay: '<S6>/Unit Delay' */
    Motor_Control_STR_DW.UnitDelay_DSTATE_c = rtb_Sum;

    /* Update for UnitDelay: '<S6>/Unit Delay2' */
    Motor_Control_STR_DW.UnitDelay2_DSTATE_a = rtb_UnitDelay_j;

    /* Update for UnitDelay: '<S6>/Unit Delay3' */
    Motor_Control_STR_DW.UnitDelay3_DSTATE_i = d1;

    /* Update for UnitDelay: '<S6>/Unit Delay1' */
    Motor_Control_STR_DW.UnitDelay1_DSTATE_j = rtb_UnitDelay3_b;

    /* End of Outputs for SubSystem: '<Root>/Switch Case Action Subsystem' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<Root>/Switch Case Action Subsystem2' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Sum: '<S3>/Add1' incorporates:
     *  Inport: '<Root>/K1'
     *  Inport: '<Root>/K2'
     *  Inport: '<Root>/Sensor'
     *  Inport: '<Root>/Setpoint'
     *  Product: '<S3>/Product'
     *  Product: '<S3>/Product1'
     *  Sum: '<S3>/Add'
     *  Sum: '<S58>/Add'
     *  UnitDelay: '<S58>/Unit Delay'
     */
    rtb_Sum = (Setpoint - Sensor) * K1 + (Sensor -
      Motor_Control_STR_DW.UnitDelay_DSTATE) * K2;

    /* Saturate: '<S3>/Saturation' */
    if (rtb_Sum > 100.0) {
      /* Saturate: '<S3>/Saturation' */
      pwm3 = 100.0;
    } else if (rtb_Sum < -100.0) {
      /* Saturate: '<S3>/Saturation' */
      pwm3 = -100.0;
    } else {
      /* Saturate: '<S3>/Saturation' */
      pwm3 = rtb_Sum;
    }

    /* End of Saturate: '<S3>/Saturation' */

    /* Update for UnitDelay: '<S58>/Unit Delay' incorporates:
     *  Inport: '<Root>/Sensor'
     */
    Motor_Control_STR_DW.UnitDelay_DSTATE = Sensor;

    /* End of Outputs for SubSystem: '<Root>/Switch Case Action Subsystem2' */
    break;
  }

  /* End of SwitchCase: '<Root>/Switch Case' */
}

/* Model initialize function */
void Motor_Control_STR_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(Motor_Control_STR_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Motor_Control_STR_B), 0,
                sizeof(B_Motor_Control_STR_T));

  /* exported global signals */
  pwm3 = 0.0;
  pwm2 = 0.0;
  pwm1 = 0.0;

  /* states (dwork) */
  (void) memset((void *)&Motor_Control_STR_DW, 0,
                sizeof(DW_Motor_Control_STR_T));

  /* external inputs */
  Sensor = 0.0;
  Case = 0.0;
  Setpoint = 0.0;
  Kp = 0.0;
  Ki = 0.0;
  Kd = 0.0;
  K1 = 0.0;
  K2 = 0.0;
  xi = 0.0;

  /* SystemInitialize for IfAction SubSystem: '<Root>/Switch Case Action Subsystem' */
  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay1' */
  memcpy(&Motor_Control_STR_DW.UnitDelay1_DSTATE[0],
         &Motor_Control_STR_ConstP.UnitDelay1_InitialCondition[0], sizeof(real_T)
         << 4U);

  /* InitializeConditions for UnitDelay: '<S5>/Unit Delay' */
  Motor_Control_STR_DW.UnitDelay_DSTATE_j[0] = -1.0;
  Motor_Control_STR_DW.UnitDelay_DSTATE_j[1] = 0.1;
  Motor_Control_STR_DW.UnitDelay_DSTATE_j[2] = 0.1;
  Motor_Control_STR_DW.UnitDelay_DSTATE_j[3] = 1.0;

  /* End of SystemInitialize for SubSystem: '<Root>/Switch Case Action Subsystem' */
}

/* Model terminate function */
void Motor_Control_STR_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
