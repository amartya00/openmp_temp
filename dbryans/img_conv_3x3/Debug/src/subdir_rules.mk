################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/edma.obj: ../src/edma.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/ti/include" --include_path="/opt/ti/xdctools_3_23_03_53/packages" --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="src/edma.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/main.obj: ../src/main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/ti/include" --include_path="/opt/ti/xdctools_3_23_03_53/packages" --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="src/main.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/test.obj: ../src/test.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/ti/include" --include_path="/opt/ti/xdctools_3_23_03_53/packages" --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="src/test.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


