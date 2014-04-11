#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ti/omp/omp.h>

#include <xdc/runtime/Timestamp.h>
#include <xdc/runtime/Types.h>

typedef unsigned char dataType; //int8
//typedef unsigned short dataType;  //int16
//typedef unsigned long dataType;   //int32
//typedef float dataType;           //float32
//typedef double dataType;          //float64

double timerval();

#define X_BASE_ADDR 0x80000000

void dwt(int cores, int size)
{
    //this is an inline 5/3 Legall filter DWT using the lifting method
    //the high pass is calculated first, then the low pass
    //there are 5 lifting levels (not 3) by Le Gall's design
    //odd values updated, then even values updated

    --size; //index from 0, not 1
    int parity = size%2;
    int i;

    dataType *x;
    x = (dataType*)(X_BASE_ADDR);
    
    for(i=0;i<size;++i)
    {
        *(x+i)=(dataType)rand();
    }
    
    //int d[size/2];    //non-inline version
    //int s[size/2];
    
    //high pass
    #pragma omp parallel private(i)
    {
        #pragma omp for
        for(i = 1; size > i; i += 2)
        {
            //any decent compiler should optimize the n/2 to n>>1
            x[i] = x[i] - (x[i-1] + x[i+1])/2;
            //d[(i-1)/2] = x[i] - (x[i-1] + x[i+1])/2;
        }
    }

    //symmetric reflection for first input
    //first input is 0th case (even) - so only high-pass done
    x[0] += x[1]/2;

    //symmetric reflection for last input
    if(parity)
    {
        x[size] = x[size] - x[size-1];  //odd (high) case
    }
    else
    {
        x[size] += x[size-1]/2;     //even (low) case
    }

    //low pass
    #pragma omp parallel private(i)
    {
        #pragma omp for
        for(i = 2; size > i; i += 2)
        {
            x[i] = x[i] + (x[i-1] + x[i+1])/4;
            //s[i/2] = x[i] + (x[i-1] + x[i+1])/4;
        }
    }

}

int main(int argc, const char *argv[])
{
    int cores=8;
    int size_input=480;
    //create 2D image of dimensions size_input x size_input
    int size=size_input*size_input;
    
    omp_set_num_threads((unsigned int) cores);

    int i,j;
    

    //double start = timerval();
    double start = Timestamp_get32();
    dwt(cores,size);
    double end = Timestamp_get32();
    double runtime = end-start;
    
    printf("%d,%d,%f\n",cores,size_input,runtime);

    //free(A);
    return 0;
}

/* double timerval() */
/* { */
/*     struct timeval st; */
/*     gettimeofday(&st, NULL); */
/*     return st.tv_sec + st.tv_usec * 1e-6; */
/* } */
