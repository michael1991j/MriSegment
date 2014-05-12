################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DebugView.cpp \
../FindBoneFemer.cpp \
../FindBoneFemurTrans.cpp \
../FindBonePatella.cpp \
../FindBoneTibia.cpp \
../FindCartilage.cpp \
../LabeledResults.cpp \
../MRIOpenCV.cpp \
../MRIOpenCVSettings.cpp \
../MRIProcess.cpp \
../RunAll.cpp 

OBJS += \
./DebugView.o \
./FindBoneFemer.o \
./FindBoneFemurTrans.o \
./FindBonePatella.o \
./FindBoneTibia.o \
./FindCartilage.o \
./LabeledResults.o \
./MRIOpenCV.o \
./MRIOpenCVSettings.o \
./MRIProcess.o \
./RunAll.o 

CPP_DEPS += \
./DebugView.d \
./FindBoneFemer.d \
./FindBoneFemurTrans.d \
./FindBonePatella.d \
./FindBoneTibia.d \
./FindCartilage.d \
./LabeledResults.d \
./MRIOpenCV.d \
./MRIOpenCVSettings.d \
./MRIProcess.d \
./RunAll.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


