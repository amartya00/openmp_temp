#include <stdio.h>
#include <math.h>

// #define PI 3.14

int main(void) {

    unsigned int i =0;
    float omega = 0;
    float cos16 = 0;
    float sin16 = 0;

    int cosVal = 0;
    int sinVal = 0;

    printf("int sin_16[360] = {");

    for (i = 0; i < 360; i++) {
        omega = (i * M_PI)/180;
        cos16 = cos(omega) * 65536;
        sin16 = sin(omega) * 65536;
        cosVal = cos16;
        sinVal = sin16;
        printf("%d,", sinVal);
    }

    printf ("};");
    return 0;
}
