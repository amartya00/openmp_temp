## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd \
  package/cfg/img_invert_pe66.oe66 \

linker.cmd: package/cfg/img_invert_pe66.xdl
	$(SED) 's"^\"\(package/cfg/img_invert_pe66cfg.cmd\)\"$""\"/media/work/F5/TMS320C6678-Benchmarks/c6678_benchmarks/img_invert/Release/configPkg/\1\""' package/cfg/img_invert_pe66.xdl > $@