################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_uart.c 

OBJS += \
./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_uart.o 

C_DEPS += \
./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_uart.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F4xx_HAL_Driver/Inc/%.o Drivers/STM32F4xx_HAL_Driver/Inc/%.su: ../Drivers/STM32F4xx_HAL_Driver/Inc/%.c Drivers/STM32F4xx_HAL_Driver/Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I"C:/Users/osari/Desktop/32F401RE/Workspace/RTOS_workspace/BasicTaskCreation/ThirdParty/SEGGER/Config" -I"C:/Users/osari/Desktop/32F401RE/Workspace/RTOS_workspace/BasicTaskCreation/ThirdParty/SEGGER/OS" -I"C:/Users/osari/Desktop/32F401RE/Workspace/RTOS_workspace/BasicTaskCreation/ThirdParty/SEGGER/SEGGER" -I"C:/Users/osari/Desktop/32F401RE/Workspace/RTOS_workspace/BasicTaskCreation/ThirdParty/FreeRTOS" -I"C:/Users/osari/Desktop/32F401RE/Workspace/RTOS_workspace/BasicTaskCreation/ThirdParty/FreeRTOS/include" -I"C:/Users/osari/Desktop/32F401RE/Workspace/RTOS_workspace/BasicTaskCreation/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32F4xx_HAL_Driver-2f-Inc

clean-Drivers-2f-STM32F4xx_HAL_Driver-2f-Inc:
	-$(RM) ./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_uart.d ./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_uart.o ./Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal_uart.su

.PHONY: clean-Drivers-2f-STM32F4xx_HAL_Driver-2f-Inc

