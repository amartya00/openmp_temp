## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd \
  package/cfg/omp_config_pe66.oe66 \

linker.cmd: package/cfg/omp_config_pe66.xdl
	$(SED) 's"^\"\(package/cfg/omp_config_pe66cfg.cmd\)\"$""\"C:/ti/C6678/OMP_Matrix_mul/Debug/configPkg/\1\""' package/cfg/omp_config_pe66.xdl > $@
