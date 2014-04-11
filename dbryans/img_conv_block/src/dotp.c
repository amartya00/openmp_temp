#include "dotp.h"

unsigned int dotp(unsigned short *restrict a, unsigned short *restrict b) {

    int i, sum1 = 0, sum2 = 0;

    for (i = 0; i < FEATURE_SIZE; i++) {
        /* sum1 = sum1 + _mpy (_amem4_const(&a[i]), _amem4_const(&b[i])); */
        /* sum2 = sum2 + _mpyh(_amem4_const(&a[i]), _amem4_const(&b[i])); */
        sum1 += a[i] * b[i];
    }
    /* return sum1 + sum2; */
    return sum1;
}
