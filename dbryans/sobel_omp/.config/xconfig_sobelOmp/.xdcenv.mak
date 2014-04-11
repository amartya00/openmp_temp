#
_XDCBUILDCOUNT = 0
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /opt/ti/omp_1_02_00_05/packages;/opt/ti/bios_6_34_02_18/packages;/opt/ti/ipc_1_24_03_32/packages;/opt/ti/pdk_C6678_1_1_2_6/packages;/opt/ti/edma3_lld_02_11_05_02/packages;/opt/ti/imglib_c66x_3_1_1_0/packages;/opt/ti/ccsv5/ccs_base;/opt/ti/mcsdk_2_01_02_06/demos;/media/work_/F5/TMS320C6678-Benchmarks/benchmarks/sobel_omp/.config
override XDCROOT = /opt/ti/xdctools_3_24_05_48
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /opt/ti/omp_1_02_00_05/packages;/opt/ti/bios_6_34_02_18/packages;/opt/ti/ipc_1_24_03_32/packages;/opt/ti/pdk_C6678_1_1_2_6/packages;/opt/ti/edma3_lld_02_11_05_02/packages;/opt/ti/imglib_c66x_3_1_1_0/packages;/opt/ti/ccsv5/ccs_base;/opt/ti/mcsdk_2_01_02_06/demos;/media/work_/F5/TMS320C6678-Benchmarks/benchmarks/sobel_omp/.config;/opt/ti/xdctools_3_24_05_48/packages;..
HOSTOS = Linux
endif
