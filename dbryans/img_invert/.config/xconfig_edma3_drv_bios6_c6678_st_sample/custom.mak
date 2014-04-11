## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd \
  package/cfg/edma3_drv_bios6_c6678_st_sample_pe66.oe66 \

linker.cmd: package/cfg/edma3_drv_bios6_c6678_st_sample_pe66.xdl
	$(SED) 's"^\"\(package/cfg/edma3_drv_bios6_c6678_st_sample_pe66cfg.cmd\)\"$""\"/media/work/F5/TMS320C6678-Benchmarks/c6678_benchmarks/bilinear/.config/xconfig_edma3_drv_bios6_c6678_st_sample/\1\""' package/cfg/edma3_drv_bios6_c6678_st_sample_pe66.xdl > $@
