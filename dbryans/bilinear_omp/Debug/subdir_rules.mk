################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
configPkg/compiler.opt: ../omp_config.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"C:/ti/xdctools_3_23_04_60/xs" --xdcpath="C:/ti/omp_1_02_00_05/packages;C:/ti/bios_6_33_06_50/packages;C:/ti/ipc_1_24_03_32/packages;C:/ti/pdk_C6678_1_1_2_6/packages;C:/ti/ccsv5/ccs_base;C:/ti/edma3_lld_02_11_05_02/packages;/media/work__/F5/TMS320C6678-Benchmarks/benchmarks/platform_repo;" xdc.tools.configuro -o configPkg -t ti.targets.elf.C66 -p evmc6678sc -r debug -c "C:/ti" "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: configPkg/compiler.opt
configPkg/: configPkg/compiler.opt


