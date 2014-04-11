#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /opt/ti/omp_1_02_00_05/packages;/opt/ti/bios_6_34_02_18/packages;/opt/ti/ipc_3_00_00_08/packages;/opt/ti/pdk_C6678_1_1_2_6/packages;/media/work_/F5/TMS320C6678-Benchmarks/benchmarks/platform_repo;/opt/ti/ccsv5/ccs_base
override XDCROOT = /opt/ti/xdctools_3_24_05_48
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /opt/ti/omp_1_02_00_05/packages;/opt/ti/bios_6_34_02_18/packages;/opt/ti/ipc_3_00_00_08/packages;/opt/ti/pdk_C6678_1_1_2_6/packages;/media/work_/F5/TMS320C6678-Benchmarks/benchmarks/platform_repo;/opt/ti/ccsv5/ccs_base;/opt/ti/xdctools_3_24_05_48/packages;..
HOSTOS = Linux
endif
