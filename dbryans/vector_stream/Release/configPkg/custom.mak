## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd \
  package/cfg/vector_stream_pe66.oe66 \

linker.cmd: package/cfg/vector_stream_pe66.xdl
	$(SED) 's"^\"\(package/cfg/vector_stream_pe66cfg.cmd\)\"$""\"A:/F5/TMS320C6678-Benchmarks/benchmarks/vector_stream/Release/configPkg/\1\""' package/cfg/vector_stream_pe66.xdl > $@
