#include <ti/omp/omp.h>

#include <string.h>
#include <assert.h>
#include <stdio.h>

#include <xdc/runtime/Timestamp.h>
#include <xdc/runtime/Types.h>

#include "cos.h"
#include "sin.h"

#define NTHREADS  (unsigned short) 8

void bilinear () {

    unsigned short i =0;
    unsigned short j =0;

    int itcos = 0;
    int itsin = 0;
    int it = 0;
    int jt = 0;
    int ir =0;
    int jr = 0;
    int sinTh = 0;
    int cosTh = 0;

    int w1 = 0; 
    int w2 = 0; 

    int si = 0;
    int sj = 0;


    unsigned int outBi;
    unsigned short chunkSize = 0;
    int nthreads;

    const unsigned char *in;
    unsigned short width = 1920;
    unsigned short height = 1080;
    unsigned short theta = 90;
    unsigned char *out;

    unsigned int delta    = 0;
    unsigned int timestamp = 0;

    nthreads = NTHREADS;
    omp_set_num_threads(nthreads);
    chunkSize = height/nthreads;

    sinTh = sin_16[theta];
    cosTh = cos_16[theta];

    in  = (unsigned char *)(0x82000000);
    out = (unsigned char *)(0x86000000);

    timestamp = Timestamp_get32();

#pragma omp parallel shared(in, out, width, height) private(i,j,jt, it, itcos, itsin, ir ,jr, si, sj)
    {
#pragma omp for schedule(static)
    for (i = 0; i < height -1; i++){
        for (j = 0; j < width -1; j++){
            it = (i - (height)/2);
            itcos = it * cosTh;
            itsin = it * sinTh;
            jt = (j - (width)/2);
            ir = itcos - jt * sinTh;
            jr = itsin + jt * cosTh;

            si = ir >> 8;
            sj = jr >> 8;
            si = si + height/2 -1;
            sj = sj + width/2 -1;
            out[i*width+j] = sj;

            if (si > 0 && si < height -1){
                if(sj >0 && sj < width -1){

                    w1 = (ir >> 8) & (0xF);
                    w2 = (ir >> 8) & (0xF);
                    outBi = (0xF - w1)*((0xF-w2)*in[si * width + sj] + w2*in[(si+1) * width + sj]) + w1*((0xF-w2)*in[si * width + sj +1] + w2*in[(si+1) * width + sj +1]);
                     out[i*width +j] = outBi >> 8;
                }
            }
            else
                out[i*width +j] = 0;
        }
        }
    }
    


    delta = Timestamp_get32() - timestamp;
    printf("\nexecution time: %0.2fms\n", (float)delta/1000000);
}

