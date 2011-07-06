################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ProjectEuler_Dasm80x86.c \
../src/error.c \
../src/graphics.c \
../src/p102.c \
../src/p305.c \
../src/p45.c 

OBJS += \
./src/ProjectEuler_Dasm80x86.o \
./src/error.o \
./src/graphics.o \
./src/p102.o \
./src/p305.o \
./src/p45.o 

C_DEPS += \
./src/ProjectEuler_Dasm80x86.d \
./src/error.d \
./src/graphics.d \
./src/p102.d \
./src/p305.d \
./src/p45.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


