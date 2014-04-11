#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/dsplib_c66x_3_1_1_0/packages;C:/ti/pdk_C6678_1_1_0_2/packages;C:/ti/omp_1_01_02_03_beta/packages;C:/ti/bios_6_33_04_39/packages;C:/ti/ccsv5/ccs_base
override XDCROOT = C:/ti/xdctools_3_23_03_53
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/dsplib_c66x_3_1_1_0/packages;C:/ti/pdk_C6678_1_1_0_2/packages;C:/ti/omp_1_01_02_03_beta/packages;C:/ti/bios_6_33_04_39/packages;C:/ti/ccsv5/ccs_base;C:/ti/xdctools_3_23_03_53/packages;..
HOSTOS = Windows
endif
