## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd \
  package/cfg/blas3libSC_pe66.oe66 \

linker.cmd: package/cfg/blas3libSC_pe66.xdl
	$(SED) 's"^\"\(package/cfg/blas3libSC_pe66cfg.cmd\)\"$""\"C:/ti/delivered/blasLevel3/lib/C66/blas3libSCOmp/Release/configPkg/\1\""' package/cfg/blas3libSC_pe66.xdl > $@
