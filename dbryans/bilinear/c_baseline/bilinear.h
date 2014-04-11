/* #define NUM_ROWS (unsigned int)1080 */
/* #define NUM_COLS (unsigned int)1960 */

#define NUM_ROWS (unsigned int)1080
#define NUM_COLS (unsigned int)1960

#define PI 3.1416
#define THETA (float) (60*(PI))/180

void bilinear (unsigned int *in, unsigned int width, unsigned int height, float theta, unsigned int *out);
void bilinear_omp (unsigned int *in, unsigned int width, unsigned int height, float theta, unsigned int *out);
