################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CFG_SRCS += \
../omp_config.cfg 

C_SRCS += \
../MAD_32x32_OMP.c \
../MAD_8x8_OMP.c \
../SAD_32x32_OMP.c \
../SAD_8x8_OMP.c \
../omp_hello.c 

OBJS += \
./MAD_32x32_OMP.obj \
./MAD_8x8_OMP.obj \
./SAD_32x32_OMP.obj \
./SAD_8x8_OMP.obj \
./omp_hello.obj 

GEN_SRCS += \
./configPkg/compiler.opt \
./configPkg/linker.cmd 

C_DEPS += \
./MAD_32x32_OMP.pp \
./MAD_8x8_OMP.pp \
./SAD_32x32_OMP.pp \
./SAD_8x8_OMP.pp \
./omp_hello.pp 

GEN_MISC_DIRS += \
./configPkg/ 

GEN_CMDS += \
./configPkg/linker.cmd 

GEN_OPTS += \
./configPkg/compiler.opt 

GEN_SRCS__QUOTED += \
"configPkg\compiler.opt" \
"configPkg\linker.cmd" 

GEN_MISC_DIRS__QUOTED += \
"configPkg\" 

C_DEPS__QUOTED += \
"MAD_32x32_OMP.pp" \
"MAD_8x8_OMP.pp" \
"SAD_32x32_OMP.pp" \
"SAD_8x8_OMP.pp" \
"omp_hello.pp" 

OBJS__QUOTED += \
"MAD_32x32_OMP.obj" \
"MAD_8x8_OMP.obj" \
"SAD_32x32_OMP.obj" \
"SAD_8x8_OMP.obj" \
"omp_hello.obj" 

C_SRCS__QUOTED += \
"../MAD_32x32_OMP.c" \
"../MAD_8x8_OMP.c" \
"../SAD_32x32_OMP.c" \
"../SAD_8x8_OMP.c" \
"../omp_hello.c" 

CFG_SRCS__QUOTED += \
"../omp_config.cfg" 

GEN_OPTS__FLAG += \
--cmd_file="./configPkg/compiler.opt" 

GEN_CMDS__FLAG += \
-l"./configPkg/linker.cmd" 


