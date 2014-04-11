## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd \
  package/cfg/img_conv_dma_pe66.oe66 \

linker.cmd: package/cfg/img_conv_dma_pe66.xdl
	$(SED) 's"^\"\(package/cfg/img_conv_dma_pe66cfg.cmd\)\"$""\"/media/work__/F5/TMS320C6678-Benchmarks/benchmarks/img_conv_dma/Release/configPkg/\1\""' package/cfg/img_conv_dma_pe66.xdl > $@
