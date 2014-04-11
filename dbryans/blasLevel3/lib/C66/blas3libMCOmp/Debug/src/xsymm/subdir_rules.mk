################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/xsymm/csymmC66MC.obj: C:/ti/delivered/blasLevel3/src/multiCore/xsymm/csymmC66MC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/include" --include_path="C:/ti/delivered/blasLevel3/lib/C66/blas3libMCOmp/../../../inc" --display_error_number --diag_warning=225 --openmp --preproc_with_compile --preproc_dependency="src/xsymm/csymmC66MC.pp" --obj_directory="src/xsymm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/xsymm/dsymmC66MC.obj: C:/ti/delivered/blasLevel3/src/multiCore/xsymm/dsymmC66MC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/include" --include_path="C:/ti/delivered/blasLevel3/lib/C66/blas3libMCOmp/../../../inc" --display_error_number --diag_warning=225 --openmp --preproc_with_compile --preproc_dependency="src/xsymm/dsymmC66MC.pp" --obj_directory="src/xsymm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/xsymm/ssymmC66MC.obj: C:/ti/delivered/blasLevel3/src/multiCore/xsymm/ssymmC66MC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/include" --include_path="C:/ti/delivered/blasLevel3/lib/C66/blas3libMCOmp/../../../inc" --display_error_number --diag_warning=225 --openmp --preproc_with_compile --preproc_dependency="src/xsymm/ssymmC66MC.pp" --obj_directory="src/xsymm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/xsymm/zsymmC66MC.obj: C:/ti/delivered/blasLevel3/src/multiCore/xsymm/zsymmC66MC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/include" --include_path="C:/ti/delivered/blasLevel3/lib/C66/blas3libMCOmp/../../../inc" --display_error_number --diag_warning=225 --openmp --preproc_with_compile --preproc_dependency="src/xsymm/zsymmC66MC.pp" --obj_directory="src/xsymm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


