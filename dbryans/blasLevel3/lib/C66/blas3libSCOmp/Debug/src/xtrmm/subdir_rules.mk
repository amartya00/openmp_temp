################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/xtrmm/ctrmmC66SC.obj: C:/ti/delivered/blasLevel3/src/singleCore/xtrmm/ctrmmC66SC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/include" --include_path="C:/ti/delivered/blasLevel3/lib/C66/blas3libSCOmp/../../../inc" --display_error_number --diag_warning=225 --openmp --preproc_with_compile --preproc_dependency="src/xtrmm/ctrmmC66SC.pp" --obj_directory="src/xtrmm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/xtrmm/dtrmmC66SC.obj: C:/ti/delivered/blasLevel3/src/singleCore/xtrmm/dtrmmC66SC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/include" --include_path="C:/ti/delivered/blasLevel3/lib/C66/blas3libSCOmp/../../../inc" --display_error_number --diag_warning=225 --openmp --preproc_with_compile --preproc_dependency="src/xtrmm/dtrmmC66SC.pp" --obj_directory="src/xtrmm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/xtrmm/strmmC66SC.obj: C:/ti/delivered/blasLevel3/src/singleCore/xtrmm/strmmC66SC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/include" --include_path="C:/ti/delivered/blasLevel3/lib/C66/blas3libSCOmp/../../../inc" --display_error_number --diag_warning=225 --openmp --preproc_with_compile --preproc_dependency="src/xtrmm/strmmC66SC.pp" --obj_directory="src/xtrmm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/xtrmm/ztrmmC66SC.obj: C:/ti/delivered/blasLevel3/src/singleCore/xtrmm/ztrmmC66SC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/include" --include_path="C:/ti/delivered/blasLevel3/lib/C66/blas3libSCOmp/../../../inc" --display_error_number --diag_warning=225 --openmp --preproc_with_compile --preproc_dependency="src/xtrmm/ztrmmC66SC.pp" --obj_directory="src/xtrmm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


