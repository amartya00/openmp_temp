################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
configPkg/compiler.opt: ../omp_config.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"C:/ti/xdctools_3_23_03_53/xs" --xdcpath="C:/ti/omp_1_01_02_06/packages;C:/ti/bios_6_33_05_46/packages;C:/ti/ipc_1_24_03_32/packages;C:/ti/pdk_C6678_1_1_0_3/packages;C:/ti/ccsv5/ccs_base;" xdc.tools.configuro -o configPkg -t ti.targets.elf.C66 -p ti.omp.examples.platforms.evm6678 -r debug -c "C:/ti" "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: configPkg/compiler.opt
configPkg/: configPkg/compiler.opt

omp_matvec.obj: ../omp_matvec.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/bin/cl6x" -mv6600 --abi=eabi -g --include_path="C:/ti/include" --display_error_number --diag_warning=225 --diag_wrap=off --openmp --preproc_with_compile --preproc_dependency="omp_matvec.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

