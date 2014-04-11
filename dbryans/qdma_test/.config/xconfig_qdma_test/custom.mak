## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd \
  package/cfg/qdma_test_pe66.oe66 \

linker.cmd: package/cfg/qdma_test_pe66.xdl
	$(SED) 's"^\"\(package/cfg/qdma_test_pe66cfg.cmd\)\"$""\"C:/c6678_benchmark/qdma_test/.config/xconfig_qdma_test/\1\""' package/cfg/qdma_test_pe66.xdl > $@
