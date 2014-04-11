#include <stdio.h>
#include "1080p_soccer.h"
//#include "man.h"
#include "img_write.h"
// #include "bilinear.h"
// #include "omp.h"
#include <sys/time.h>
#include <time.h>
#include <math.h>

#include "test.h"
// #define NTHREADS  8

double timerval () {
    struct timeval st;
    gettimeofday(&st, NULL);
    return (st.tv_sec+st.tv_usec*1e-6);
}

double totaltimesec (double start, double stop) {
    return (stop-start);
}

int main (int argc, char *argv[]){
  
  // int nthreads;
  // nthreads = NTHREADS;
  // omp_set_num_threads(nthreads);
    double startTime = 0;
    double endTime = 0;

    float timeSerial = 0;
    float timeOmp = 0;

    unsigned int imgOut[NUM_COLS * NUM_ROWS] = {0};
    unsigned int imgOutOmp[NUM_COLS * NUM_ROWS] = {0};

    unsigned short theta = 0;

    float rad = 0;

    theta = atoi(argv[1]);
    rad = (theta*(M_PI))/180;

    startTime = timerval();
    //bilinear_omp(imgIn, (unsigned int)(NUM_COLS), (unsigned int) (NUM_ROWS), rad, imgOutOmp);
    
    endTime = timerval();
    printf (" \nelapsed time OMP in seconds: %.8f\n", timeOmp = (endTime - startTime));

    /* startTime = timerval(); */
    /* //bilinear(imgIn, (unsigned int)(NUM_COLS), (unsigned int) (NUM_ROWS), rad, imgOut); */
    /* endTime = timerval(); */
    /* printf (" \nelapsed time in seconds: %.8f\n", timeSerial = (endTime - startTime)); */
    
    /* printf("\nspeed up: %0.2f\n", (timeSerial)/(timeOmp)); */
    /* img_write(imgIn, NUM_COLS, NUM_ROWS); */

    return 0;
}

