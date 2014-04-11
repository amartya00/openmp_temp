/* This file is tests DMA using edma3 lld*/

#include <stdio.h>
#include "edma.h"
// #include "memory.h"

#include <xdc/std.h>

#include <ti/sysbios/family/c66/Cache.h>
#include <ti/csl/csl_cacheAux.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Timestamp.h>

// includes needed for heap/memory allocation
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/cfg/global.h>


#define NUM_BYTES1 1024 * sizeof(unsigned short)
#define NUM_BYTES2 512 * sizeof(unsigned short)
#define NUM_BYTES3 4096 * sizeof(unsigned short)


void main(void) {

	Uint32 timestamp, delta;
	timestamp = Timestamp_get32();

	EDMA3_DRV_Result edmaResult = EDMA3_DRV_SOK;


	unsigned const short *L1d_p9;
	unsigned const short *L1d_p10;

	unsigned short *mainSourceImg;
	unsigned short *referenceImg1;

	L1d_p9 = (unsigned const short *) Memory_alloc((IHeap_Handle) l2Heap, (NUM_BYTES1), 0, NULL);
	L1d_p10 = (unsigned const short *) Memory_alloc((IHeap_Handle) l2Heap, (NUM_BYTES3), 0, NULL);

	referenceImg1 = (unsigned short *) Memory_alloc((IHeap_Handle) l2Heap, (NUM_BYTES1), 0, NULL);
	mainSourceImg = (unsigned short *) Memory_alloc((IHeap_Handle) l2Heap, (NUM_BYTES3), 0, NULL);

	int i;

	edmaWait4Completion(1);

	for (i = 0; i < 1024; i++) {
		mainSourceImg[i] = 1;
	}

	edmaInit();

	edmaInitiateXfer(L1d_p10, mainSourceImg, NUM_BYTES2, 8, 1, NUM_BYTES2, NUM_BYTES2, 1, 1, 0, 1);
	edmaWait4Completion(0);

	edmaInitiateXfer(L1d_p9, referenceImg1, NUM_BYTES2, 2, 1, NUM_BYTES2, NUM_BYTES2, 1, 1, 0, 1);
	edmaWait4Completion(0);

	delta = Timestamp_get32()-timestamp;

}
