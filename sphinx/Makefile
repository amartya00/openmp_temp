#
# $Log: Makefile,v $
# Revision 1.20  2000/11/15 00:00:39  bronis
# made changes to improve scalability
#
# Revision 1.19  2000/09/15 00:04:59  bronis
# Added assure makefiles and removed problems revealed by assure
#
# Revision 1.18  2000/09/06 21:09:12  bronis
# Added several OpenMP versions for Alpha clusters in various states of correctness
#
# Revision 1.17  2000/08/25 23:17:15  bronis
# Added OpenMP tests
#
# Revision 1.16  2000/03/16 15:48:38  bronis
# fixed mpguidec warnings
#
# Revision 1.15  2000/01/10 22:27:45  bronis
# fixed minor Makefile bug
#
# Revision 1.14  2000/01/10 21:50:23  bronis
# Added full blown aux tests implementation
#
# Revision 1.13  2000/01/04 18:31:08  bronis
# Added Makefile.DEC.MPICH.P4
#
# Revision 1.12  1999/09/21 23:28:38  bronis
# fixed pthreads tests
#
# Revision 1.11  1999/09/21 15:59:49  bronis
# Added make unmeasured; fixed call_*_prologue bug
#
# Revision 1.10  1999/09/14 16:38:50  srtaylor
# First cut at multiple dimensions
#
# Revision 1.9  1999/09/03 16:47:58  bronis
# Fixed IBM_MPICH clean
#
# Revision 1.8  1999/09/03 16:38:46  bronis
# Added Makefile.IBM.MPICH
#
# Revision 1.7  1999/08/25 15:13:08  bronis
# make clean now cleans DEC_MPICH
#
# Revision 1.6  1999/08/25 15:10:12  bronis
# Added Makefile.DEC.MPICH
#
# Revision 1.5  1999/08/10 20:51:03  bronis
# Added priority chart
#
# Revision 1.4  1999/07/29 17:02:42  bronis
# Fixed bug in alignment fix
#
# Revision 1.3  1999/07/27 21:50:53  bronis
# Added Makefile.SUN.MPICH
#
# Revision 1.2  1999/07/27 16:32:40  srtaylor
# Moved -D flags to top level Makefile
#
# Revision 1.1.1.1  1999/05/11 16:50:02  srtaylor
# CVS repository setup for sphinx
#
#

ALL: default

MAKE  = make

SHELL = /bin/sh

SOURCE_FILES = "autodist.c automeasure.c bind.c data_list.c mw.c pqtypes.c \
	sphinx_call.c sphinx_col.c sphinx_error.c sphinx_mem.c \
	sphinx_params.c sphinx_post.c sphinx_p2p.c sphinx_simple.c \
	sphinx_threads.c sphinx_tools.c sphinx_aux_test.c sphinx_omp.c \
        sphinx.c"

#C_FLAGS = "-g -c -DMULTI_DIM -DMY_TEST_IO"
C_FLAGS = "-g -c -DMULTI_DIM"

DEC: DEC_SPHINX DEC_YIELD

DEC_SPHINX:
	@make -f Makefile.DEC dec_sphinx SOURCE_FILES=${SOURCE_FILES} \
	                                 C_FLAGS=${C_FLAGS}

DEC_YIELD:
	@make -f Makefile.DEC dec_yieldtest

DEC_CLEAN:
	@make -f Makefile.DEC clean

DEC_OMP: DEC_OMP_SPHINX DEC_OMP_YIELD

DEC_OMP_SPHINX:
	@make -f Makefile.DEC.OMP dec_omp_sphinx \
                       SOURCE_FILES=${SOURCE_FILES} C_FLAGS=${C_FLAGS}

DEC_OMP_YIELD:
	@make -f Makefile.DEC.OMP dec_omp_yieldtest

DEC_OMP_CLEAN:
	@make -f Makefile.DEC.OMP clean

DEC_GUIDE: DEC_GUIDE_SPHINX DEC_GUIDE_YIELD

DEC_GUIDE_SPHINX:
	@make -f Makefile.DEC.GUIDE dec_guide_sphinx \
                      SOURCE_FILES=${SOURCE_FILES} C_FLAGS=${C_FLAGS}

DEC_GUIDE_YIELD:
	@make -f Makefile.DEC.GUIDE dec_guide_yieldtest

DEC_GUIDE_CLEAN:
	@make -f Makefile.DEC.GUIDE clean

DEC_ASSURE: DEC_ASSURE_SPHINX DEC_ASSURE_YIELD

DEC_ASSURE_SPHINX:
	@make -f Makefile.DEC.ASSURE dec_assure_sphinx \
                      SOURCE_FILES=${SOURCE_FILES} C_FLAGS=${C_FLAGS}

DEC_ASSURE_YIELD:
	@make -f Makefile.DEC.ASSURE dec_assure_yieldtest

