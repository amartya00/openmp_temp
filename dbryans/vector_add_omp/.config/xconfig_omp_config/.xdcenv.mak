#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/omp_1_01_02_03_beta/packages;C:/ti/bios_6_33_05_46/packages;C:/ti/ipc_1_24_03_32/packages;C:/ti/pdk_C6678_1_1_0_2/packages;C:/ti/ccsv5/ccs_base;A:/F5/TMS320C6678-Benchmarks/c6678_benchmarks/hello_world_omp/.config
override XDCROOT = C:/ti/xdctools_3_23_03_53
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/omp_1_01_02_03_beta/packages;C:/ti/bios_6_33_05_46/packages;C:/ti/ipc_1_24_03_32/packages;C:/ti/pdk_C6678_1_1_0_2/packages;C:/ti/ccsv5/ccs_base;A:/F5/TMS320C6678-Benchmarks/c6678_benchmarks/hello_world_omp/.config;C:/ti/xdctools_3_23_03_53/packages;..
HOSTOS = Windows
endif
