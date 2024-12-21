/*
 * File: Motor_Control_STR.h
 *
 * Code generated for Simulink model 'Motor_Control_STR'.
 *
 * Model version                  : 12.25
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Sat Dec 21 08:24:32 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Motor_Control_STR_h_
#define RTW_HEADER_Motor_Control_STR_h_
#ifndef Motor_Control_STR_COMMON_INCLUDES_
#define Motor_Control_STR_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Motor_Control_STR_COMMON_INCLUDES_ */

#include "Motor_Control_STR_types.h"
#include <stddef.h>
#include <string.h>
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Theta[4];                     /* '<S5>/Embedded MATLAB Function' */
} B_Motor_Control_STR_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S58>/Unit Delay' */
  real_T UnitDelay2_DSTATE;            /* '<S5>/Unit Delay2' */
  real_T UnitDelay6_DSTATE;            /* '<S5>/Unit Delay6' */
  real_T UnitDelay5_DSTATE;            /* '<S5>/Unit Delay5' */
  real_T UnitDelay1_DSTATE[16];        /* '<S5>/Unit Delay1' */
  real_T UnitDelay_DSTATE_j[4];        /* '<S5>/Unit Delay' */
  real_T UnitDelay_DSTATE_f;           /* '<S6>/Unit Delay' */
  real_T UnitDelay2_DSTATE_m;          /* '<S6>/Unit Delay2' */
  real_T UnitDelay3_DSTATE_d;          /* '<S6>/Unit Delay3' */
  real_T UnitDelay1_DSTATE_n;          /* '<S6>/Unit Delay1' */
  real_T Filter_DSTATE;                /* '<S36>/Filter' */
  real_T Integrator_DSTATE;            /* '<S41>/Integrator' */
} DW_Motor_Control_STR_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: 1e5*eye(4)
   * Referenced by: '<S5>/Unit Delay1'
   */
  real_T UnitDelay1_InitialCondition[16];
} ConstP_Motor_Control_STR_T;

/* Real-time Model Data Structure */
struct tag_RTM_Motor_Control_STR_T {
  const char_T * volatile errorStatus;
};

/* Block signals (default storage) */
extern B_Motor_Control_STR_T Motor_Control_STR_B;

/* Block states (default storage) */
extern DW_Motor_Control_STR_T Motor_Control_STR_DW;

/* Constant parameters (default storage) */
extern const ConstP_Motor_Control_STR_T Motor_Control_STR_ConstP;

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T Sensor;                  /* '<Root>/Sensor' */
extern real_T Case;                    /* '<Root>/Case' */
extern real_T Setpoint;                /* '<Root>/Setpoint' */
extern real_T Kp;                      /* '<Root>/Kp' */
extern real_T Ki;                      /* '<Root>/Ki' */
extern real_T Kd;                      /* '<Root>/Kd' */
extern real_T K1;                      /* '<Root>/K1' */
extern real_T K2;                      /* '<Root>/K2' */
extern real_T lamda;                   /* '<Root>/lamda' */
extern real_T xi;                      /* '<Root>/xi' */
extern real_T wn;                      /* '<Root>/wn' */
extern real_T pwm3;                    /* '<S3>/Saturation' */
extern real_T pwm2;                    /* '<S1>/Saturation' */
extern real_T pwm1;                    /* '<S2>/Saturation' */

/* Model entry point functions */
extern void Motor_Control_STR_initialize(void);
extern void Motor_Control_STR_step(void);
extern void Motor_Control_STR_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Motor_Control_STR_T *const Motor_Control_STR_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Add' : Unused code path elimination
 * Block '<S4>/Unit Delay' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Motor_Control_STR'
 * '<S1>'   : 'Motor_Control_STR/Switch Case Action Subsystem'
 * '<S2>'   : 'Motor_Control_STR/Switch Case Action Subsystem1'
 * '<S3>'   : 'Motor_Control_STR/Switch Case Action Subsystem2'
 * '<S4>'   : 'Motor_Control_STR/Switch Case Action Subsystem/DC Motor'
 * '<S5>'   : 'Motor_Control_STR/Switch Case Action Subsystem/Identification'
 * '<S6>'   : 'Motor_Control_STR/Switch Case Action Subsystem/Self-Tuning Regulator'
 * '<S7>'   : 'Motor_Control_STR/Switch Case Action Subsystem/Identification/Embedded MATLAB Function'
 * '<S8>'   : 'Motor_Control_STR/Switch Case Action Subsystem/Self-Tuning Regulator/MATLAB Function'
 * '<S9>'   : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller'
 * '<S10>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Anti-windup'
 * '<S11>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/D Gain'
 * '<S12>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Filter'
 * '<S13>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Filter ICs'
 * '<S14>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/I Gain'
 * '<S15>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Ideal P Gain'
 * '<S16>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S17>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Integrator'
 * '<S18>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Integrator ICs'
 * '<S19>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/N Copy'
 * '<S20>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/N Gain'
 * '<S21>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/P Copy'
 * '<S22>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Parallel P Gain'
 * '<S23>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Reset Signal'
 * '<S24>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Saturation'
 * '<S25>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Saturation Fdbk'
 * '<S26>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Sum'
 * '<S27>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Sum Fdbk'
 * '<S28>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Tracking Mode'
 * '<S29>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Tracking Mode Sum'
 * '<S30>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Tsamp - Integral'
 * '<S31>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Tsamp - Ngain'
 * '<S32>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/postSat Signal'
 * '<S33>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/preSat Signal'
 * '<S34>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S35>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/D Gain/External Parameters'
 * '<S36>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S37>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S38>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/I Gain/External Parameters'
 * '<S39>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S40>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S41>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Integrator/Discrete'
 * '<S42>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S43>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/N Copy/Disabled'
 * '<S44>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/N Gain/External Parameters'
 * '<S45>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/P Copy/Disabled'
 * '<S46>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Parallel P Gain/External Parameters'
 * '<S47>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Reset Signal/Disabled'
 * '<S48>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Saturation/Passthrough'
 * '<S49>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S50>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Sum/Sum_PID'
 * '<S51>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S52>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S53>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S54>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S55>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S56>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S57>'  : 'Motor_Control_STR/Switch Case Action Subsystem1/Discrete PID Controller/preSat Signal/Forward_Path'
 * '<S58>'  : 'Motor_Control_STR/Switch Case Action Subsystem2/DC Motor'
 */
#endif                                 /* RTW_HEADER_Motor_Control_STR_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
