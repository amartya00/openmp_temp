#
# $log$
#

.SUFFIXES:
.SUFFIXES: .c .f .dec.mpich.p4.o
 
srcdir = .
 
ALL: default

CC          = mpicc_p4
CLINKER     = mpicc_p4
OPTFLAGS    = -g

MAKE        = make

SHELL = /bin/sh

CFLAGS = $(OPTFLAGS) -DDEC -DBUILD_MPILIB_NAME=\\\"MPICH-ch_p4\\\" $(C_FLAGS)

LIBS = -lm -lrt -pthread -lmach

DEC_MPICH_P4_OBJS = ${SOURCE_FILES:.c=.dec.mpich.p4.o}

EXECS = dec_mpich_p4_sphinx dec_mpich_p4_yieldtest

default: $(EXECS)

linktest: default clean

all: default

dec_mpich_p4_sphinx: $(DEC_MPICH_P4_OBJS)
	$(CLINKER) $(OPTFLAGS) -o dec_mpich_p4_sphinx \
                                         $(DEC_MPICH_P4_OBJS) $(LIBS)

dec_mpich_p4_yieldtest: yieldtest.dec.mpich.p4.o
	$(CLINKER) $(OPTFLAGS) -o dec_mpich_p4_yieldtest \
                                           yieldtest.dec.mpich.p4.o $(LIBS)

clean:
	@-/bin/rm -f *.dec.mpich.p4.o *~ PI* $(EXECS) core

.c.dec.mpich.p4.o:
	$(CC) $(CFLAGS) -c -o $@ $*.c







