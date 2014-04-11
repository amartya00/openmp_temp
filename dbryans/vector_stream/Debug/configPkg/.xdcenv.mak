#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /opt/ti/dsplib_c66x_3_1_0_0/packages;/opt/ti/edma3_lld_02_11_05_02/packages;/opt/ti/grace_1_10_04_36/packages;/opt/ti/imglib_c66x_3_1_1_0/packages;/opt/ti/ipc_1_24_03_32/packages;/opt/ti/mathlib_c66x_3_0_1_1/packages;/opt/ti/mcsdk_2_01_02_06/demos;/opt/ti/pdk_C6657_1_1_2_6/packages;/opt/ti/pdk_C6670_1_1_2_6/packages;/opt/ti/pdk_C6678_1_1_2_6/packages;/opt/ti/ndk_2_21_01_38/packages;/opt/ti/omp_1_01_03_02/packages;/opt/ti/bios_6_33_05_46/packages;/opt/ti/uia_1_01_00_04/packages;/opt/ti/xdais_7_21_01_07/packages;/opt/ti/xdais_7_21_01_07/examples;/opt/ti/ccsv5/ccs_base;/media/work__/F5/TMS320C6678-Benchmarks/benchmarks/platform_repo
override XDCROOT = /opt/ti/xdctools_3_23_03_53
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /opt/ti/dsplib_c66x_3_1_0_0/packages;/opt/ti/edma3_lld_02_11_05_02/packages;/opt/ti/grace_1_10_04_36/packages;/opt/ti/imglib_c66x_3_1_1_0/packages;/opt/ti/ipc_1_24_03_32/packages;/opt/ti/mathlib_c66x_3_0_1_1/packages;/opt/ti/mcsdk_2_01_02_06/demos;/opt/ti/pdk_C6657_1_1_2_6/packages;/opt/ti/pdk_C6670_1_1_2_6/packages;/opt/ti/pdk_C6678_1_1_2_6/packages;/opt/ti/ndk_2_21_01_38/packages;/opt/ti/omp_1_01_03_02/packages;/opt/ti/bios_6_33_05_46/packages;/opt/ti/uia_1_01_00_04/packages;/opt/ti/xdais_7_21_01_07/packages;/opt/ti/xdais_7_21_01_07/examples;/opt/ti/ccsv5/ccs_base;/media/work__/F5/TMS320C6678-Benchmarks/benchmarks/platform_repo;/opt/ti/xdctools_3_23_03_53/packages;..
HOSTOS = Linux
endif
