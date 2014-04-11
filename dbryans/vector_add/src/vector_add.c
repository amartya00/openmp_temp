#include <stdio.h>

#define DDR3_BASE_ADDR 0x80000000
#define SIZE 0x10000
#define A_ADDRESS DDR3_BASE_ADDR
#define B_ADDRESS A_ADDRESS + (SIZE) * 4
#define C_ADDRESS B_ADDRESS + (SIZE) * 4

int main(void){

    // unsigned int a[SIZE] = {0};
    // unsigned int b[SIZE] = {0};
    // unsigned int c[SIZE] = {0};
    unsigned int *a;
    unsigned int *b;
    unsigned int *c;
    unsigned int i = 0;

    a = (unsigned int *)A_ADDRESS;
    b = (unsigned int *)B_ADDRESS;

    c = (unsigned int *)C_ADDRESS;

    printf("Address of a: %.8X, b: %.8X, c: %.8X\n", a, b, c);
    printf("Initializing arrays and performing vector add\n");
    for (i = 0; i < SIZE; i++){
    a[i] = i;
    b[i] = i;
    c[i] = a[i] + b[i];
    }
    
    printf("vector add done random check %d (a[2000]) + %d (b[2000]) = %d (c[2000])\n", a[2000], b[2000], c[2000]);
    return 0;

}
