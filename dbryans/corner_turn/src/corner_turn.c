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
#define SIZE 4000
#define A_BASE_ADDR 0x80000000
#define B_BASE_ADDR A_BASE_ADDR + sizeof(dataType)*(SIZE)


int main(int argc, char *argv[])
{
    int cores=1;
    int size=SIZE;
    Types_Timestamp64 timeIn, timeOut;
    
    omp_set_num_threads((unsigned int) cores);
    srand(time(NULL));
    int i,j;
    
    dataType *A,*B;
    A=(dataType*)(A_BASE_ADDR);
    B=(dataType*)(B_BASE_ADDR);
    
    for (i=0;i<size;i++)
    {
        for (j=0;j<size;j++)
        {
            *(A+i*size+j)=(dataType)rand();
            *(B+i*size+j)=0;
            //printf("%d ",*(A+i*size+j));
        }
        //printf("\n\r");
    }
    

    Timestamp_get64(&timeIn);
        #pragma omp parallel private(i,j)
    {
        #pragma omp for
        for (i=0;i<size;i++)
        {
            for (j=0;j<size;j++)
            {
                *(B+j*size+i)=*(A+i*size+j);
            }
            //printf("mythread: %d\n\r",omp_get_thread_num());
        }
    }
    Timestamp_get64(&timeOut);
    /*for (i=0;i<size;i++)
    {
        for (j=0;j<size;j++)
        {
            printf("%d ",*(B+i*size+j));
        }
        printf("\n\r");
    }*/
    printf("Print this\n");
    printf("cycle count = %ld\n", ((long) _itoll(timeOut.hi, timeOut.lo) - (long) _itoll(timeIn.hi, timeIn.lo)));
    printf("%d,%d\n",cores,size);
    

    return 0;
}
/* double timerval() */
/* { */
/*     struct timeval st; */
/*     gettimeofday(&st, NULL); */
/*     return st.tv_sec + st.tv_usec * 1e-6; */
/* } */
