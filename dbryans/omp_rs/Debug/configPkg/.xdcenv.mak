#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /opt/ti/omp_1_01_03_02/packages;/opt/ti/bios_6_34_02_18/packages;/opt/ti/ipc_1_25_00_04/packages;/opt/ti/pdk_C6678_1_1_2_6/packages;/opt/ti/ccsv5/ccs_base;/home/barboza/workspace/TEMP
override XDCROOT = /opt/ti/xdctools_3_24_05_48
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /opt/ti/omp_1_01_03_02/packages;/opt/ti/bios_6_34_02_18/packages;/opt/ti/ipc_1_25_00_04/packages;/opt/ti/pdk_C6678_1_1_2_6/packages;/opt/ti/ccsv5/ccs_base;/home/barboza/workspace/TEMP;/opt/ti/xdctools_3_24_05_48/packages;..
HOSTOS = Linux
endif
