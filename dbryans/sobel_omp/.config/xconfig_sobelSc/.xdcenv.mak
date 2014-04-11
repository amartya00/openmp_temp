#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /opt/ti/omp_1_01_03_02/packages;/opt/ti/bios_6_33_06_50/packages;/opt/ti/ipc_1_24_03_32/packages;/opt/ti/pdk_C6678_1_1_2_5/packages;/opt/ti/edma3_lld_02_11_05_02/packages;/opt/ti/imglib_c66x_3_1_1_0/packages;/media/work/F5/TMS320C6678-Benchmarks/c6678_benchmarks/platforms;/opt/ti/ccsv5/ccs_base;/media/work/F5/TMS320C6678-Benchmarks/c6678_benchmarks/sobel_omp/.config
override XDCROOT = /opt/ti/xdctools_3_23_04_60
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /opt/ti/omp_1_01_03_02/packages;/opt/ti/bios_6_33_06_50/packages;/opt/ti/ipc_1_24_03_32/packages;/opt/ti/pdk_C6678_1_1_2_5/packages;/opt/ti/edma3_lld_02_11_05_02/packages;/opt/ti/imglib_c66x_3_1_1_0/packages;/media/work/F5/TMS320C6678-Benchmarks/c6678_benchmarks/platforms;/opt/ti/ccsv5/ccs_base;/media/work/F5/TMS320C6678-Benchmarks/c6678_benchmarks/sobel_omp/.config;/opt/ti/xdctools_3_23_04_60/packages;..
HOSTOS = Linux
endif
