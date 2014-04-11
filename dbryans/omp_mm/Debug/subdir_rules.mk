################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
configPkg/compiler.opt: ../omp_config.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"/opt/ti/xdctools_3_24_06_63/xs" --xdcpath="/opt/ti/omp_1_01_03_02/packages;/opt/ti/bios_6_34_02_18/packages;/opt/ti/ipc_1_25_00_04/packages;/opt/ti/pdk_C6678_1_1_2_6/packages;/opt/ti/ccsv5/ccs_base;/home/barboza/workspace/RTSC;" xdc.tools.configuro -o configPkg -t ti.targets.elf.C66 -p evmc6678Omp -r debug -c "/opt/ti/C6000CGT7.4.0" "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: configPkg/compiler.opt
configPkg/: configPkg/compiler.opt

omp_mm.obj: ../omp_mm.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/C6000CGT7.4.0/bin/cl6x" -mv6600 --abi=eabi -g --include_path="/opt/ti/C6000CGT7.4.0/include" --display_error_number --diag_warning=225 --openmp --preproc_with_compile --preproc_dependency="omp_mm.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


