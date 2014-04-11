################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/xgemm/cgemmC66SC.obj: C:/ti/delivered/blasLevel3/src/singleCore/xgemm/cgemmC66SC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/bin/cl6x" -mv6600 --abi=eabi -O2 --include_path="C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/include" --include_path="C:/ti/delivered/blasLevel3/lib/C66/blas3libSCOmp/../../../inc" --define=DMA_COPYA --define=DMA_COPYB --display_error_number --diag_warning=225 --openmp --preproc_with_compile --preproc_dependency="src/xgemm/cgemmC66SC.pp" --obj_directory="src/xgemm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/xgemm/dgemmC66SC.obj: C:/ti/delivered/blasLevel3/src/singleCore/xgemm/dgemmC66SC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/bin/cl6x" -mv6600 --abi=eabi -O2 --include_path="C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/include" --include_path="C:/ti/delivered/blasLevel3/lib/C66/blas3libSCOmp/../../../inc" --define=DMA_COPYA --define=DMA_COPYB --display_error_number --diag_warning=225 --openmp --preproc_with_compile --preproc_dependency="src/xgemm/dgemmC66SC.pp" --obj_directory="src/xgemm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/xgemm/sgemmC66SC.obj: C:/ti/delivered/blasLevel3/src/singleCore/xgemm/sgemmC66SC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/bin/cl6x" -mv6600 --abi=eabi -O2 --include_path="C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/include" --include_path="C:/ti/delivered/blasLevel3/lib/C66/blas3libSCOmp/../../../inc" --define=DMA_COPYA --define=DMA_COPYB --display_error_number --diag_warning=225 --openmp --preproc_with_compile --preproc_dependency="src/xgemm/sgemmC66SC.pp" --obj_directory="src/xgemm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/xgemm/zgemmC66SC.obj: C:/ti/delivered/blasLevel3/src/singleCore/xgemm/zgemmC66SC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/bin/cl6x" -mv6600 --abi=eabi -O2 --include_path="C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/include" --include_path="C:/ti/delivered/blasLevel3/lib/C66/blas3libSCOmp/../../../inc" --define=DMA_COPYA --define=DMA_COPYB --display_error_number --diag_warning=225 --openmp --preproc_with_compile --preproc_dependency="src/xgemm/zgemmC66SC.pp" --obj_directory="src/xgemm" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


