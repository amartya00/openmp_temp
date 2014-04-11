################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
configPkg/compiler.opt: ../blas3libSC.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"C:/ti/xdctools_3_23_03_53/xs" --xdcpath="C:/ti/pdk_C6678_1_1_0_2/packages;C:/ti/bios_6_33_04_39/packages;C:/ti/edma3_lld_02_11_05_02/packages;C:/ti/omp_1_01_02_03_beta/packages;C:/ti/ccsv5/ccs_base;" xdc.tools.configuro -o configPkg -t ti.targets.elf.C66 -p ti.omp.examples.platforms.evm6678 -r release -c "C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2" "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: configPkg/compiler.opt
configPkg/: configPkg/compiler.opt


