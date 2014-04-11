################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/xhemm/chemmC66SC.obj: C:/ti/delivered/blasLevel3/src/singleCore/xhemm/chemmC66SC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/include" --include_path="C:/ti/delivered/blasLevel3/lib/C66/blas3libSCOmp/../../../inc" --display_error_number --diag_warning=225 --openmp --preproc_with_compile --preproc_dependency="src/xhemm/chemmC66SC.pp" --obj_directory="src/xhemm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/xhemm/zhemmC66SC.obj: C:/ti/delivered/blasLevel3/src/singleCore/xhemm/zhemmC66SC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/include" --include_path="C:/ti/delivered/blasLevel3/lib/C66/blas3libSCOmp/../../../inc" --display_error_number --diag_warning=225 --openmp --preproc_with_compile --preproc_dependency="src/xhemm/zhemmC66SC.pp" --obj_directory="src/xhemm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


