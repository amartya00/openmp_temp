#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/dsplib_c66x_3_1_0_0/packages;C:/ti/edma3_lld_02_11_05_02/packages;C:/ti/grace_1_10_04_36/packages;C:/ti/imglib_c66x_3_1_0_1/packages;C:/ti/ipc_1_24_03_32/packages;C:/ti/mathlib_c66x_3_0_1_1/packages;C:/ti/mcsdk_2_01_00_02/demos;C:/ti/pdk_C6657_1_1_0_2/packages;C:/ti/pdk_C6670_1_1_0_2/packages;C:/ti/pdk_C6678_1_1_0_2/packages;C:/ti/ndk_2_21_00_32/packages;C:/ti/omp_1_01_02_03_beta/packages;C:/ti/bios_6_33_05_46/packages;C:/ti/uia_1_01_00_04/packages;C:/ti/xdais_7_21_01_07/packages;C:/ti/xdais_7_21_01_07/examples;C:/ti/ccsv5/ccs_base;C:/c6678_benchmark/qdma_test/.config
override XDCROOT = C:/ti/xdctools_3_23_03_53
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/dsplib_c66x_3_1_0_0/packages;C:/ti/edma3_lld_02_11_05_02/packages;C:/ti/grace_1_10_04_36/packages;C:/ti/imglib_c66x_3_1_0_1/packages;C:/ti/ipc_1_24_03_32/packages;C:/ti/mathlib_c66x_3_0_1_1/packages;C:/ti/mcsdk_2_01_00_02/demos;C:/ti/pdk_C6657_1_1_0_2/packages;C:/ti/pdk_C6670_1_1_0_2/packages;C:/ti/pdk_C6678_1_1_0_2/packages;C:/ti/ndk_2_21_00_32/packages;C:/ti/omp_1_01_02_03_beta/packages;C:/ti/bios_6_33_05_46/packages;C:/ti/uia_1_01_00_04/packages;C:/ti/xdais_7_21_01_07/packages;C:/ti/xdais_7_21_01_07/examples;C:/ti/ccsv5/ccs_base;C:/c6678_benchmark/qdma_test/.config;C:/ti/xdctools_3_23_03_53/packages;..
HOSTOS = Windows
endif
