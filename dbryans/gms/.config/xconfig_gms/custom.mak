## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd \
  package/cfg/gms_pe66.oe66 \

linker.cmd: package/cfg/gms_pe66.xdl
	$(SED) 's"^\"\(package/cfg/gms_pe66cfg.cmd\)\"$""\"/media/work__/F5/TMS320C6678-Benchmarks/benchmarks/gms/.config/xconfig_gms/\1\""' package/cfg/gms_pe66.xdl > $@
