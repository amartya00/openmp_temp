################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/MAD_32x32_OMP.obj: ../src/MAD_32x32_OMP.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/C6000CGT7.4.2/bin/cl6x" -mv6600 --abi=eabi -O2 --include_path="/opt/ti/C6000CGT7.4.2/include" --display_error_number --diag_warning=225 --diag_wrap=off --openmp --preproc_with_compile --preproc_dependency="src/MAD_32x32_OMP.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

src/MAD_8x8_OMP.obj: ../src/MAD_8x8_OMP.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/C6000CGT7.4.2/bin/cl6x" -mv6600 --abi=eabi -O2 --include_path="/opt/ti/C6000CGT7.4.2/include" --display_error_number --diag_warning=225 --diag_wrap=off --openmp --preproc_with_compile --preproc_dependency="src/MAD_8x8_OMP.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

src/SAD_32x32_OMP.obj: ../src/SAD_32x32_OMP.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/C6000CGT7.4.2/bin/cl6x" -mv6600 --abi=eabi -O2 --include_path="/opt/ti/C6000CGT7.4.2/include" --display_error_number --diag_warning=225 --diag_wrap=off --openmp --preproc_with_compile --preproc_dependency="src/SAD_32x32_OMP.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

src/SAD_8x8_OMP.obj: ../src/SAD_8x8_OMP.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/C6000CGT7.4.2/bin/cl6x" -mv6600 --abi=eabi -O2 --include_path="/opt/ti/C6000CGT7.4.2/include" --display_error_number --diag_warning=225 --diag_wrap=off --openmp --preproc_with_compile --preproc_dependency="src/SAD_8x8_OMP.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

src/omp_hello.obj: ../src/omp_hello.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/C6000CGT7.4.2/bin/cl6x" -mv6600 --abi=eabi -O2 --include_path="/opt/ti/C6000CGT7.4.2/include" --display_error_number --diag_warning=225 --diag_wrap=off --openmp --preproc_with_compile --preproc_dependency="src/omp_hello.pp" --obj_directory="src" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


