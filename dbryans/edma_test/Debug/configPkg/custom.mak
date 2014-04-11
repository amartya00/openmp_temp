## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd \
  package/cfg/app_pe66.oe66 \

linker.cmd: package/cfg/app_pe66.xdl
	$(SED) 's"^\"\(package/cfg/app_pe66cfg.cmd\)\"$""\"/media/work_/F5/TMS320C6678-Benchmarks/c6678_benchmarks/edma_test/Debug/configPkg/\1\""' package/cfg/app_pe66.xdl > $@
