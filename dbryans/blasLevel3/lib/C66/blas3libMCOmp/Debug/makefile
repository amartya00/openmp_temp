################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2

ORDERED_OBJS += \
"./src/xgemm/zgemmC66MC.obj" \
"./src/xgemm/sgemmC66MC.obj" \
"./src/xgemm/dgemmC66MC.obj" \
"./src/xgemm/cgemmC66MC.obj" \
"./src/xhemm/zhemmC66MC.obj" \
"./src/xhemm/chemmC66MC.obj" \
"./src/xher2k/zher2kC66MC.obj" \
"./src/xher2k/cher2kC66MC.obj" \
"./src/xherk/zherkC66MC.obj" \
"./src/xherk/cherkC66MC.obj" \
"./src/xsymm/zsymmC66MC.obj" \
"./src/xsymm/ssymmC66MC.obj" \
"./src/xsymm/dsymmC66MC.obj" \
"./src/xsymm/csymmC66MC.obj" \
"./src/xsyr2k/zsyr2kC66MC.obj" \
"./src/xsyr2k/ssyr2kC66MC.obj" \
"./src/xsyr2k/dsyr2kC66MC.obj" \
"./src/xsyr2k/csyr2kC66MC.obj" \
"./src/xsyrk/zsyrkC66MC.obj" \
"./src/xsyrk/ssyrkC66MC.obj" \
"./src/xsyrk/dsyrkC66MC.obj" \
"./src/xsyrk/csyrkC66MC.obj" \
"./src/xtrmm/ztrmmC66MC.obj" \
"./src/xtrmm/strmmC66MC.obj" \
"./src/xtrmm/dtrmmC66MC.obj" \
"./src/xtrmm/ctrmmC66MC.obj" \
"./src/xtrsm/ztrsmC66MC.obj" \
"./src/xtrsm/strsmC66MC.obj" \
"./src/xtrsm/dtrsmC66MC.obj" \
"./src/xtrsm/ctrsmC66MC.obj" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include src/xtrsm/subdir_vars.mk
-include src/xtrmm/subdir_vars.mk
-include src/xsyrk/subdir_vars.mk
-include src/xsyr2k/subdir_vars.mk
-include src/xsymm/subdir_vars.mk
-include src/xherk/subdir_vars.mk
-include src/xher2k/subdir_vars.mk
-include src/xhemm/subdir_vars.mk
-include src/xgemm/subdir_vars.mk
-include subdir_rules.mk
-include src/xtrsm/subdir_rules.mk
-include src/xtrmm/subdir_rules.mk
-include src/xsyrk/subdir_rules.mk
-include src/xsyr2k/subdir_rules.mk
-include src/xsymm/subdir_rules.mk
-include src/xherk/subdir_rules.mk
-include src/xher2k/subdir_rules.mk
-include src/xhemm/subdir_rules.mk
-include src/xgemm/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: blas3libMCOmp.ae66

# Tool invocations
blas3libMCOmp.ae66: $(OBJS) $(OBJ_SRCS) $(CMD_SRCS)
	@echo 'Building target: $@'
	@echo 'Invoking: C6000 Archiver'
	"C:/Program Files (x86)/Texas Instruments/C6000 Code Generation Tools 7.4.0B2/bin/ar6x" r "blas3libMCOmp.ae66" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(GEN_SRCS__QUOTED)$(GEN_MISC_FILES__QUOTED)$(GEN_OPTS__QUOTED)$(GEN_CMDS__QUOTED)$(C6000_LIBRARY_OUTPUTS__QUOTED) "blas3libMCOmp.ae66"
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-$(RM) "src\xtrsm\ctrsmC66MC.pp" "src\xtrsm\dtrsmC66MC.pp" "src\xtrsm\strsmC66MC.pp" "src\xtrsm\ztrsmC66MC.pp" "src\xtrmm\ctrmmC66MC.pp" "src\xtrmm\dtrmmC66MC.pp" "src\xtrmm\strmmC66MC.pp" "src\xtrmm\ztrmmC66MC.pp" "src\xsyrk\csyrkC66MC.pp" "src\xsyrk\dsyrkC66MC.pp" "src\xsyrk\ssyrkC66MC.pp" "src\xsyrk\zsyrkC66MC.pp" "src\xsyr2k\csyr2kC66MC.pp" "src\xsyr2k\dsyr2kC66MC.pp" "src\xsyr2k\ssyr2kC66MC.pp" "src\xsyr2k\zsyr2kC66MC.pp" "src\xsymm\csymmC66MC.pp" "src\xsymm\dsymmC66MC.pp" "src\xsymm\ssymmC66MC.pp" "src\xsymm\zsymmC66MC.pp" "src\xherk\cherkC66MC.pp" "src\xherk\zherkC66MC.pp" "src\xher2k\cher2kC66MC.pp" "src\xher2k\zher2kC66MC.pp" "src\xhemm\chemmC66MC.pp" "src\xhemm\zhemmC66MC.pp" "src\xgemm\cgemmC66MC.pp" "src\xgemm\dgemmC66MC.pp" "src\xgemm\sgemmC66MC.pp" "src\xgemm\zgemmC66MC.pp" 
	-$(RM) "src\xtrsm\ctrsmC66MC.obj" "src\xtrsm\dtrsmC66MC.obj" "src\xtrsm\strsmC66MC.obj" "src\xtrsm\ztrsmC66MC.obj" "src\xtrmm\ctrmmC66MC.obj" "src\xtrmm\dtrmmC66MC.obj" "src\xtrmm\strmmC66MC.obj" "src\xtrmm\ztrmmC66MC.obj" "src\xsyrk\csyrkC66MC.obj" "src\xsyrk\dsyrkC66MC.obj" "src\xsyrk\ssyrkC66MC.obj" "src\xsyrk\zsyrkC66MC.obj" "src\xsyr2k\csyr2kC66MC.obj" "src\xsyr2k\dsyr2kC66MC.obj" "src\xsyr2k\ssyr2kC66MC.obj" "src\xsyr2k\zsyr2kC66MC.obj" "src\xsymm\csymmC66MC.obj" "src\xsymm\dsymmC66MC.obj" "src\xsymm\ssymmC66MC.obj" "src\xsymm\zsymmC66MC.obj" "src\xherk\cherkC66MC.obj" "src\xherk\zherkC66MC.obj" "src\xher2k\cher2kC66MC.obj" "src\xher2k\zher2kC66MC.obj" "src\xhemm\chemmC66MC.obj" "src\xhemm\zhemmC66MC.obj" "src\xgemm\cgemmC66MC.obj" "src\xgemm\dgemmC66MC.obj" "src\xgemm\sgemmC66MC.obj" "src\xgemm\zgemmC66MC.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
