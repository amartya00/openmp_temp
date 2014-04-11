#
#  Do not edit this file.  This file is generated from 
#  package.bld.  Any modifications to this file will be 
#  overwritten whenever makefiles are re-generated.
#

unexport MAKEFILE_LIST
MK_NOGENDEPS := $(filter clean,$(MAKECMDGOALS))
override PKGDIR = evmc6678Omp
XDCINCS = -I. -I$(strip $(subst ;, -I,$(subst $(space),\$(space),$(XPKGPATH))))
XDCCFGDIR = package/cfg/

#
# The following dependencies ensure package.mak is rebuilt
# in the event that some included BOM script changes.
#
ifneq (clean,$(MAKECMDGOALS))
/opt/ti/xdctools_3_24_05_48/include/utils.tci:
package.mak: /opt/ti/xdctools_3_24_05_48/include/utils.tci
/opt/ti/xdctools_3_24_05_48/packages/xdc/xdc.tci:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/xdc.tci
/opt/ti/xdctools_3_24_05_48/packages/xdc/template.xs:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/template.xs
/opt/ti/xdctools_3_24_05_48/packages/xdc/om2.xs:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/om2.xs
/opt/ti/xdctools_3_24_05_48/packages/xdc/xmlgen.xs:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/xmlgen.xs
/opt/ti/xdctools_3_24_05_48/packages/xdc/xmlgen2.xs:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/xmlgen2.xs
/opt/ti/xdctools_3_24_05_48/packages/xdc/IPackage.xs:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/IPackage.xs
/opt/ti/xdctools_3_24_05_48/packages/xdc/package.xs:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/package.xs
/opt/ti/xdctools_3_24_05_48/packages/xdc/services/global/Clock.xs:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/services/global/Clock.xs
/opt/ti/xdctools_3_24_05_48/packages/xdc/services/global/Trace.xs:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/services/global/Trace.xs
/opt/ti/xdctools_3_24_05_48/packages/xdc/bld/bld.js:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/bld/bld.js
/opt/ti/xdctools_3_24_05_48/packages/xdc/bld/BuildEnvironment.xs:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/bld/BuildEnvironment.xs
/opt/ti/xdctools_3_24_05_48/packages/xdc/bld/PackageContents.xs:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/bld/PackageContents.xs
/opt/ti/xdctools_3_24_05_48/packages/xdc/bld/_gen.xs:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/bld/_gen.xs
/opt/ti/xdctools_3_24_05_48/packages/xdc/bld/Library.xs:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/bld/Library.xs
/opt/ti/xdctools_3_24_05_48/packages/xdc/bld/Executable.xs:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/bld/Executable.xs
/opt/ti/xdctools_3_24_05_48/packages/xdc/bld/Repository.xs:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/bld/Repository.xs
/opt/ti/xdctools_3_24_05_48/packages/xdc/bld/Configuration.xs:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/bld/Configuration.xs
/opt/ti/xdctools_3_24_05_48/packages/xdc/bld/Script.xs:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/bld/Script.xs
/opt/ti/xdctools_3_24_05_48/packages/xdc/bld/Manifest.xs:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/bld/Manifest.xs
/opt/ti/xdctools_3_24_05_48/packages/xdc/bld/Utils.xs:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/bld/Utils.xs
/opt/ti/xdctools_3_24_05_48/packages/xdc/bld/ITarget.xs:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/bld/ITarget.xs
/opt/ti/xdctools_3_24_05_48/packages/xdc/bld/ITarget2.xs:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/bld/ITarget2.xs
/opt/ti/xdctools_3_24_05_48/packages/xdc/bld/ITargetFilter.xs:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/bld/ITargetFilter.xs
/opt/ti/xdctools_3_24_05_48/packages/xdc/bld/package.xs:
package.mak: /opt/ti/xdctools_3_24_05_48/packages/xdc/bld/package.xs
package.mak: config.bld
package.mak: package.bld
endif


all: .executables 
.executables: .libraries .dlls
.libraries: .interfaces

