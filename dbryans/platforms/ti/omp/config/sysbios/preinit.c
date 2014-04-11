/* Copyright (C) 2005, 2008, 2009 Free Software Foundation, Inc.
   Contributed by Jakub Jelinek <jakub@redhat.com>.

   This file is part of the GNU OpenMP Library (libgomp).

   Libgomp is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   Libgomp is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
   FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
   more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */

/* Copyright (C) 2011
   Texas Instruments, Inc.
   Created by Shreyas Prasad <shreyasp@ti.com>. 
   
   SYS/BIOS-specific code used to
   1) Alias MSMC RAM to a non-cached alias 
   2) Initialize static variables in COFF executables to '0' at boot-time */ 

#ifndef __TI_ELFABI__
extern far int  __cinit__;  /* define by TI linker == -1 if .cinit isn't loaded */
extern char __bss__[];    /* defined by the TI linker to be the start of .bss */
extern char __end__;    /* defined by the TI linker to be the end of .bss */
#endif

#include <cpy_tbl.h>
#include <xdc/std.h>

#ifdef ti_targets_elf_C66
#include <ti/csl/csl_xmcAux.h>
#include <ti/omp/utils/OpenMP.h>

#define SEGSZ_4MB       0x15
//#define RADDR           0x0C000000 /* Physical address of MSMC RAM */
//#define MPAX_INDEX      3  

extern COPY_TABLE __binit__;

static void initMPAX(void)
{    
    CSL_XMC_XMPAXH mpaxh;
    CSL_XMC_XMPAXL mpaxl;

    CSL_XMC_getXMPAXL (OpenMP_mpaxIndex, &mpaxl);
    CSL_XMC_getXMPAXH (OpenMP_mpaxIndex, &mpaxh);

    mpaxh.segSize = SEGSZ_4MB;
    mpaxh.bAddr = OpenMP_noncachedMsmcAlias >> 12;

    CSL_XMC_setXMPAXH (OpenMP_mpaxIndex, &mpaxh);

    mpaxl.ux = 1;
    mpaxl.uw = 1;
    mpaxl.ur = 1;
    mpaxl.sx = 1;
    mpaxl.sw = 1;
    mpaxl.sr = 1;
    mpaxl.rAddr = OpenMP_mpaxRaddr >> 12;//RADDR;

    CSL_XMC_setXMPAXL (OpenMP_mpaxIndex, &mpaxl);
    
    /* Initialize the RUN linker sections since the MSMC alias is now available  */
    copy_in(&__binit__);
}
#endif

#ifndef __TI_ELFABI__
static void initBss()
{
    /* if .cinit is not loaded, the loader has already initialized .bss */
    if (&__cinit__ != (int *)-1) {
        char *cp;

        /* otherwise, we initialize all .bss to 0 before .cinit is processed */
        for (cp = __bss__; cp <= &__end__; ) {
            *cp++ = 0;
        }
    }
}
#endif

/*
 *  ======== _system_pre_init ========
 *  Called by the reset code prior to .cinit processing (which
 *  initializes all explicitly initialized C static or global variables)
 */
int _system_pre_init(void)
{
#ifdef ti_targets_elf_C66
    initMPAX();
#endif
    
#ifndef __TI_ELFABI__
    initBss();
#endif

    return (1);
}

