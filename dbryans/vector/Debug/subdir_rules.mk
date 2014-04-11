################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
configPkg/compiler.opt: ../app.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"C:/ti/xdctools_3_23_04_60/xs" --xdcpath="C:/ti/bios_6_33_06_50/packages;C:/ti/ccsv5/ccs_base;" xdc.tools.configuro -o configPkg -t ti.targets.elf.C66 -p ti.platforms.evm6678 -r release -c "C:/ti" --compileOptions "-g --optimize_with_debug" "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: configPkg/compiler.opt
configPkg/: configPkg/compiler.opt

main.obj: ../main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/bin/cl6x" -mv6600 --abi=eabi -O3 -ms0 -g --optimize_with_debug=on --include_path="C:/ti/include" --display_error_number --diag_warning=225 --diag_wrap=off --debug_software_pipeline --advice:performance=all --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

vector_stream_int16.obj: ../vector_stream_int16.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/bin/cl6x" -mv6600 --abi=eabi -O3 -ms0 -g --optimize_with_debug=on --include_path="C:/ti/include" --display_error_number --diag_warning=225 --diag_wrap=off --debug_software_pipeline --advice:performance=all --preproc_with_compile --preproc_dependency="vector_stream_int16.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

vector_stream_sp.obj: ../vector_stream_sp.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"C:/ti/bin/cl6x" -mv6600 --abi=eabi -O3 -ms0 -g --optimize_with_debug=on --include_path="C:/ti/include" --display_error_number --diag_warning=225 --diag_wrap=off --debug_software_pipeline --advice:performance=all --preproc_with_compile --preproc_dependency="vector_stream_sp.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


