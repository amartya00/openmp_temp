################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/common.obj: ../src/common.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/ti/include" --include_path="/opt/ti/edma3_lld_02_11_05_02/packages" --include_path="/opt/ti/bios_6_33_05_46/packages" --include_path="/opt/ti/xdctools_3_23_02_47/packages/" --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="src/common.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/main.obj: ../src/main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/ti/include" --include_path="/opt/ti/edma3_lld_02_11_05_02/packages" --include_path="/opt/ti/bios_6_33_05_46/packages" --include_path="/opt/ti/xdctools_3_23_02_47/packages/" --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="src/main.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/qdma_test.obj: ../src/qdma_test.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/ti/include" --include_path="/opt/ti/edma3_lld_02_11_05_02/packages" --include_path="/opt/ti/bios_6_33_05_46/packages" --include_path="/opt/ti/xdctools_3_23_02_47/packages/" --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="src/qdma_test.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


