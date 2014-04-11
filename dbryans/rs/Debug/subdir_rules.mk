################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
configPkg/compiler.opt: ../app.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"/opt/ti/xdctools_3_24_05_48/xs" --xdcpath="/opt/ti/bios_6_34_02_18/packages;/opt/ti/ccsv5/ccs_base;/home/barboza/workspace/RTSC;" xdc.tools.configuro -o configPkg -t ti.targets.elf.C66 -p BASIC_C6678_DDR3 -r release -c "/opt/ti/C6000CGT7.4.0" --compileOptions "-g --optimize_with_debug" "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: configPkg/compiler.opt
configPkg/: configPkg/compiler.opt

rs.obj: ../rs.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/C6000CGT7.4.0/bin/cl6x" -mv6600 --abi=eabi -g --include_path="/opt/ti/C6000CGT7.4.0/include" --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="rs.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


