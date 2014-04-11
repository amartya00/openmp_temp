## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e66 linker.cmd package/cfg/app_pe66.oe66

linker.cmd: package/cfg/app_pe66.xdl
	$(SED) 's"^\"\(package/cfg/app_pe66cfg.cmd\)\"$""\"C:/Users/Dorian/workspace_v5_4/vector/Debug/configPkg/\1\""' package/cfg/app_pe66.xdl > $@
