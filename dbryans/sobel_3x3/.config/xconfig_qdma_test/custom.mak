## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd \
  package/cfg/qdma_test_pe66.oe66 \

linker.cmd: package/cfg/qdma_test_pe66.xdl
	$(SED) 's"^\"\(package/cfg/qdma_test_pe66cfg.cmd\)\"$""\"/media/work/F5/TMS320C6678-Benchmarks/c6678_benchmarks/bilinear/.config/xconfig_qdma_test/\1\""' package/cfg/qdma_test_pe66.xdl > $@
