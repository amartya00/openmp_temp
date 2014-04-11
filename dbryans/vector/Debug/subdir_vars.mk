################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CFG_SRCS += \
../app.cfg 

C_SRCS += \
../main.c \
../vector_stream_int16.c \
../vector_stream_sp.c 

OBJS += \
./main.obj \
./vector_stream_int16.obj \
./vector_stream_sp.obj 

GEN_SRCS += \
./configPkg/compiler.opt \
./configPkg/linker.cmd 

C_DEPS += \
./main.pp \
./vector_stream_int16.pp \
./vector_stream_sp.pp 

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
"main.pp" \
"vector_stream_int16.pp" \
"vector_stream_sp.pp" 

OBJS__QUOTED += \
"main.obj" \
"vector_stream_int16.obj" \
"vector_stream_sp.obj" 

CFG_SRCS__QUOTED += \
"../app.cfg" 

GEN_OPTS__FLAG += \
--cmd_file="./configPkg/compiler.opt" 

GEN_CMDS__FLAG += \
-l"./configPkg/linker.cmd" 

C_SRCS__QUOTED += \
"../main.c" \
"../vector_stream_int16.c" \
"../vector_stream_sp.c" 