DEC_ASSURE_CLEAN:
	@make -f Makefile.DEC.ASSURE clean

DEC_PRUN: DEC_PRUN_SPHINX DEC_PRUN_YIELD

DEC_PRUN_SPHINX:
	@make -f Makefile.DEC.PRUN dec_prun_sphinx \
                      SOURCE_FILES=${SOURCE_FILES} C_FLAGS=${C_FLAGS}

DEC_PRUN_YIELD:
	@make -f Makefile.DEC.PRUN dec_prun_yieldtest

DEC_PRUN_CLEAN:
	@make -f Makefile.DEC.PRUN clean

DEC_PRUN_OMP: DEC_PRUN_OMP_SPHINX DEC_PRUN_OMP_YIELD

DEC_PRUN_OMP_SPHINX:
	@make -f Makefile.DEC.PRUN.OMP dec_prun_omp_sphinx \
                      SOURCE_FILES=${SOURCE_FILES} C_FLAGS=${C_FLAGS}

DEC_PRUN_OMP_YIELD:
	@make -f Makefile.DEC.PRUN.OMP dec_prun_omp_yieldtest

DEC_PRUN_OMP_CLEAN:
	@make -f Makefile.DEC.PRUN.OMP clean

DEC_GUIDE_PRUN: DEC_GUIDE_PRUN_SPHINX DEC_GUIDE_PRUN_YIELD

DEC_GUIDE_PRUN_SPHINX:
	@make -f Makefile.DEC.GUIDE.PRUN dec_guide_prun_sphinx \
                      SOURCE_FILES=${SOURCE_FILES} C_FLAGS=${C_FLAGS}

DEC_GUIDE_PRUN_YIELD:
	@make -f Makefile.DEC.GUIDE.PRUN dec_guide_prun_yieldtest

DEC_GUIDE_PRUN_CLEAN:
	@make -f Makefile.DEC.GUIDE.PRUN clean

DEC_MPICH: DEC_MPICH_SPHINX DEC_MPICH_YIELD

DEC_MPICH_SPHINX:
	@make -f Makefile.DEC.MPICH dec_mpich_sphinx \
	                     SOURCE_FILES=${SOURCE_FILES} C_FLAGS=${C_FLAGS}

DEC_MPICH_YIELD:
	@make -f Makefile.DEC.MPICH dec_mpich_yieldtest

DEC_MPICH_CLEAN:
	@make -f Makefile.DEC.MPICH clean

DEC_MPICH_P4: DEC_MPICH_P4_SPHINX DEC_MPICH_P4_YIELD

DEC_MPICH_P4_SPHINX:
	@make -f Makefile.DEC.MPICH.P4 dec_mpich_p4_sphinx \
	                     SOURCE_FILES=${SOURCE_FILES} C_FLAGS=${C_FLAGS}

DEC_MPICH_P4_YIELD:
	@make -f Makefile.DEC.MPICH.P4 dec_mpich_p4_yieldtest

DEC_MPICH_P4_CLEAN:
	@make -f Makefile.DEC.MPICH.P4 clean

ALPHA_LINUX_MPICH: ALPHA_LINUX_MPICH_SPHINX ALPHA_LINUX_MPICH_YIELD

ALPHA_LINUX_MPICH_SPHINX:
	@make -f Makefile.ALPHA.LINUX.MPICH alpha_linux_mpich_sphinx \
	                     SOURCE_FILES=${SOURCE_FILES} C_FLAGS=${C_FLAGS}

ALPHA_LINUX_MPICH_YIELD:
	@make -f Makefile.ALPHA.LINUX.MPICH alpha_linux_mpich_yieldtest

ALPHA_LINUX_MPICH_CLEAN:
	@make -f Makefile.ALPHA.LINUX.MPICH clean

IBM: IBM_SPHINX IBM_YIELD

IBM_SPHINX:
	@make -f Makefile.IBM ibm_sphinx SOURCE_FILES=${SOURCE_FILES} \
	                                 C_FLAGS=${C_FLAGS}

IBM_YIELD:
	@make -f Makefile.IBM ibm_yieldtest

IBM_CLEAN:
	@make -f Makefile.IBM clean

IBM_OMP: IBM_OMP_SPHINX IBM_OMP_YIELD

IBM_OMP_SPHINX:
	@make -f Makefile.IBM.OMP ibm_omp_sphinx SOURCE_FILES=${SOURCE_FILES} \
	                                 C_FLAGS=${C_FLAGS}

IBM_OMP_YIELD:
	@make -f Makefile.IBM.OMP ibm_omp_yieldtest

IBM_OMP_CLEAN:
	@make -f Makefile.IBM.OMP clean

IBM_R7: IBM_R7_SPHINX IBM_R7_YIELD