PKGCFGS := $(wildcard package.xs) package/build.cfg
.interfaces: package/package.xdc.inc package/package.defs.h package.xdc $(PKGCFGS)

-include package/package.xdc.dep
package/%.xdc.inc package/%_evmc6678Omp.c package/%.defs.h: %.xdc $(PKGCFGS)
	@$(MSG) generating interfaces for package evmc6678Omp" (because $@ is older than $(firstword $?))" ...
	$(XSRUN) -f xdc/services/intern/cmd/build.xs $(MK_IDLOPTS) -m package/package.xdc.dep -i package/package.xdc.inc package.xdc

ifeq (,$(MK_NOGENDEPS))
-include package/package.cfg.dep
endif

package/rel/undefinedevmc6678Omppackage/package.rel.xml: package/package.cfg.xdc.inc
package/package.cfg.xdc.inc: $(XDCROOT)/packages/xdc/cfg/cfginc.js package.xdc
	@$(MSG) generating schema include file list ...
	$(CONFIG) -f $(XDCROOT)/packages/xdc/cfg/cfginc.js evmc6678Omp $@

test:;
%,copy:
	@$(if $<,,$(MSG) don\'t know how to build $*; exit 1)
	@$(MSG) cp $< $@
	$(RM) $@
	$(CP) $< $@

$(XDCCFGDIR)%.c $(XDCCFGDIR)%.h $(XDCCFGDIR)%.xdl: $(XDCCFGDIR)%.cfg .interfaces $(XDCROOT)/packages/xdc/cfg/Main.xs
	@$(MSG) "configuring $(_PROG_NAME) from $< ..."
	$(CONFIG) $(_PROG_XSOPTS) xdc.cfg $(_PROG_NAME) $(XDCCFGDIR)$*.cfg $(XDCCFGDIR)$*

.PHONY: release,evmc6678Omp
evmc6678Omp.zip: package/package.bld.xml
evmc6678Omp.zip: package/build.cfg
evmc6678Omp.zip: package/package.xdc.inc
evmc6678Omp.zip: package/package.cfg.xdc.inc
ifeq (,$(MK_NOGENDEPS))
-include package/rel/evmc6678Omp.zip.dep
endif
package/rel/evmc6678Omp/evmc6678Omp/package/package.rel.xml: .force
	@$(MSG) generating external release references $@ ...
	$(XS) $(JSENV) -f $(XDCROOT)/packages/xdc/bld/rel.js $(MK_RELOPTS) . $@

evmc6678Omp.zip: package/rel/evmc6678Omp.xdc.inc package/rel/evmc6678Omp/evmc6678Omp/package/package.rel.xml
	@$(MSG) making release file $@ "(because of $(firstword $?))" ...
	-$(RM) $@
	$(call MKRELZIP,package/rel/evmc6678Omp.xdc.inc,package/rel/evmc6678Omp.zip.dep)


release release,evmc6678Omp: all evmc6678Omp.zip
clean:: .clean
	-$(RM) evmc6678Omp.zip
	-$(RM) package/rel/evmc6678Omp.xdc.inc
	-$(RM) package/rel/evmc6678Omp.zip.dep

clean:: .clean
	-$(RM) .libraries .libraries,*
clean:: 
	-$(RM) .dlls .dlls,*
#
# The following clean rule removes user specified
# generated files or directories.
#

ifneq (clean,$(MAKECMDGOALS))
ifeq (,$(wildcard package))
    $(shell $(MKDIR) package)
endif
ifeq (,$(wildcard package/cfg))
    $(shell $(MKDIR) package/cfg)
endif
ifeq (,$(wildcard package/lib))
    $(shell $(MKDIR) package/lib)
endif
ifeq (,$(wildcard package/rel))
    $(shell $(MKDIR) package/rel)
endif
ifeq (,$(wildcard package/internal))
    $(shell $(MKDIR) package/internal)
endif
ifeq (,$(wildcard package/external))
    $(shell $(MKDIR) package/external)
endif
endif
clean::
	-$(RMDIR) package


