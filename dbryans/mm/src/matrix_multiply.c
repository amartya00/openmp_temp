#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include <ti/omp/omp.h>

#include <xdc/runtime/Timestamp.h>
#include <xdc/runtime/Types.h>

#include <c6x.h>
/* #include <stdint.h> */
typedef unsigned char dataType; //int8
//typedef unsigned short dataType;  //int16
//typedef unsigned long dataType;   //int32
//typedef float dataType;           //float32
//typedef double dataType;          //float64

#define SIZE 4000
#define A_BASE_ADDR 0x80000000
#define B_BASE_ADDR A_BASE_ADDR + sizeof(dataType)*(SIZE)
#define C_BASE_ADDR B_BASE_ADDR + sizeof(dataType)*(SIZE)

double timerval();

int main(int argc, char *argv[])
{
    int cores=8;
    int size=SIZE;
    Types_Timestamp64 timeIn, timeOut;    
    //printf("\n---matrix_multiply---");
    //printf("\ncores:\t%d",cores);
    //printf("\nsize:\t%d",size);
    uint64_t start_time, end_time;    
    omp_set_num_threads((unsigned int) cores);
    srand(time(NULL));
    int i,j;
    
    dataType *A,*B,*C;
    A=(dataType*)(A_BASE_ADDR);
    B=(dataType*)(B_BASE_ADDR);
    C=(dataType*)(C_BASE_ADDR);
    

    for (i=0;i<size;i++)
    {
        for (j=0;j<size;j++)
        {
            *(A+i*size+j)=(dataType)rand();
            //printf("%lu ",*(A+i*size+j));
        }
        *(B+i)=(dataType)rand();
        *(C+i)=0;
        //printf("\t%d\t%d\n\r",*(B+i),*(C+i));
    }

    start_time = _itoll(TSCH,TSCL);

    #pragma omp parallel private(i,j)
    {
#pragma omp for schedule(static, size/cores)
        for (i=0;i<size;i++)
        {
            for (j=0;j<size;j++)
            {
                *(C+i)+=(*(A+i*size+j))*(*(B+i));
            }
            //printf("mythread: %d\n\r",omp_get_thread_num());
        }
    }
    Timestamp_get64(&timeOut);
    //printf("\nsec:\t%f\n",runtime);
    
    /*for (i=0;i<size;i++)
    {
        printf("%d\n\r",*(C+i));
    }*/
    
    /* printf("Print this\n"); */
    /* printf("cycle count = %ld\n", ((long) _itoll(timeOut.hi, timeOut.lo) - (long) _itoll(timeIn.hi, timeIn.lo))); */
    /* printf("%d,%d\n",cores,size); */
    end_time = _itoll(TSCH,TSCL);
    printf("cycle count:%lld\n", end_time-start_time);
    
    /* free(C); */
    /* free(B); */
    /* free(A); */
    
    return 0;
}
/* double timerval() */
/* { */
/*     struct timeval st; */
/*     gettimeofday(&st, NULL); */
/*     return st.tv_sec + st.tv_usec * 1e-6; */
/* } */
