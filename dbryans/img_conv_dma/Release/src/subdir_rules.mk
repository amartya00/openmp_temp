################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/edma.obj: ../src/edma.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/C6000CGT7.4.2/bin/cl6x" -mv6600 --abi=eabi -O3 --include_path="/opt/ti/C6000CGT7.4.2/include" --define=PARAMS --display_error_number --diag_warning=225 --diag_wrap=off --optimizer_interlist --openmp --preproc_with_compile --preproc_dependency="src/edma.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

src/img_conv.obj: ../src/img_conv.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/C6000CGT7.4.2/bin/cl6x" -mv6600 --abi=eabi -O3 --include_path="/opt/ti/C6000CGT7.4.2/include" --define=PARAMS --display_error_number --diag_warning=225 --diag_wrap=off --optimizer_interlist --openmp --preproc_with_compile --preproc_dependency="src/img_conv.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

src/img_pass_thru.obj: ../src/img_pass_thru.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/C6000CGT7.4.2/bin/cl6x" -mv6600 --abi=eabi -O3 --include_path="/opt/ti/C6000CGT7.4.2/include" --define=PARAMS --display_error_number --diag_warning=225 --diag_wrap=off --optimizer_interlist --openmp --preproc_with_compile --preproc_dependency="src/img_pass_thru.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

src/main.obj: ../src/main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/C6000CGT7.4.2/bin/cl6x" -mv6600 --abi=eabi -O3 --include_path="/opt/ti/C6000CGT7.4.2/include" --define=PARAMS --display_error_number --diag_warning=225 --diag_wrap=off --optimizer_interlist --openmp --preproc_with_compile --preproc_dependency="src/main.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


