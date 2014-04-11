#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /opt/ti/omp_1_01_03_02/packages;/opt/ti/bios_6_33_05_46/packages;/opt/ti/ipc_1_24_03_32/packages;/opt/ti/pdk_C6678_1_1_2_5/packages;/opt/ti/ccsv5/ccs_base
override XDCROOT = /opt/ti/xdctools_3_23_03_53
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /opt/ti/omp_1_01_03_02/packages;/opt/ti/bios_6_33_05_46/packages;/opt/ti/ipc_1_24_03_32/packages;/opt/ti/pdk_C6678_1_1_2_5/packages;/opt/ti/ccsv5/ccs_base;/opt/ti/xdctools_3_23_03_53/packages;..
HOSTOS = Linux
endif
