#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <xdc/runtime/Types.h>
#include <xdc/runtime/Timestamp.h>

#define DIGITS_AMOUNT   10    /* number of all possible keys (bucket's size) */
#define N 65536*8*4
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

uint32_t shared_buckets[K][DIGITS_AMOUNT];

void radixsort(uint32_t *input_array, uint32_t * tmp,
                                uint32_t max_digits_size)
{
		uint32_t digit;
	    int f, i, j;

	    for (i=0; i<N; i++) {

	        for (j=0; j<max_digits_size; j++) {
	            digit = p(j);

	            f=input_array[i]/digit%DIGITS_AMOUNT;
	            shared_buckets[j][f]++;
	        }
	    }

	    for (j=0; j<max_digits_size; j++) {
	        for (i=1; i<DIGITS_AMOUNT; i++)
	            shared_buckets[j][i]+=shared_buckets[j][i-1];
	    }

	    for (j=0; j<max_digits_size; j++) {
	        digit = p(j);

	        for(i=N-1;i>=0;i--) {
	            int unit = input_array[i]/digit%DIGITS_AMOUNT;
	            int pos = --shared_buckets[j][unit];
	            tmp[pos]=input_array[i];
	        }

	        for(i=0;i<N;i++)
	            input_array[i]=tmp[i];
	    }
}

int main()
{
        uint32_t i,j, *input, max_value = 0, tmp_value = 0;
        int value_length = K, max_digits_size = 0;
        char str[10] = {0};
        uint32_t *tmp;

        Types_Timestamp64 st;
    	Types_Timestamp64 et;
    	double timestamp = 0;
    	double delta=0;

        /* allocation of memory */
        input = (uint32_t *)calloc(N,sizeof(uint32_t));
        if (!input) {
                printf("ERROR: not enough memory!\n");
                return 1;
        }

	    tmp = (uint32_t *)calloc(N, sizeof(uint32_t));
	    if (tmp==NULL) {
	        printf("ERROR: not enough memory!\n");
	        abort();
	    }

	    for(i=0; i<K; i++)
	    	for(j=0; j<DIGITS_AMOUNT; j++)
	    		shared_buckets[i][j]=0;

        for(i=0;i<value_length;i++)
                str[i] = '9';
        srand(time(NULL));
        for(i=0;i<N; i++) {
                input[i] = rand() % strtoul(str,NULL,10) + 1;
                if (max_value < input[i])
                        max_value = input[i];
        }

        tmp_value = max_value;
        while((tmp_value/=10)>0)
                max_digits_size++;
        max_digits_size++;


        Timestamp_get64(&st);
        radixsort(input, tmp, max_digits_size);

        Timestamp_get64(&et);
        timestamp = ((long long)st.hi)<<32|st.lo;
        delta = ((long long)et.hi)<<32 | (et.lo);
        delta = delta - timestamp;

        printf("Time taken %f for RS N=%d\n", (float)delta/1000000, N);

        /* check values order */
        int not_ordered = 0;
        for (i=1; i<N; i++) {
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

        return 0;
}

