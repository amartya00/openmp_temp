/*  
    A 1D FFT Benchmark Based on the FFTW library. 
    Copyright (C) 2013  Dylan Rudolph

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    For infomation on the FFTW library, see http://www.fftw.org/. 
*/

#include <fftw3.h>
#include <stdlib.h>
#include <time.h>

struct timespec start_time, end_time;

double time_diff(struct timespec a, struct timespec b)
{
  double dt = (( b.tv_sec - a.tv_sec ) + 
               ( b.tv_nsec - a.tv_nsec ) / 1E9);
  return dt;
}

int main(int argc, char **argv)
{  
  /* This should probably be equal to the number of cores. */
  uint threads = 2;

  /* Accept the command-line argument for vector length. Default to 16192. */
  uint N;
  char *endptr;
  if (argc > 1) { N = strtol(argv[1], &endptr, 10); }
  else { N = 16192; }

  /* 'runs' is the number of times over which to average. 
     It becomes smaller with input size. */
  uint runs = 33554432/N;
  if (runs > 33554432) { runs++; }
  printf("N runs in C program: %i\n", runs);

  /* Declare that this is to be a parallel program */
  fftw_init_threads();

  /* Initialize the data and the 'plan' - a part of FFTW */
  fftw_complex *input, *output;
  fftw_plan plan;

  input = (fftw_complex*) fftw_malloc( sizeof(fftw_complex) * N );
  output = (fftw_complex*) fftw_malloc( sizeof(fftw_complex) * N );

  /* Fill the complex input vector randomly */
  srand(time(0));
  uint k;
  for (k = 0; k<N; k++) { 
    input[k][0] = ((double) rand() / RAND_MAX * 2 - 1); 
    input[k][1] = ((double) rand() / RAND_MAX * 2 - 1); 
  }

  /* Declare the number of threads to use. */
  fftw_plan_with_nthreads(threads);
  
  /* Make the FFTW 'plan' */
  plan = fftw_plan_dft_1d(N, input, output, FFTW_FORWARD, FFTW_ESTIMATE);
  
  /* Run the FFT 'runs' times and time it. */
  clock_gettime(CLOCK_REALTIME, &start_time);
  for (k = 0; k<runs; k++) {
    fftw_execute(plan);
  }
  clock_gettime(CLOCK_REALTIME, &end_time);
  
  /* Reclaim allocated memory. */
  fftw_destroy_plan(plan);
  fftw_free(input);
  fftw_free(output);

  /* Calculate the time difference and normalize for 'runs' */
  double dt = time_diff(start_time, end_time) / (double) runs;
  printf("F64RUNTIME: %.8f;rf64\n", dt);

  return 0;
}
