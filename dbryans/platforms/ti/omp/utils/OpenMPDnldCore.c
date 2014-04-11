/* 
 * Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/
#include <string.h>
#include <ti/sdo/ipc/_Ipc.h>
#include <xdc/runtime/System.h>
#include <ti/omp/utils/OpenMP.h>

#include <stdio.h>
/* MAL Library functions */


//#define DEVICE 6670

#if !(defined DEVICE)
#error DEVICE not defined
#endif

/* Tomahawk */
#if (DEVICE==6472)
#include "device_C6472.h"
/* Nyquist */
#elif (DEVICE==6670)
#include "device_C6670.h"
/* Shannon */
#elif (DEVICE==6678)
#include "device_C6678.h"
#else
#error "no device defined"
#endif


/* Defines for NML BOOT STATUS */
#define NML_STATUS_APP_ENTRY	0xff
#define NML_STATUS_RETURNED_FROM_APP	0x100

extern volatile unsigned int cregister DNUM;

static int reset_run_core(unsigned int coreId, unsigned int ba);
static int reset_core(unsigned int coreId);

/**
 * @brief
 *   Writeback/Invalidate L1D and L2 cache 
 *   size is specified in 32bit words
 */
#define CACHE_INV_ONLY  1
#define CACHE_WB_ONLY  2
#define CACHE_WB_AND_INV  3

#define DEVICE_IPCGR_BASE  0x2620240
#define DEVICE_IPCGR(x)    *((volatile unsigned int *)(DEVICE_IPCGR_BASE + ((x)*4)))

#define CSL_IPC_WRITE(core, v)   DEVICE_IPCGR(core) = (v)


static int reset_run_core(unsigned int coreId, unsigned int ba)
{
	volatile unsigned int *reg;
	unsigned int mod_id, pd;

    mod_id = GET_PSC_MOD(coreId);

	/* Enable power domain module */
#if ((DEVICE==6678) || (DEVICE==6670))
    pd = GET_PD(coreId);
#elif (DEVICE==6472)
	pd = (*(unsigned int *)MDCFG_ADDR(mod_id) & MDCFG_PD_MASK) >> 16;
#endif


#if 0
	/* Place the core in reset */
	reg = (unsigned int*)MDCTL_ADDR(mod_id);
	*reg = (*reg & ~ MDCTL_NEXT_STATE_MASK) | MDCTL_NEXT_STATE_EN;
	*reg = (*reg & ~ MDCTL_LRSTZ_MASK);


	reg = (unsigned int*)PTCMD_ADDR;
	*reg = (1 << pd);

	/* Poll for transition done */
	reg = (unsigned int*)PTSTAT_ADDR;
	while ((*reg & (1 << pd)));

#endif
	/* Setup the BOOT_ADDR */
	/* boot address should be 1KB aligned */
	if (ba & 0x3ff)
		return -1;

	KICK0 = KICK0_UNLOCK;
    KICK1 = KICK1_UNLOCK;

	reg = (unsigned int*)BOOT_ADDR(coreId);
#if ((DEVICE==6678) || (DEVICE==6670))
   	*reg = ba;
#elif (DEVICE==6472)
   	*reg = (ba >> 10);
#endif

#if 0
	/* Set the bootcomplete register */
	CSL_IPC_WRITE(coreId, 1);
#endif

	/* Take the core out of reset */
	reg = (unsigned int*)MDCTL_ADDR(mod_id);
	*reg = (*reg & ~ MDCTL_NEXT_STATE_MASK) | MDCTL_NEXT_STATE_EN;
	*reg = (*reg & ~ MDCTL_LRSTZ_MASK) | MDCTL_LRSTZ_MASK;

	/* Enable power domain module */
	reg = (unsigned int*)PTCMD_ADDR;
	*reg = (1 << pd);

	/* Poll for transition done */
	reg = (unsigned int*)PTSTAT_ADDR;
	while ((*reg & (1 << pd)));
    
    /* Verify state change */
	reg = (unsigned int*)MDSTAT_ADDR(mod_id);
    while ((*reg & MDSTAT_STATE_MASK) != MDSTAT_STATE_EN);

	return 0;
}

static int reset_core(unsigned int coreId)
{
	volatile unsigned int *reg;
	unsigned int mod_id, pd;

    mod_id = GET_PSC_MOD(coreId);

	/* Place the core in reset */
	reg = (unsigned int*)MDCTL_ADDR(mod_id);
	*reg = (*reg & ~ MDCTL_NEXT_STATE_MASK) | MDCTL_NEXT_STATE_EN;
	*reg = (*reg & ~ MDCTL_LRSTZ_MASK);

#if ((DEVICE==6678) || (DEVICE==6670))
    pd = GET_PD(coreId);
#elif (DEVICE==6472)
	pd = (*(unsigned int *)MDCFG_ADDR(mod_id) & MDCFG_PD_MASK) >> 16;
#endif

	/* Enable power domain module */
	reg = (unsigned int*)PTCMD_ADDR;
	*reg = (1 << pd);

	/* Poll for transition done */
	reg = (unsigned int*)PTSTAT_ADDR;
	while ((*reg & (1 << pd)));
	return 0;
}

#define L2MEM_SIZE        0x00080000
#define L2MEM_ADDR        0x00800000
#define L2MEM_ADDR_G(x)   (0x10800000 | ((x) << 24))

extern cregister volatile unsigned int DNUM;
extern void _c_int00(void);
extern cregister volatile unsigned int TSCL;
int siu_ibl_download_core(void)
{
  int i;
  int status;
  
  if(DNUM==OpenMP_baseIdOfCluster) {
   
    for (i=(DNUM + 1); i < (ti_sdo_utils_MultiProc_numProcsInCluster+OpenMP_baseIdOfCluster); i++) {
      /* Reset each core before copying data */
	  reset_core(i);
	  
      memcpy((void *)L2MEM_ADDR_G(i),(void *)L2MEM_ADDR,L2MEM_SIZE);
	  /* reset core after loading data and run from _c_int00 */
	  status=reset_run_core(i,(int)_c_int00);
	  if(status)
	  {
		  System_abort("Error: running the core after reset\n");
	  }

    }
  }
  return (1);
}


