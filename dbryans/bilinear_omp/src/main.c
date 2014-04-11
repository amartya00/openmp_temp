/*
 *  ======== main.c ========
 */

#include <xdc/std.h>

#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>

#include <ti/sysbios/BIOS.h>

#include <ti/sysbios/knl/Task.h>

#include<stdio.h>

#include <c6x.h>
#include <ti/omp/omp.h>

#include <string.h>
#include <assert.h>
#include <stdio.h>

#include <xdc/runtime/Timestamp.h>
#include <xdc/runtime/Types.h>
#include "cos.h"
#include "sin.h"

#define NTHREADS  (unsigned short) 8

#define IMG_COLS (unsigned short) 1920
#define IMG_ROWS (unsigned short) 1080

#define CHUNK_SIZE (IMG_ROWS)/(NTHREADS)
//void bilinear(void);

// ======== taskFxn ========
/* Void taskFxn(UArg a0, UArg a1) */
/* { */
/*     System_printf("enter taskFxn()\n"); */

/*     img_conv(); */

/*     System_printf("exit taskFxn()\n"); */
/* } */

/*
 *  ======== main ========
 */
void main(void)
{ 
    /* Task_Handle task; */
    /* Error_Block eb; */

    printf("enter main()\n");
    unsigned int i =0;//Change to unsigned int
    unsigned int j =0;

    int itcos = 0;
    int itsin = 0;
    int it = 0;
    int jt = 0;
    int ir =0;
    int jr = 0;
    int sinTh = 0;
    int cosTh = 0;

    int sinThNeg = 0;

    int w1 = 0;
    int w2 = 0;

    int si = 0;
    int sj = 0;

    int si_t = 0;
    int sj_t = 0;
    
    unsigned short tid = 0;

    unsigned int outBi;
    //unsigned short chunkSize = 0;
    unsigned short nthreads;

    const unsigned char *in;
    unsigned short theta = 45;
    unsigned char *out;

    unsigned int delta    = 0;
    unsigned int timestamp = 0;

    unsigned int maskHigh = 0;
    unsigned int maskLow = 0;

    uint64_t start_time, end_time;

    __x128_t irjr;
    __x128_t sinCos_128;
    __x128_t itjt_128;

    long long irjr_l;

    long long irjr_shr;

    long long irjr_add;

    long long imgDim = _itoll(IMG_COLS, IMG_ROWS);
    long long imgZero = _itoll(0,0);
    long long imgDimHalf = _itoll((IMG_ROWS)/2, (IMG_COLS)/2);

    __x128_t imgLoc;
    __x128_t sis_128;
    __x128_t imgCol4 = _ito128(IMG_COLS, IMG_COLS, IMG_COLS, IMG_COLS);

    long long coeff;

    long long imgLoc_si_sj;
    long long imgLoc_si1_sj;


    nthreads = NTHREADS;
    // omp_set_num_threads(nthreads);

    sinTh = sin_16[theta];
    sinThNeg = -1 * sin_16[theta];
    cosTh = cos_16[theta];
    

    in  = (unsigned char *)(0x82000000);
    out = (unsigned char *)(0x86000000);

    //timestamp = Timestamp_get32();


    // tid = 0;
    sinCos_128 = _ito128(cosTh, sinTh, sinThNeg, cosTh);
    start_time = _itoll(TSCH,TSCL);    
    // #pragma omp parallel shared(in, out) private(i,j,jt, it, itjt_128, irjr, irjr_l ,irjr_shr, irjr_add, si, sj, tid, maskLow, maskHigh, w1, w2, coeff, imgLoc, imgLoc_si,sj, imgLoc_si1_sj, outBi)
    {
        // #pragma omp for
        // tid = omp_get_thread_num();
        //printf("%d : %d\n", tid*(CHUNK_SIZE), (tid+1)*(CHUNK_SIZE));
        // for (i = tid*(CHUNK_SIZE); i < (tid+1)*(CHUNK_SIZE); i++){
        for (i = 0; i < IMG_ROWS; i++){
            for (j = 0; j < IMG_COLS; j++){
                it = (i - (IMG_ROWS)/2);                
                jt = (j - (IMG_COLS)/2);

                /* itcos = it * cosTh; */
                /* itsin = it * sinTh; */

                /* ir = itcos - jt * sinTh; */
                /* jr = itsin + jt * cosTh; */

                
                itjt_128 = _ito128(it,it,jt,jt);
                
                irjr = _qmpy32(sinCos_128, itjt_128);

                irjr_l = _dadd(_hi128(irjr),_lo128(irjr));
                
                /* si = ir >> 8; */
                /* sj = jr >> 8; */
                irjr_shr = _dshr(irjr_l,8);
            
                // si = si + IMG_ROWS/2 -1;
                // sj = sj + IMG_COLS/2 -1;

                irjr_add = _dadd(irjr_shr, imgDimHalf);

                maskLow = _dcmpgt2(irjr_add, imgZero);
                maskHigh = _dcmpgt2(imgDim, irjr_add);

                si = _hill(irjr_add);
                sj = _loll(irjr_add);

                // if (si > 0 && si < IMG_ROWS ) {
                if (maskHigh == maskLow) {
                    // if(sj >0 && sj < IMG_COLS) {

                        w1 = (_hill(irjr_shr)) & (0xF);
                        w2 = (_loll(irjr_shr)) & (0xF);
                        coeff = _mpyu4ll((0xF-w1)<<24|w1<<16|(0xF-w1)<<8|w1,(0xF-w2)<<24|w2<<16|(0xF-w2)<<8|w2);
                        imgLoc = _qmpy32(_ito128(si,si,si+1,si+1), imgCol4);
                        imgLoc_si_sj = _dadd(_hi128(imgLoc), _itoll(sj,sj+1));
                        imgLoc_si1_sj = _dadd(_lo128(imgLoc),_itoll(sj,sj+1));
                        
                        // outBi = (0xF - w1)*((0xF-w2)*in[si * IMG_COLS + sj] + (0xF-w2)*w1*in[(si+1) * IMG_COLS + sj]) + (0xF-w1)*w2((0xF-w2)*in[si * IMG_COLS + sj +1] + w1*w2*in[(si+1) * IMG_COLS + sj +1]);
                        outBi = _dotpsu4h(_itoll(in[_hill(imgLoc_si_sj)]<<16|in[_hill(imgLoc_si1_sj)],in[_loll(imgLoc_si_sj)]<<16|in[_loll(imgLoc_si1_sj)]),coeff);
                        
                        out[i*IMG_COLS +j] = outBi >> 8;
                    }
                    /* else */
                    /*     out[i*IMG_COLS +j] = 0; */
                    /* } */
                else
                    out[i*IMG_COLS +j] = 0;
            }
        }
    }
    


    end_time = _itoll(TSCH,TSCL);
    printf("cycle count:%lld\n", end_time-start_time);    

    /* Error_init(&eb); */
    /* task = Task_create(taskFxn, NULL, &eb); */
    /* if (task == NULL) { */
    /*     System_printf("Task_create() failed!\n"); */
    /*     BIOS_exit(0); */
    /* } */

    /* BIOS_start();     /\* enable interrupts and start SYS/BIOS *\/ */
    printf("exit main()\n");
}
