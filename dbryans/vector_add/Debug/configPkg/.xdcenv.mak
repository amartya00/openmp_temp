#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /opt/ti/bios_6_34_02_18/packages;/opt/ti/ccsv5/ccs_base
override XDCROOT = /opt/ti/xdctools_3_24_05_48
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /opt/ti/bios_6_34_02_18/packages;/opt/ti/ccsv5/ccs_base;/opt/ti/xdctools_3_24_05_48/packages;..
HOSTOS = Linux
endif
