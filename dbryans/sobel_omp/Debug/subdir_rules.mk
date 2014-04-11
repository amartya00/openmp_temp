################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
configPkg/compiler.opt: ../sobelOmp.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"C:/ti/xdctools_3_23_04_60/xs" --xdcpath="C:/ti/omp_1_01_03_02/packages;C:/ti/bios_6_33_06_50/packages;C:/ti/ipc_1_24_03_32/packages;C:/ti/pdk_C6678_1_1_2_6/packages;C:/ti/edma3_lld_02_11_05_02/packages;C:/ti/imglib_c66x_3_1_1_0/packages;/media/work/F5/TMS320C6678-Benchmarks/c6678_benchmarks/platforms;C:/ti_5_3/ccsv5/ccs_base;" xdc.tools.configuro -o configPkg -t ti.targets.elf.C66 -p myBoardOMP -r debug -c "C:/ti_5_3/compiler" "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: configPkg/compiler.opt
configPkg/: configPkg/compiler.opt


