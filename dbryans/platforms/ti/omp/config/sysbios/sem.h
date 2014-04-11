/* Copyright (C) 2005, 2006, 2009 Free Software Foundation, Inc.
   Contributed by Richard Henderson <rth@redhat.com>.

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
   
   This is a SYS/BIOS specific implementation of a semaphore synchronization
   mechanism for libgomp.  This type is private to the library.    */


#ifndef GOMP_SEM_H
#define GOMP_SEM_H 1

#define HW_sem

#include <ti/omp/utils/OpenMP.h>
#include <ti/csl/csl_semAux.h>
#define ti_sdo_ipc_ListMP__internalaccess
#include <ti/sdo/ipc/_ListMP.h>
#include <ti/sdo/ipc/_GateMP.h>
#include <ti/ipc/MultiProc.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/knl/Task.h>


typedef struct gomp_sem_t {
    volatile UInt count;
} gomp_sem_t;

#pragma STRUCT_ALIGN (gomp_sem_t, 8);

static inline void gomp_sem_destroy (gomp_sem_t *sem)
{
    /*
     *  Nothing needed here.  Local instance was already deleted in
     *  gomp_sem_init
     */

}
static inline void gomp_sem_wait (gomp_sem_t *sem)
{
#ifdef HW_sem
    while ((CSL_semAcquireDirect ( OpenMP_ompHwSem)) == 0);
    while(sem->count == 0) {
		CSL_semReleaseSemaphore ( OpenMP_ompHwSem);
        Task_yield();
        while ((CSL_semAcquireDirect ( OpenMP_ompHwSem)) == 0);
    };
    sem->count--;
    _mfence();
    asm(" NOP 9");  /* Require 16 NOPs after an MFENCE */
    asm(" NOP 7");
    CSL_semReleaseSemaphore ( OpenMP_ompHwSem);
#else
    UInt key;
    GateMP_Handle gate;

    gate = GateMP_getDefaultRemote();
    key = GateMP_enter(gate);
    while(sem->count == 0) {
        GateMP_leave(gate, key);
        Task_yield();
        key = GateMP_enter(gate);
    };
    sem->count--;
    GateMP_leave(gate, key);

#endif

}
static inline void gomp_sem_post (gomp_sem_t *sem)
{
#ifdef HW_sem
	while ((CSL_semAcquireDirect ( OpenMP_ompHwSem)) == 0);
    sem->count++;
    _mfence();
    asm(" NOP 9");  /* Require 16 NOPs after an MFENCE */
    asm(" NOP 7");
	CSL_semReleaseSemaphore ( OpenMP_ompHwSem);
#else
    UInt key;
    GateMP_Handle gate;

    gate = GateMP_getDefaultRemote();

    key = GateMP_enter(gate);
    sem->count++;
    GateMP_leave(gate, key);

#endif

}



static inline void gomp_sem_init (gomp_sem_t *sem, int value)
{
    sem->count = value;
	_mfence();
    asm(" NOP 9");  /* Require 16 NOPs after an MFENCE */
    asm(" NOP 7");
	
}
#endif /* GOMP_SEM_H  */
