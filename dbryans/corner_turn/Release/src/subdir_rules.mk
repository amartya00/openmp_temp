################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/corner_turn.obj: ../src/corner_turn.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/C6000CGT7.4.2/bin/cl6x" -mv6600 --abi=eabi -O3 --include_path="/opt/ti/C6000CGT7.4.2/include" --display_error_number --diag_warning=225 --diag_wrap=off --openmp --preproc_with_compile --preproc_dependency="src/corner_turn.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


