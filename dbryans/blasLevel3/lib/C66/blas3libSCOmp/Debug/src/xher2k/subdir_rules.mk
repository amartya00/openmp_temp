################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/xher2k/cher2kC66SC.obj: C:/ti/delivered/blasLevel3/src/singleCore/xher2k/cher2kC66SC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/include" --include_path="C:/ti/delivered/blasLevel3/lib/C66/blas3libSCOmp/../../../inc" --display_error_number --diag_warning=225 --openmp --preproc_with_compile --preproc_dependency="src/xher2k/cher2kC66SC.pp" --obj_directory="src/xher2k" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/xher2k/zher2kC66SC.obj: C:/ti/delivered/blasLevel3/src/singleCore/xher2k/zher2kC66SC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/include" --include_path="C:/ti/delivered/blasLevel3/lib/C66/blas3libSCOmp/../../../inc" --display_error_number --diag_warning=225 --openmp --preproc_with_compile --preproc_dependency="src/xher2k/zher2kC66SC.pp" --obj_directory="src/xher2k" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


