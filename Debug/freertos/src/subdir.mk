################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../freertos/src/FreeRTOSCommonHooks.c \
../freertos/src/heap_3.c \
../freertos/src/list.c \
../freertos/src/port.c \
../freertos/src/queue.c \
../freertos/src/tasks.c 

OBJS += \
./freertos/src/FreeRTOSCommonHooks.o \
./freertos/src/heap_3.o \
./freertos/src/list.o \
./freertos/src/port.o \
./freertos/src/queue.o \
./freertos/src/tasks.o 

C_DEPS += \
./freertos/src/FreeRTOSCommonHooks.d \
./freertos/src/heap_3.d \
./freertos/src/list.d \
./freertos/src/port.d \
./freertos/src/queue.d \
./freertos/src/tasks.d 


# Each subdirectory must supply rules for building sources it contributes
freertos/src/%.o: ../freertos/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -D__USE_LPCOPEN -DCORE_M4 -DSDK_DEBUGCONSOLE=0 -I"C:\Users\Emilie1\Documents\MCUXpressoIDE_10.0.2_411\workspace\lpc_chip_40xx\inc" -I"C:\Users\Emilie1\Documents\MCUXpressoIDE_10.0.2_411\workspace\lpc_board_ea_devkit_4088\inc" -I"C:\Users\Emilie1\Documents\MCUXpressoIDE_10.0.2_411\workspace\freertos_queue\example\inc" -I"C:\Users\Emilie1\Documents\MCUXpressoIDE_10.0.2_411\workspace\freertos_queue\freertos\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fsingle-precision-constant -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


