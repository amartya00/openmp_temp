#include <stdio.h>
#include <stdlib.h>
#include <xdc/runtime/Timestamp.h>
#include <xdc/runtime/Types.h>
#include <ti/omp/omp.h>

#define NTHREADS 8
#define SIZE 512

#define DEBUG 0

int main ()
{
    int i, j, k, N = SIZE;
    float  **a, **b, **c;
    Types_Timestamp64 st;
    Types_Timestamp64 et;
    long long timestamp = 0;
    long long delta=0;
    int th = omp_get_max_threads();
    int chunk = SIZE/th;
    float sum=0;
    float CH=0;

    N=SIZE;
    a = (float**)malloc(sizeof(float *)*SIZE);
    b = (float**)malloc(sizeof(float *)*SIZE);
    c = (float**)malloc(sizeof(float *)*SIZE);

    if(a==NULL || b == NULL || c == NULL)
    {
    	printf("MALLOC FAILED 1\n");
    	abort();
    }

    for (i=0; i<N; i++){
            a[i]= (float*)malloc(sizeof(float)*SIZE);
            b[i]= (float*)malloc(sizeof(float)*SIZE);
            c[i]= (float*)malloc(sizeof(float)*SIZE);
            if(a[i] == NULL || b[i] == NULL || c[i]==NULL)
            {
            	printf("MALLOC FAILED 2\n");
            	abort();
            }
    }


    float sgn[2]={1,-1};
    for (i=0; i<N; i++)
        for (j=0; j<N; j++){
        	a[i][j] = sgn[rand()%2]*(float)(rand()%SIZE)*8/11;//1;
        	b[i][j] = sgn[rand()%2]*(float)(rand()%SIZE)*9/11;//1;
        	c[i][j] = 0;
        }

    Timestamp_get64(&st);
#pragma omp parallel shared(a,b,c) private(i,j,k)
   {
#pragma omp for schedule(static, chunk) private(sum)
    for (i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++){
        	sum=0;
            for (k=0; k<SIZE; k++)
            	sum+=a[i][k]*b[k][j];
            	c[i][j]=sum;
            }

    }
   }
	Timestamp_get64(&et);
	timestamp = ((long long)st.hi)<<32|st.lo;
	delta = ((long long)et.hi)<<32 | (et.lo);
	delta = delta - timestamp;

	int row=rand()%SIZE;
    int col=rand()%SIZE;
    for (k=0; k<SIZE; k++)
          CH+= a[row][k]* b[k][col];

    if(c[row][col] == CH)
    	printf("Matrix checked for random index\n");
    else
    	printf("Matrix check FAILED for random index\n");

    printf("Matrix Multiplication N=%d: Time=%f\n", SIZE, (float)delta/1000000);

    free(a); free(b); free(c);

    return 0;
}
