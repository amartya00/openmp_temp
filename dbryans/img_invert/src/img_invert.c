#include <stdio.h>

void img_invert(unsigned char *in, unsigned short width, unsigned short height, unsigned char *out){

    unsigned short i = 0;
    unsigned short j = 0;
    
    for (i = 0; i < height; i++){
        for (j = 0; j < width; j++){
            out[i*width + j] = 255 - in[i*width +j];
        }
    }
}
