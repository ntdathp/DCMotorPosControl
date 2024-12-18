################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Matlab/Motor_Control_STR.c \
../Core/Matlab/Motor_Control_STR_data.c \
../Core/Matlab/rtGetInf.c \
../Core/Matlab/rtGetNaN.c \
../Core/Matlab/rt_nonfinite.c 

OBJS += \
./Core/Matlab/Motor_Control_STR.o \
./Core/Matlab/Motor_Control_STR_data.o \
./Core/Matlab/rtGetInf.o \
./Core/Matlab/rtGetNaN.o \
./Core/Matlab/rt_nonfinite.o 

C_DEPS += \
./Core/Matlab/Motor_Control_STR.d \
./Core/Matlab/Motor_Control_STR_data.d \
./Core/Matlab/rtGetInf.d \
./Core/Matlab/rtGetNaN.d \
./Core/Matlab/rt_nonfinite.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Matlab/%.o Core/Matlab/%.su Core/Matlab/%.cyclo: ../Core/Matlab/%.c Core/Matlab/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Core/Matlab -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Matlab

clean-Core-2f-Matlab:
	-$(RM) ./Core/Matlab/Motor_Control_STR.cyclo ./Core/Matlab/Motor_Control_STR.d ./Core/Matlab/Motor_Control_STR.o ./Core/Matlab/Motor_Control_STR.su ./Core/Matlab/Motor_Control_STR_data.cyclo ./Core/Matlab/Motor_Control_STR_data.d ./Core/Matlab/Motor_Control_STR_data.o ./Core/Matlab/Motor_Control_STR_data.su ./Core/Matlab/rtGetInf.cyclo ./Core/Matlab/rtGetInf.d ./Core/Matlab/rtGetInf.o ./Core/Matlab/rtGetInf.su ./Core/Matlab/rtGetNaN.cyclo ./Core/Matlab/rtGetNaN.d ./Core/Matlab/rtGetNaN.o ./Core/Matlab/rtGetNaN.su ./Core/Matlab/rt_nonfinite.cyclo ./Core/Matlab/rt_nonfinite.d ./Core/Matlab/rt_nonfinite.o ./Core/Matlab/rt_nonfinite.su

.PHONY: clean-Core-2f-Matlab

