#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /opt/ti/bios_6_33_05_46/packages;/opt/ti/edma3_lld_02_11_05_02/packages;/opt/ti/ccsv5/ccs_base;/media/work_/F5/TMS320C6678-Benchmarks/c6678_benchmarks/platform_repo;/media/work/F5/TMS320C6678-Benchmarks/c6678_benchmarks/platforms
override XDCROOT = /opt/ti/xdctools_3_23_04_60
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /opt/ti/bios_6_33_05_46/packages;/opt/ti/edma3_lld_02_11_05_02/packages;/opt/ti/ccsv5/ccs_base;/media/work_/F5/TMS320C6678-Benchmarks/c6678_benchmarks/platform_repo;/media/work/F5/TMS320C6678-Benchmarks/c6678_benchmarks/platforms;/opt/ti/xdctools_3_23_04_60/packages;..
HOSTOS = Linux
endif
