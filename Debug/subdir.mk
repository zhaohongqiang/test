################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../al.c \
../dl.c \
../lib.c \
../pl.c \
../queue.c \
../sender.c \
../test_lib.c 

OBJS += \
./al.o \
./dl.o \
./lib.o \
./pl.o \
./queue.o \
./sender.o \
./test_lib.o 

C_DEPS += \
./al.d \
./dl.d \
./lib.d \
./pl.d \
./queue.d \
./sender.d \
./test_lib.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


