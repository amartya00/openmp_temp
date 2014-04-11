#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/omp_1_01_02_06/packages;C:/ti/bios_6_33_05_46/packages;C:/ti/ipc_1_24_03_32/packages;C:/ti/pdk_C6678_1_1_0_3/packages;C:/ti/ccsv5/ccs_base;C:/ti/C6678/OMP_Matrix_mul/.config
override XDCROOT = C:/ti/xdctools_3_23_03_53
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/omp_1_01_02_06/packages;C:/ti/bios_6_33_05_46/packages;C:/ti/ipc_1_24_03_32/packages;C:/ti/pdk_C6678_1_1_0_3/packages;C:/ti/ccsv5/ccs_base;C:/ti/C6678/OMP_Matrix_mul/.config;C:/ti/xdctools_3_23_03_53/packages;..
HOSTOS = Windows
endif
