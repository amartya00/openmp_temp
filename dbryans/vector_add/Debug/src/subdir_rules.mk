################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/main.obj: ../src/main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/C6000CGT7.4.2/bin/cl6x" -mv6600 --abi=eabi -g --include_path="/opt/ti/C6000CGT7.4.2/include" --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="src/main.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

src/vector_add.obj: ../src/vector_add.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/C6000CGT7.4.2/bin/cl6x" -mv6600 --abi=eabi -g --include_path="/opt/ti/C6000CGT7.4.2/include" --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="src/vector_add.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


