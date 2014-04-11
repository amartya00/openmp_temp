#include <stdio.h>
#include "man.h"
#include "img_write.h"
#include "bilinear.h"
// #include <math.h>

int main (int argc, char *argv[]){


    unsigned int out[NUM_COLS * NUM_ROWS] = {0};

    unsigned short theta = 0;

    theta = atoi(argv[1]);

    bilinear(in, (unsigned int)(NUM_COLS), (unsigned int) (NUM_ROWS), theta, out);
    img_write(out, 1024, 1024);
    return 0;
    
}
