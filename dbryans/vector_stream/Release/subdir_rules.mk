################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
configPkg/compiler.opt: ../vector_stream.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"C:/ti/xdctools_3_23_03_53/xs" --xdcpath="C:/ti/dsplib_c66x_3_1_0_0/packages;C:/ti/edma3_lld_02_11_05_02/packages;C:/ti/grace_1_10_04_36/packages;C:/ti/imglib_c66x_3_1_0_1/packages;C:/ti/ipc_1_24_03_32/packages;C:/ti/mathlib_c66x_3_0_1_1/packages;C:/ti/mcsdk_2_01_00_02/demos;C:/ti/pdk_C6657_1_1_0_2/packages;C:/ti/pdk_C6670_1_1_0_2/packages;C:/ti/pdk_C6678_1_1_0_2/packages;C:/ti/ndk_2_21_00_32/packages;C:/ti/omp_1_01_02_03_beta/packages;C:/ti/bios_6_33_05_46/packages;C:/ti/uia_1_01_00_04/packages;C:/ti/xdais_7_21_01_07/packages;C:/ti/xdais_7_21_01_07/examples;C:/ti/ccsv5/ccs_base;/media/work__/F5/TMS320C6678-Benchmarks/benchmarks/platform_repo/;A:/F5/TMS320C6678-Benchmarks/benchmarks/platform_repo;" xdc.tools.configuro -o configPkg -t ti.targets.elf.C66 -p evmc6678sc -r release -c "C:/ti" "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: configPkg/compiler.opt
configPkg/: configPkg/compiler.opt


