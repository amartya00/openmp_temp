################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/edma.obj: ../src/edma.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/C6000CGT7.4.0/bin/cl6x" -mv6600 --abi=eabi -g --include_path="/opt/ti/C6000CGT7.4.0/include" --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="src/edma.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

src/edma_check.obj: ../src/edma_check.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/C6000CGT7.4.0/bin/cl6x" -mv6600 --abi=eabi -g --include_path="/opt/ti/C6000CGT7.4.0/include" --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="src/edma_check.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

src/main.obj: ../src/main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/C6000CGT7.4.0/bin/cl6x" -mv6600 --abi=eabi -g --include_path="/opt/ti/C6000CGT7.4.0/include" --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="src/main.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

