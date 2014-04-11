#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ti/omp/omp.h>

#include <xdc/runtime/Timestamp.h>
#include <xdc/runtime/Types.h>

#include <c6x.h>
/* #include <stdint.h> */

typedef unsigned char dataType;   //int8
//typedef unsigned short dataType;  //int16
//typedef unsigned long dataType;   //int32
//typedef float dataType;           //float32
//typedef double dataType;            //float64

#define CHANNELS 250
#define LENGTH 320
#define WIDTH 320

#define S_BASE_ADDR 0x80000000
#define AVG_BASE_ADDR S_BASE_ADDR + (sizeof(dataType))*(CHANNELS)*(LENGTH)*(WIDTH)

int main(int argc, char *argv[])
{
    int cores=1;
    int channels=CHANNELS;
    int length=LENGTH;
    int width=WIDTH;
    /* int channels=10; */
    /* int length=480; */
    /* int width=480; */
    Types_Timestamp64 timeIn, timeOut;
    uint64_t start_time, end_time;
    
    omp_set_num_threads((unsigned int) cores);

    int i,j,k;

    dataType *avg;
    dataType *s;
    s=(dataType*)(S_BASE_ADDR);
    avg=(dataType*)(AVG_BASE_ADDR);

    dataType z1,z2,z3;

    for(k=0; k<channels; k++){
        for(i=0; i<length; i++){
            for(j=0; j<width; j++){
                *(s+ k*length*width + i*width + j)=(dataType)rand();
                //printf("s[%d][%d][%d]: %d \n \r",i,j,k,*(s+ k*length*width + i*width + j));
            }
        }
    }

    /* Timestamp_get64(&timeIn); */
    /* unsigned int  start = Timestamp_get32(); */
    start_time = _itoll(TSCH,TSCL);

    #pragma omp parallel private(k,i,j)
    {
#pragma omp for schedule(static, cores/channels)
      for(k=0; k<channels; k++){
       for(i=1; i<length; i++){
           for(j=0; j<width-1; j++){
               //printf("i: %d j: %d k: %d \r \n", i,j,k);
               //checking for boundary conditions
               //printf("s[%d][%d][%d]: %f \n ",i,j,k,*(s+ k*length*width + i*width + j));
               //checking z-band boundaries
               if(k<4){
                   //checking vertical boundaries
                   if(i==0){
                       if(j==0){
                           *(avg+ k*length*width + i*width + j) = *(s+ k*length*width + i*width + j) ;
                           if(k==0){
                               z1=0;
                               z2=0;
                               z3=0;
                           }
                           else if(k==1){
                               z1= *(s+ (k-1)*length*width + i*width + j) ;
                               z2=0;
                               z3=0;
                           }
                           else if(k==2){
                               z1= *(s+ (k-1)*length*width + i*width + j) ;
                               z2= *(s+ (k-2)*length*width + i*width + j) ;
                               z3=0;
                           }
                           else if(k==3){
                               z1= *(s+ (k-1)*length*width + i*width + j) ;
                               z2= *(s+ (k-2)*length*width + i*width + j) ;
                               z3= *(s+ (k-3)*length*width + i*width + j) ;
                           }
                       }
                       else{
                           *(avg+ k*length*width + i*width + j) = (*(s+ k*width*length + i*width + j) + *(s+ k*length*width + i*width + (j-1)) )/2;
                           if(k==0){
                               z1=0;
                               z2=0;
                               z3=0;
                           }
                           else if(k==1){
                               z1=  (*(s+ (k-1)*length*width + i*width + j) + *(s+ (k-1)*length*width + i*width + (j-1)))/2;
                               z2=0;
                               z3=0;
                           }
                           else if(k==2){
                               z1= (*(s+ (k-1)*length*width + i*width + j) + *(s+ (k-1)*length*width + i*width + (j-1)))/2;
                               z2= (*(s+ (k-2)*length*width + i*width + j) + *(s+ (k-2)*length*width + i*width + (j-1)))/2;
                               z3=0;
                           }
                           else if(k==3){
                               z1= (*(s+ (k-1)*length*width + i*width + j) + *(s+ (k-1)*length*width + i*width + (j-1)))/2;
                               z2= (*(s+ (k-2)*length*width + i*width + j) + *(s+ (k-2)*length*width + i*width + (j-1)))/2;
                               z3= (*(s+ (k-3)*length*width + i*width + j) + *(s+ (k-3)*length*width + i*width + (j-1)))/2;
                           }

                       }
                   }
                   else if(j!=width-1){
                       if(j==0){
                           *(avg+ k*length*width + i*width + j)= (*(s+ k*length*width + i*width + j) + *(s+ k*length*width + (i-1)*width + j) + *(s+ k*length*width + (i-1)*width + (j+1)))/3;

                           if(k==0){
                               z1=0;
                               z2=0;
                               z3=0;
                           }
                           else if(k==1){
                               z1= (*(s+ (k-1)*length*width + i*width + j) + *(s+ (k-1)*length*width + (i-1)*width + j) + *(s+ (k-1)*length*width + (i-1)*width + (j+1)))/3;
                               z2=0;
                               z3=0;
                           }
                           else if(k==2){
                               z1= (*(s+ (k-1)*length*width + i*width + j) + *(s+ (k-1)*length*width + (i-1)*width + j) + *(s+ (k-1)*length*width + (i-1)*width + (j+1)))/3;
                               z2= (*(s+ (k-2)*length*width + i*width + j) + *(s+ (k-2)*length*width + (i-1)*width + j) + *(s+ (k-2)*length*width + (i-1)*width + (j+1)))/3;
                               z3=0;
                           }
                           else if(k==3){
                               z1= (*(s+ (k-1)*length*width + i*width + j) + *(s+ (k-1)*length*width + (i-1)*width + j) + *(s+ (k-1)*length*width + (i-1)*width + (j+1)))/3;
                               z2= (*(s+ (k-2)*length*width + i*width + j) + *(s+ (k-2)*length*width + (i-1)*width + j) + *(s+ (k-2)*length*width + (i-1)*width + (j+1)))/3;
                               z3= (*(s+ (k-3)*length*width + i*width + j) + *(s+ (k-3)*length*width + (i-1)*width + j) + *(s+ (k-3)*length*width + (i-1)*width + (j+1)))/3;
                           }

                       }
                       else{
                           *(avg+ k*length*width + i*width + j)= (*(s+ k*length*width + i*width + j) + *(s+ k*length*width + (i-1)*width + j) + *(s+ k*length*width + (i-1)*width + (j-1)) + *(s+ k*length*width + i*width + (j-1)) + *(s+ k*length*width + (i-1)*width + (j+1)))/5;

                          if(k==0){
                               z1=0;
                               z2=0;
                               z3=0;
                           }
                           else if(k==1){
                               z1=  (*(s+ (k-1)*length*width + i*width + j) + *(s+ (k-1)*length*width + (i-1)*width + j) + *(s+ (k-1)*length*width + (i-1)*width + (j-1)) + *(s+ (k-1)*length*width + i*width + (j-1)) + *(s+ (k-1)*length*width + (i-1)*width + (j+1)))/5;
                               z2=0;
                               z3=0;
                           }
                           else if(k==2){
                               z1= (*(s+ (k-1)*length*width + i*width + j) + *(s+ (k-1)*length*width + (i-1)*width + j) + *(s+ (k-1)*length*width + (i-1)*width + (j-1)) + *(s+ (k-1)*length*width + i*width + (j-1)) + *(s+ (k-1)*length*width + (i-1)*width + (j+1)))/5;
                               z2= (*(s+ (k-2)*length*width + i*width + j) + *(s+ (k-2)*length*width + (i-1)*width + j) + *(s+ (k-2)*length*width + (i-1)*width + (j-1)) + *(s+ (k-2)*length*width + i*width + (j-1)) + *(s+ (k-2)*length*width + (i-1)*width + (j+1)))/5;
                               z3=0;
                           }
                           else if(k==3){
                               z1= (*(s+ (k-1)*length*width + i*width + j) + *(s+ (k-1)*length*width + (i-1)*width + j) + *(s+ (k-1)*length*width + (i-1)*width + (j-1)) + *(s+ (k-1)*length*width + i*width + (j-1)) + *(s+ (k-1)*length*width + (i-1)*width + (j+1)))/5;
                               z2= (*(s+ (k-2)*length*width + i*width + j) + *(s+ (k-2)*length*width + (i-1)*width + j) + *(s+ (k-2)*length*width + (i-1)*width + (j-1)) + *(s+ (k-2)*length*width + i*width + (j-1)) + *(s+ (k-2)*length*width + (i-1)*width + (j+1)))/5;
                               z3= (*(s+ (k-3)*length*width + i*width + j) + *(s+ (k-3)*length*width + (i-1)*width + j) + *(s+ (k-3)*length*width + (i-1)*width + (j-1)) + *(s+ (k-3)*length*width + i*width + (j-1)) + *(s+ (k-3)*length*width + (i-1)*width + (j+1)))/5;
                           }
                       }


                   }
                   else {
                        *(avg+ k*length*width + i*width + j)= (*(s+ k*length*width + i*width + j) + *(s+ k*length*width + (i-1)*width + j) + *(s+ k*length*width + (i-1)*width + (j-1)) + *(s+ k*length*width + i*width + (j-1)))/4;

                           if(k==0){
                               z1=0;
                               z2=0;
                               z3=0;
                           }
                           else if(k==1){
                               z1= (*(s+ (k-1)*length*width + i*width + j) + *(s+ (k-1)*length*width + (i-1)*width + j) + *(s+ (k-1)*length*width + (i-1)*width + (j-1)) + *(s+ (k-1)*length*width + i*width + (j-1)))/4;
                               z2=0;
                               z3=0;
                           }
                           else if(k==2){
                               z1= (*(s+ (k-1)*length*width + i*width + j) + *(s+ (k-1)*length*width + (i-1)*width + j) + *(s+ (k-1)*length*width + (i-1)*width + (j-1)) + *(s+ (k-1)*length*width + i*width + (j-1)))/4;
                               z2= (*(s+ (k-2)*length*width + i*width + j) + *(s+ (k-2)*length*width + (i-1)*width + j) + *(s+ (k-2)*length*width + (i-1)*width + (j-1)) + *(s+ (k-2)*length*width + i*width + (j-1)))/4;
                               z3=0;
                           }
                           else if(k==3){
                               z1= (*(s+ (k-1)*length*width + i*width + j) + *(s+ (k-1)*length*width + (i-1)*width + j) + *(s+ (k-1)*length*width + (i-1)*width + (j-1)) + *(s+ (k-1)*length*width + i*width + (j-1)))/4;
                               z2= (*(s+ (k-2)*length*width + i*width + j) + *(s+ (k-2)*length*width + (i-1)*width + j) + *(s+ (k-2)*length*width + (i-1)*width + (j-1)) + *(s+ (k-2)*length*width + i*width + (j-1)))/4;
                               z3= (*(s+ (k-3)*length*width + i*width + j) + *(s+ (k-3)*length*width + (i-1)*width + j) + *(s+ (k-3)*length*width + (i-1)*width + (j-1)) + *(s+ (k-3)*length*width + i*width + (j-1)))/4;
                           }
                   }

               }

               else{
                   if(i==0){
                       if(j==0){
                           *(avg+ k*length*width + i*width + j) = *(s+ k*length*width + i*width + j) ;

                               z1= *(s+ (k-1)*length*width + i*width + j) ;
                               z2= *(s+ (k-2)*length*width + i*width + j) ;
                               z3= *(s+ (k-3)*length*width + i*width + j) ;

                       }
                       else{
                           *(avg+ k*length*width + i*width + j)= (*(s+ k*length*width + i*width + j) + *(s+ k*length*width + i*width + j-1))/2;

                               z1= (*(s+ (k-1)*length*width + i*width + j) + *(s+ (k-1)*length*width + i*width + j-1))/2;
                               z2= (*(s+ (k-2)*length*width + i*width + j) + *(s+ (k-2)*length*width + i*width + j-1))/2;
                               z3= (*(s+ (k-3)*length*width + i*width + j) + *(s+ (k-3)*length*width + i*width + j-1))/2;


                       }
                   }
                   else if(j!=width-1){
                       if(j==0){
                           *(avg+ k*length*width + i*width + j)= ( *(s+ k*length*width + i*width + j) + *(s+ k*length*width + (i-1)*width + j) + *(s+ k*length*width + (i-1)*width + j+1))/3;


                            z1= ( *(s+ (k-1)*length*width + i*width + j) + *(s+ (k-1)*length*width + (i-1)*width + j) + *(s+ (k-1)*length*width + (i-1)*width + j+1))/3;
                            z2= ( *(s+ (k-2)*length*width + i*width + j) + *(s+ (k-2)*length*width + (i-2)*width + j) + *(s+ (k-2)*length*width + (i-1)*width + j+1))/3;
                            z3= ( *(s+ (k-3)*length*width + i*width + j) + *(s+ (k-3)*length*width + (i-3)*width + j) + *(s+ (k-3)*length*width + (i-1)*width + j+1))/3;


                       }
                       else{
                           *(avg+ k*length*width + i*width + j)= (*(s+ k*length*width + i*width + j) + *(s+ k*length*width + (i-1)*width + j) + *(s+ k*length*width + (i-1)*width + (j-1)) + *(s+ k*length*width + i*width + (j-1)) + *(s+ k*length*width + (i-1)*width + (j+1)))/5;


                            z1= (*(s+ (k-1)*length*width + i*width + j) + *(s+ (k-1)*length*width + (i-1)*width + j) + *(s+ (k-1)*length*width + (i-1)*width + (j-1)) + *(s+ (k-1)*length*width + i*width + (j-1)) + *(s+ (k-1)*length*width + (i-1)*width + (j+1)))/5;
                            z2= (*(s+ (k-2)*length*width + i*width + j) + *(s+ (k-2)*length*width + (i-1)*width + j) + *(s+ (k-2)*length*width + (i-2)*width + (j-1)) + *(s+ (k-2)*length*width + i*width + (j-1)) + *(s+ (k-2)*length*width + (i-1)*width + (j+1)))/5;
                            z3= (*(s+ (k-3)*length*width + i*width + j) + *(s+ (k-3)*length*width + (i-1)*width + j) + *(s+ (k-3)*length*width + (i-1)*width + (j-1)) + *(s+ (k-3)*length*width + i*width + (j-1)) + *(s+ (k-3)*length*width + (i-1)*width + (j+1)))/5;

                       }


                   }
                   else {
                        *(avg+ k*length*width + i*width + j)= (*(s+ k*length*width + i*width + j) + *(s+ k*length*width + (i-1)*width + j) + *(s+ k*length*width + (i-1)*width + (j-1)) + *(s+ k*length*width + i*width + (j-1)))/4;

                        z1= (*(s+ (k-1)*length*width + i*width + j) + *(s+ (k-1)*length*width + (i-1)*width + j) + *(s+ (k-1)*length*width + (i-1)*width + (j-1)) + *(s+ (k-1)*length*width + i*width + (j-1)))/4;
                        z2= (*(s+ (k-2)*length*width + i*width + j) + *(s+ (k-2)*length*width + (i-1)*width + j) + *(s+ (k-2)*length*width + (i-1)*width + (j-1)) + *(s+ (k-2)*length*width + i*width + (j-1)))/4;
                        z3= (*(s+ (k-3)*length*width + i*width + j) + *(s+ (k-3)*length*width + (i-1)*width + j) + *(s+ (k-3)*length*width + (i-1)*width + (j-1)) + *(s+ (k-3)*length*width + i*width + (j-1)))/4;

                   }

               }


              //printf("Value at s[%d][%d][%d]: %f  \n \r",i,j,k,*(s+ k*length*width + i*width + j));
              //printf("avg[%d][%d][%d]: %f \n \r",i,j,k,*(avg+ k*length*width + i*width + j));
              //printf("%f \n",(float)*(avg+ k*length*width + i*width + j));
              //printf("z1[%d][%d][%d]: %f \r \n ",i,j,k,z1);
              //printf("z2[%d][%d][%d]: %f \r \n ",i,j,k,z2);
              //printf("z3[%d][%d][%d]: %f \r \n ",i,j,k,z3);
           }
       }
    }
    }
    
    /* Timestamp_get64(&timeOut); */
    /* unsigned int end = Timestamp_get32(); */
    /* printf("cycle count = %ld\n", ((long long) _itoll(timeOut.hi, timeOut.lo) - (long long) _itoll(timeIn.hi, timeIn.lo))); */

    /* printf("cycle 32 count %d-%d = %d\n", end,start,end-start); */
    end_time = _itoll(TSCH,TSCL);
    printf("cycle count:%lld\n", end_time-start_time);

    return 0;

}
/* double timerval() */
/* { */
/*     struct timeval st; */
/*     gettimeofday(&st, NULL); */
/*     return st.tv_sec + st.tv_usec * 1e-6; */
/* } */