IBM_R7_SPHINX:
	@make -f Makefile.IBM.r7 ibm_r7_sphinx SOURCE_FILES=${SOURCE_FILES} \
	                                       C_FLAGS=${C_FLAGS}

IBM_R7_YIELD:
	@make -f Makefile.IBM.r7 ibm_r7_yieldtest

IBM_R7_CLEAN:
	@make -f Makefile.IBM.r7 clean

IBM_MPICH: IBM_MPICH_SPHINX IBM_MPICH_YIELD

IBM_MPICH_SPHINX:
	@make -f Makefile.IBM.MPICH ibm_mpich_sphinx \
                  SOURCE_FILES=${SOURCE_FILES} C_FLAGS=${C_FLAGS}

IBM_MPICH_YIELD:
	@make -f Makefile.IBM.MPICH ibm_mpich_yieldtest

IBM_MPICH_CLEAN:
	@make -f Makefile.IBM.MPICH clean

IBM_MPGUIDE: IBM_MPGUIDE_SPHINX IBM_MPGUIDE_YIELD

IBM_MPGUIDE_SPHINX:
	@make -f Makefile.IBM.MPGUIDE ibm_mpguide_sphinx \
	                   SOURCE_FILES=${SOURCE_FILES} C_FLAGS=${C_FLAGS}

IBM_MPGUIDE_YIELD:
	@make -f Makefile.IBM.MPGUIDE ibm_mpguide_yieldtest

IBM_MPGUIDE_CLEAN:
	@make -f Makefile.IBM.MPGUIDE clean

SGI: SGI_SPHINX SGI_YIELD

SGI_SPHINX:
	@make -f Makefile.SGI sgi_sphinx SOURCE_FILES=${SOURCE_FILES} \
	                                 C_FLAGS=${C_FLAGS}

SGI_YIELD:
	@make -f Makefile.SGI sgi_yieldtest

SGI_CLEAN:
	@make -f Makefile.SGI clean

SUN_MPICH: SUN_MPICH_SPHINX SUN_MPICH_YIELD

SUN_MPICH_SPHINX:
	@make -f Makefile.SUN.MPICH sun_mpich_sphinx \
	                      SOURCE_FILES=${SOURCE_FILES} C_FLAGS=${C_FLAGS}

SUN_MPICH_PURE_SPHINX:
	@make -f Makefile.SUN.MPICH sun_mpich_pure_sphinx \
	                      SOURCE_FILES=${SOURCE_FILES} C_FLAGS=${C_FLAGS}

SUN_MPICH_YIELD:
	@make -f Makefile.SUN.MPICH sun_mpich_yieldtest

SUN_MPICH_CLEAN:
	@make -f Makefile.SUN.MPICH clean

SUN: SUN_SPHINX SUN_YIELD

SUN_SPHINX:
	@make -f Makefile.SUN sun_sphinx SOURCE_FILES=${SOURCE_FILES} \
	                                 C_FLAGS=${C_FLAGS}

SUN_PURE_SPHINX:
	@make -f Makefile.SUN sun_pure_sphinx SOURCE_FILES=${SOURCE_FILES} \
	                                 C_FLAGS=${C_FLAGS}

SUN_YIELD:
	@make -f Makefile.SUN sun_yieldtest

SUN_CLEAN:
	@make -f Makefile.SUN clean

SUN_OMP: SUN_OMP_SPHINX SUN_OMP_YIELD

SUN_OMP_SPHINX:
	@make -f Makefile.SUN.OMP sun_omp_sphinx \
	                    SOURCE_FILES=${SOURCE_FILES} C_FLAGS=${C_FLAGS}

SUN_OMP_PURE_SPHINX:
	@make -f Makefile.SUN.OMP sun_omp_pure_sphinx \
	                    SOURCE_FILES=${SOURCE_FILES} C_FLAGS=${C_FLAGS}

SUN_OMP_YIELD:
	@make -f Makefile.SUN.OMP sun_omp_yieldtest

SUN_OMP_CLEAN:
	@make -f Makefile.SUN.OMP clean

all: default

default:
	@echo "Please specify a target architecture"

clean: DEC_CLEAN DEC_OMP_CLEAN DEC_GUIDE_CLEAN DEC_ASSURE_CLEAN \
           DEC_PRUN_CLEAN DEC_PRUN_OMP_CLEAN DEC_GUIDE_PRUN_CLEAN \
               DEC_MPICH_CLEAN DEC_MPICH_P4_CLEAN ALPHA_LINUX_MPICH_CLEAN \
                   IBM_CLEAN IBM_R7_CLEAN IBM_MPICH_CLEAN IBM_MPGUIDE_CLEAN \
                       IBM_OMP_CLEAN SGI_CLEAN SUN_CLEAN SUN_OMP_CLEAN \
                           SUN_MPICH_CLEAN

unmeasured: 
	@-/bin/rm -f *.out *.out.* *.log*

veryclean: unmeasured clean




