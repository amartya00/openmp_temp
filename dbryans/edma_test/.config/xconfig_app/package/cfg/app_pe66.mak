#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#
#  target compatibility key = ti.targets.elf.C66{1,0,7.4,2
#
ifeq (,$(MK_NOGENDEPS))
-include package/cfg/app_pe66.oe66.dep
endif

package/cfg/app_pe66.oe66: | .interfaces
package/cfg/app_pe66.oe66: package/cfg/app_pe66.c package/cfg/app_pe66.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66 $< ...
	$(ti.targets.elf.C66.rootDir)/bin/cl6x -c  -g --optimize_with_debug -qq -pdsw225 -mo -mv6600 --abi=eabi -eo.oe66 -ea.se66  --embed_inline_assembly  -Dxdc_cfg__header__='xconfig_app/package/cfg/app_pe66.h'  -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_4_2 -O2  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/cfg -fr=./package/cfg -fc $<
	$(MKDEP) -a $@.dep -p package/cfg -s oe66 $< -C   -g --optimize_with_debug -qq -pdsw225 -mo -mv6600 --abi=eabi -eo.oe66 -ea.se66  --embed_inline_assembly  -Dxdc_cfg__header__='xconfig_app/package/cfg/app_pe66.h'  -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_4_2 -O2  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/cfg -fr=./package/cfg
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/app_pe66.oe66: export C_DIR=
package/cfg/app_pe66.oe66: PATH:=$(ti.targets.elf.C66.rootDir)/bin/:$(PATH)

package/cfg/app_pe66.se66: | .interfaces
package/cfg/app_pe66.se66: package/cfg/app_pe66.c package/cfg/app_pe66.mak
	@$(RM) $@.dep
	$(RM) $@
	@$(MSG) cle66 -n $< ...
	$(ti.targets.elf.C66.rootDir)/bin/cl6x -c -n -s --symdebug:none -g --optimize_with_debug -qq -pdsw225 -mv6600 --abi=eabi -eo.oe66 -ea.se66   -Dxdc_cfg__header__='xconfig_app/package/cfg/app_pe66.h'  -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_4_2 -O2  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/cfg -fr=./package/cfg -fc $<
	$(MKDEP) -a $@.dep -p package/cfg -s oe66 $< -C  -n -s --symdebug:none -g --optimize_with_debug -qq -pdsw225 -mv6600 --abi=eabi -eo.oe66 -ea.se66   -Dxdc_cfg__header__='xconfig_app/package/cfg/app_pe66.h'  -Dxdc_target_name__=C66 -Dxdc_target_types__=ti/targets/elf/std.h -Dxdc_bld__profile_release -Dxdc_bld__vers_1_0_7_4_2 -O2  $(XDCINCS) -I$(ti.targets.elf.C66.rootDir)/include -fs=./package/cfg -fr=./package/cfg
	-@$(FIXDEP) $@.dep $@.dep
	
package/cfg/app_pe66.se66: export C_DIR=
package/cfg/app_pe66.se66: PATH:=$(ti.targets.elf.C66.rootDir)/bin/:$(PATH)

clean,e66 ::
	-$(RM) package/cfg/app_pe66.oe66
	-$(RM) package/cfg/app_pe66.se66

app.pe66: package/cfg/app_pe66.oe66 package/cfg/app_pe66.mak

clean::
	-$(RM) package/cfg/app_pe66.mak
