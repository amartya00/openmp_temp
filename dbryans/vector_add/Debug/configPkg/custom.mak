## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd \
  package/cfg/vector_add_pe66.oe66 \

linker.cmd: package/cfg/vector_add_pe66.xdl
	$(SED) 's"^\"\(package/cfg/vector_add_pe66cfg.cmd\)\"$""\"/home/barboza/Workspace/TI_C6678/vector_add/Debug/configPkg/\1\""' package/cfg/vector_add_pe66.xdl > $@
