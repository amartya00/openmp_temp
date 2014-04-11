################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
configPkg/compiler.opt: ../app.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"/opt/ti/xdctools_3_23_04_60/xs" --xdcpath="/opt/ti/bios_6_33_05_46/packages;/opt/ti/edma3_lld_02_11_05_02/packages;/opt/ti/ccsv5/ccs_base;/media/work_/F5/TMS320C6678-Benchmarks/c6678_benchmarks/platform_repo;/media/work/F5/TMS320C6678-Benchmarks/c6678_benchmarks/platforms;" xdc.tools.configuro -o configPkg -t ti.targets.elf.C66 -p evmc6678Omp -r release -c "/opt/ti/C6000CGT7.4.0" --compileOptions "-g --optimize_with_debug" "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: configPkg/compiler.opt
configPkg/: configPkg/compiler.opt

test.obj: ../test.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/C6000CGT7.4.0/bin/cl6x" -mv6600 --abi=eabi -g --include_path="/opt/ti/C6000CGT7.4.0/include" --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="test.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


