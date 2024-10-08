################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/main.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_hal_timebase_tim.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/tm_stm32_i2c.c \
../Core/Src/tm_stm32_i2c_dma.c \
../Core/Src/tm_stm32_spi.c \
../Core/Src/tm_stm32_usart.c 

OBJS += \
./Core/Src/main.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_hal_timebase_tim.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/tm_stm32_i2c.o \
./Core/Src/tm_stm32_i2c_dma.o \
./Core/Src/tm_stm32_spi.o \
./Core/Src/tm_stm32_usart.o 

C_DEPS += \
./Core/Src/main.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_hal_timebase_tim.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/tm_stm32_i2c.d \
./Core/Src/tm_stm32_i2c_dma.d \
./Core/Src/tm_stm32_spi.d \
./Core/Src/tm_stm32_usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I"C:/Users/osari/Desktop/32F401RE/Workspace/RTOS_workspace/BasicTaskCreation/ThirdParty/SEGGER/Config" -I"C:/Users/osari/Desktop/32F401RE/Workspace/RTOS_workspace/BasicTaskCreation/ThirdParty/SEGGER/OS" -I"C:/Users/osari/Desktop/32F401RE/Workspace/RTOS_workspace/BasicTaskCreation/ThirdParty/SEGGER/SEGGER" -I"C:/Users/osari/Desktop/32F401RE/Workspace/RTOS_workspace/BasicTaskCreation/ThirdParty/FreeRTOS" -I"C:/Users/osari/Desktop/32F401RE/Workspace/RTOS_workspace/BasicTaskCreation/ThirdParty/FreeRTOS/include" -I"C:/Users/osari/Desktop/32F401RE/Workspace/RTOS_workspace/BasicTaskCreation/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_hal_timebase_tim.d ./Core/Src/stm32f4xx_hal_timebase_tim.o ./Core/Src/stm32f4xx_hal_timebase_tim.su ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/tm_stm32_i2c.d ./Core/Src/tm_stm32_i2c.o ./Core/Src/tm_stm32_i2c.su ./Core/Src/tm_stm32_i2c_dma.d ./Core/Src/tm_stm32_i2c_dma.o ./Core/Src/tm_stm32_i2c_dma.su ./Core/Src/tm_stm32_spi.d ./Core/Src/tm_stm32_spi.o ./Core/Src/tm_stm32_spi.su ./Core/Src/tm_stm32_usart.d ./Core/Src/tm_stm32_usart.o ./Core/Src/tm_stm32_usart.su

.PHONY: clean-Core-2f-Src

