################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
configPkg/compiler.opt: ../sobelOmp.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"C:/ti_5_3/xdctools_3_24_05_48/xs" --xdcpath="C:/ti/omp_1_02_00_05/packages;C:/ti_5_3/bios_6_34_02_18/packages;C:/ti/ipc_1_24_03_32/packages;C:/ti/pdk_C6678_1_1_2_6/packages;C:/ti/edma3_lld_02_11_05_02/packages;C:/ti/imglib_c66x_3_1_1_0/packages;C:/ti_5_3/ccsv5/ccs_base;C:/ti/mcsdk_2_01_02_06/demos;" xdc.tools.configuro -o configPkg -t ti.targets.elf.C66 -p ti.omp.examples.platforms.evm6678 -r release -c "C:/ti_5_3/compiler" "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: configPkg/compiler.opt
configPkg/: configPkg/compiler.opt


