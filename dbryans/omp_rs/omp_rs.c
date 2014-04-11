#include <stdio.h>
#include <stdlib.h>
#include <ti/omp/omp.h>
#include <time.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Timestamp.h>

#define DIGITS_AMOUNT   10    /* number of all possible keys (bucket's size) */
#define N 65536*8*8*8*8
#define K 5
#define DEBUG 0
#define THREADS 8


uint32_t tenPowers[10] = {
        1,              10,             100,
        1000,           10000,          100000,
        1000000,        10000000,       100000000,
        1000000000,
};

uint32_t p(int exp)
{
        return tenPowers[exp];
}

double time_elapsed(Types_Timestamp64 st, Types_Timestamp64 et, int i, char *s)
{
		double timestamp = 0;
		double delta=0;
        timestamp = ((long long)st.hi)<<32|st.lo;
        delta = ((long long)et.hi)<<32 | (et.lo);
        delta = delta - timestamp;
        printf("%d:ITR %s %f\n",i, s, (float)delta/1000000);
        return delta;
}

void radixsort_parallel(uint32_t *input_array, uint32_t input_array_size,
                                uint32_t max_digits_size)
{
	uint32_t digit=0;
	int f=0, i=0, j=0;
	int chunk=0;
    Types_Timestamp64 st;
	Types_Timestamp64 et;

	uint32_t *tmp= (uint32_t *)calloc(input_array_size,sizeof(uint32_t));

	if(tmp==NULL) {
		printf("Failled malloc (tmp)!! \n");
		exit(0);
	}

	int tmp_bucket[THREADS][DIGITS_AMOUNT];
	//int tmp_bucket[THREADS][DIGITS_AMOUNT];
	/*int **tmp_bucket;
	tmp_bucket = (int **)malloc(sizeof(uint32_t *)*THREADS);
	for(i=0;i<THREADS;i++)
		tmp_bucket[i] = (int *)malloc(sizeof(uint32_t )*DIGITS_AMOUNT);
*/

	/*for(i=0; i<THREADS; i++)
		for(f=0; f<DIGITS_AMOUNT*K; f++)
			tmp_bucket[i][f]=0;
*/

	chunk=input_array_size/THREADS;

		#pragma omp parallel private(i,f,j,digit) shared(tmp_bucket, input_array)
		{
			int th,pos,unit;
			th=omp_get_thread_num();
			int previous_offset=0;
			int offset[DIGITS_AMOUNT]={0};
			int thread_i=0;
			int local_offset[DIGITS_AMOUNT]={0};
			int global_counter[DIGITS_AMOUNT]={0};
			uint32_t element=0;

/*			#pragma omp for schedule(static, chunk)
			for (i=0; i<N; i++) {
				element = input_array[i];
				for(j=0;j<max_digits_size;j++) {
					f=element/p(j)%DIGITS_AMOUNT; //access array
					tmp_bucket[th][j*DIGITS_AMOUNT + f]++;
				}
			}
*/

		for (j=0; j<max_digits_size; j++) {
			digit = p(j);

			for(f=0; f<DIGITS_AMOUNT; f++)
				  tmp_bucket[th][f]=0;

	      /*  Timestamp_get64(&st);*/

			#pragma omp for schedule(static, chunk)
			 for (i=0; i<N; i++) {
				f=input_array[i]/digit%DIGITS_AMOUNT; //access array
				tmp_bucket[th][f]++;
			}

		/*    Timestamp_get64(&et);
		    time_elapsed(st,et,j,"Shared Bucket");
		    Timestamp_get64(&st);*/

			for(i=0;i<DIGITS_AMOUNT;i++){
				global_counter[i]=0;
				for(thread_i=0; thread_i<THREADS; thread_i++){
					if(thread_i == th){
						local_offset[i] = global_counter[i];
					}
					global_counter[i]+=tmp_bucket[thread_i][i];
				}
			}

		 /*   Timestamp_get64(&et);
		    time_elapsed(st,et,j,"Global Offset");
		    Timestamp_get64(&st);*/

			previous_offset=0;
			//int offset[DIGITS_AMOUNT]={0};
			offset[0]=local_offset[0];

			for(i=1;i<DIGITS_AMOUNT;i++){
				previous_offset+=global_counter[i-1];
				offset[i]=previous_offset + local_offset[i];
			}

		 /*   Timestamp_get64(&et);
		    time_elapsed(st,et,j,"Local Offset");
		    Timestamp_get64(&st);*/

			#pragma omp for schedule(static, chunk)
			for(i=0;i<N;i++){
				element = input_array[i];
				unit = element/digit%DIGITS_AMOUNT;
				pos=offset[unit]++;
				tmp[pos]=element; // access array
			}

		/*    Timestamp_get64(&et);
		    time_elapsed(st,et,j,"Radix Sort");
		    Timestamp_get64(&st);*/

			#pragma omp for schedule(static, chunk)
			for(i=0;i<N;i++)
					input_array[i]=tmp[i];    //access array

		  /*  Timestamp_get64(&et);
		    time_elapsed(st,et,j,"Swap Array"); */

		}

/*
		if(j%2 == 0) {
			input_array=buffer;
			tmp=in_array;
		}
		else {
			tmp=buffer;
			input_array=in_array;
		}
		*/
}
/*
if(j%2!=0)
	for(i=0;i<input_array_size;i++)
		in_array[i]=buffer[i];
*/
        free(tmp);
}

int main()
{
        uint32_t i, *input, num_of_values = N, max_value = 0, tmp_value = 0;
        int value_length = K, max_digits_size = 0;
        char str[10] = {0};

        Types_Timestamp64 st;
    	Types_Timestamp64 et;
    	double timestamp = 0;
    	double delta=0;

        omp_set_num_threads(THREADS);

        /* allocation of memory */
        input = (uint32_t *)calloc(num_of_values,sizeof(uint32_t));
        if (!input) {
                printf("ERROR: not enough memory!\n");
                return 1;
        }

        for(i=0;i<value_length;i++)
                str[i] = '9';
        srand(time(NULL));
        for(i=0;i<num_of_values; i++) {
                input[i] = rand() % strtoul(str,NULL,10) + 1;
                if (max_value < input[i])
                        max_value = input[i];
        }

        tmp_value = max_value;
        while((tmp_value/=10)>0)
                max_digits_size++;
        max_digits_size++;
/*
        printf("\n");
        printf("Max_digit = %d\n", max_digits_size);
        for(i=0;i<N;i++)
        	printf("%u ", input[i]);
        printf("\n");
*/
        Timestamp_get64(&st);
        radixsort_parallel(input, num_of_values, max_digits_size);

        Timestamp_get64(&et);
        timestamp = ((long long)st.hi)<<32|st.lo;
        delta = ((long long)et.hi)<<32 | (et.lo);
        delta = delta - timestamp;

        printf("Time taken %f for RS N=%d\n", (float)delta/1000000, N);

        /* check values order */
        int not_ordered = 0;
        for (i=1; i<num_of_values; i++) {
                if (input[i]<input[i-1]) {
                        not_ordered = 1;
                        break;
                }
        }
        if (not_ordered) {
                printf("ORDERED CHECK: FAIL!\n");
        } else {
                printf("ORDERED CHECK: PASS\n");
        }

      //  free(input);
/*
        for(i=0;i<N;i++)
        	printf("%u ", input[i]);
        printf("\n");
*/
        return 0;
}
