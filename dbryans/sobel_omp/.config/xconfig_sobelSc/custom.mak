## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd \
  package/cfg/sobelSc_pe66.oe66 \

linker.cmd: package/cfg/sobelSc_pe66.xdl
	$(SED) 's"^\"\(package/cfg/sobelSc_pe66cfg.cmd\)\"$""\"/media/work/F5/TMS320C6678-Benchmarks/c6678_benchmarks/sobel_omp/.config/xconfig_sobelSc/\1\""' package/cfg/sobelSc_pe66.xdl > $@
