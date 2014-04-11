################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/xtrsm/ctrsmC66MC.obj: C:/ti/delivered/blasLevel3/src/multiCore/xtrsm/ctrsmC66MC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/include" --include_path="C:/ti/delivered/blasLevel3/lib/C66/blas3libMCOmp/../../../inc" --display_error_number --diag_warning=225 --openmp --preproc_with_compile --preproc_dependency="src/xtrsm/ctrsmC66MC.pp" --obj_directory="src/xtrsm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/xtrsm/dtrsmC66MC.obj: C:/ti/delivered/blasLevel3/src/multiCore/xtrsm/dtrsmC66MC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/include" --include_path="C:/ti/delivered/blasLevel3/lib/C66/blas3libMCOmp/../../../inc" --display_error_number --diag_warning=225 --openmp --preproc_with_compile --preproc_dependency="src/xtrsm/dtrsmC66MC.pp" --obj_directory="src/xtrsm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/xtrsm/strsmC66MC.obj: C:/ti/delivered/blasLevel3/src/multiCore/xtrsm/strsmC66MC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/include" --include_path="C:/ti/delivered/blasLevel3/lib/C66/blas3libMCOmp/../../../inc" --display_error_number --diag_warning=225 --openmp --preproc_with_compile --preproc_dependency="src/xtrsm/strsmC66MC.pp" --obj_directory="src/xtrsm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/xtrsm/ztrsmC66MC.obj: C:/ti/delivered/blasLevel3/src/multiCore/xtrsm/ztrsmC66MC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/include" --include_path="C:/ti/delivered/blasLevel3/lib/C66/blas3libMCOmp/../../../inc" --display_error_number --diag_warning=225 --openmp --preproc_with_compile --preproc_dependency="src/xtrsm/ztrsmC66MC.pp" --obj_directory="src/xtrsm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


