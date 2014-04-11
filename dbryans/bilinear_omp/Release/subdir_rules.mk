################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
configPkg/compiler.opt: ../omp_config.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"/opt/ti/xdctools_3_24_05_48/xs" --xdcpath="/opt/ti/bios_6_34_02_18/packages;/opt/ti/pdk_C6678_1_1_2_6/packages;/opt/ti/ccsv5/ccs_base;/opt/ti/mcsdk_2_01_02_06/demos;/media/work__/F5/TMS320C6678-Benchmarks/benchmarks/platform_repo;A:\F5\TMS320C6678-Benchmarks\benchmarks\platform_repo;/opt/ti/ipc_3_00_00_08/packages;" xdc.tools.configuro -o configPkg -t ti.targets.elf.C66 -p evmc6678sc -r release -c "/opt/ti/C6000CGT7.4.2" "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: configPkg/compiler.opt
configPkg/: configPkg/compiler.opt


