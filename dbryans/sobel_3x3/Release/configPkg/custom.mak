## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd \
  package/cfg/sobel_pe66.oe66 \

linker.cmd: package/cfg/sobel_pe66.xdl
	$(SED) 's"^\"\(package/cfg/sobel_pe66cfg.cmd\)\"$""\"/media/work/F5/TMS320C6678-Benchmarks/c6678_benchmarks/sobel_3x3/Release/configPkg/\1\""' package/cfg/sobel_pe66.xdl > $@
