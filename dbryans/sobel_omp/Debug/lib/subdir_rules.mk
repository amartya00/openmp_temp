################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
configPkg/compiler.opt: ../lib/sobelSc.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"/opt/ti/xdctools_3_23_04_60/xs" --xdcpath="/opt/ti/omp_1_01_03_02/packages;/opt/ti/bios_6_33_06_50/packages;/opt/ti/ipc_1_24_03_32/packages;/opt/ti/pdk_C6678_1_1_2_5/packages;/opt/ti/edma3_lld_02_11_05_02/packages;/opt/ti/imglib_c66x_3_1_1_0/packages;/media/work/F5/TMS320C6678-Benchmarks/c6678_benchmarks/platforms;/opt/ti/ccsv5/ccs_base;" xdc.tools.configuro -o configPkg -t ti.targets.elf.C66 -p myBoardOMP -r debug -c "/opt/ti/C6000CGT7.4.2" "$<"
	@echo 'Finished building: $<'
	@echo ' '

lib/configPkg/: configPkg/compiler.opt


