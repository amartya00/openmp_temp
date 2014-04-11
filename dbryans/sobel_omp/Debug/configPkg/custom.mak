## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd \
  package/cfg/sobelOmp_pe66.oe66 \

linker.cmd: package/cfg/sobelOmp_pe66.xdl
	$(SED) 's"^\"\(package/cfg/sobelOmp_pe66cfg.cmd\)\"$""\"/media/work/F5/TMS320C6678-Benchmarks/c6678_benchmarks/sobel_omp/Debug/configPkg/\1\""' package/cfg/sobelOmp_pe66.xdl > $@
