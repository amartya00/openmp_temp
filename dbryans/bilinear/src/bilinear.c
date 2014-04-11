#include <stdio.h>
// #include <math.h>
#include <stdlib.h>

#include "cos.h"
#include "sin.h"

void bilinear (const unsigned char *in, unsigned short width, unsigned short height, unsigned short theta, unsigned char *out) {

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

    sinTh = sin_16[theta];
    cosTh = cos_16[theta];

    unsigned int outBi;

    // printf("theta:%f, cosTh: %f, sinTh: %f", theta, cosTh, sinTh);

    for (i = 0; i < height -1; i++){
        
        it = (i - (height)/2);
        itcos = it * cosTh;
        itsin = it * sinTh;

        for (j = 0; j < width -1; j++){
            jt = (j - (width)/2);
            ir = itcos - jt * sinTh;
            jr = itsin + jt * cosTh;
            
            // printf("\nj:%d",j);
            // printf("\nir:%f\njr:%f\n", ir, jr);

            si = ir >> 8;
            sj = jr >> 8;
            si = si + height/2 -1;
            sj = sj + width/2 -1;

            // if (ir > height -1) ir = height - 1;
            // else if (ir < 0) ir = 0;

            // if (jr > width -1) jr = width -1 ;
            // else if (jr < 0) jr = 0;

            if (si > 0 && si < height -1){
                if(sj >0 && sj < width -1){

                    w1 = (ir >> 8) & (0xF);
                    w2 = (ir >> 8) & (0xF);
                    outBi = (0xF - w1)*((0xF-w2)*in[si * width + sj] + w2*in[(si+1) * width + sj]) + w1*((0xF-w2)*in[si * width + sj +1] + w2*in[(si+1) * width + sj +1]);
                    // out[i * width + j] = in[i * width +j];
                    // out[i * width + j] = in[si * width + sj];
                     out[i*width +j] = outBi >> 8;
                }
            }
            else
                out[i*width +j] = 0;

            // out[i*width +j] = out[i*width +j] >> 16;
            
            // si = (ir);
            // sj = (jr);

            // w1 = jr - sj;
            // w2 = ir - si;
            // out[i * width + j] = (1 - w1)*((1-w2)*in[si * width + sj] + w2*in[(si+1) * width + sj]) + w1*((1-w2)*in[si * width + sj +1] + w2*in[(si+1) * width + sj +1]);
            // out[i * width + j] = in[i * width +j];
            // out[i * width + j] = in[si * width + sj];
        }
    }

}

