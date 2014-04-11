## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd \
  package/cfg/omp_config_pe66.oe66 \

linker.cmd: package/cfg/omp_config_pe66.xdl
	$(SED) 's"^\"\(package/cfg/omp_config_pe66cfg.cmd\)\"$""\"A:/F5/TMS320C6678-Benchmarks/c6678_benchmarks/hello_world_omp/.config/xconfig_omp_config/\1\""' package/cfg/omp_config_pe66.xdl > $@
