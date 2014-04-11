## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd \
  package/cfg/omp_config_pe66.oe66 \

linker.cmd: package/cfg/omp_config_pe66.xdl
	$(SED) 's"^\"\(package/cfg/omp_config_pe66cfg.cmd\)\"$""\"/media/work_/F5/TMS320C6678-Benchmarks/benchmarks/DWT/Debug/configPkg/\1\""' package/cfg/omp_config_pe66.xdl > $@
