#
_XDCBUILDCOUNT = 0
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /opt/ti/bios_6_33_06_50/packages;/opt/ti/edma3_lld_02_11_05_02/packages;/opt/ti/ccsv5/ccs_base;/media/work_/F5/TMS320C6678-Benchmarks/c6678_benchmarks/platform_repo;/opt/ti/omp_1_01_03_02/packages;/opt/ti/ipc_1_24_03_32/packages;/opt/ti/pdk_C6678_1_1_2_5/packages;/opt/ti/mcsdk_2_01_02_05/demos;/media/work_/F5/TMS320C6678-Benchmarks/benchmarks/edma_test/.config
override XDCROOT = /opt/ti/xdctools_3_23_04_60
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /opt/ti/bios_6_33_06_50/packages;/opt/ti/edma3_lld_02_11_05_02/packages;/opt/ti/ccsv5/ccs_base;/media/work_/F5/TMS320C6678-Benchmarks/c6678_benchmarks/platform_repo;/opt/ti/omp_1_01_03_02/packages;/opt/ti/ipc_1_24_03_32/packages;/opt/ti/pdk_C6678_1_1_2_5/packages;/opt/ti/mcsdk_2_01_02_05/demos;/media/work_/F5/TMS320C6678-Benchmarks/benchmarks/edma_test/.config;/opt/ti/xdctools_3_23_04_60/packages;..
HOSTOS = Linux
endif
