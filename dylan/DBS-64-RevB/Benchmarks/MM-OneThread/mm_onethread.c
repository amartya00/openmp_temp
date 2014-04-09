/*
  A simple single-threaded matrix multiplaction benchmark.

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
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "time.h"

/* 64 bit float type. */
typedef double dtype;

/* 64 bit int type. */
typedef long long int ltype; 

/* 32 bit float type. */
typedef float ftype;

/* 32 bit int type. */
typedef int itype;

typedef struct {
  uint rows;
  uint cols;
  dtype ** M;
} dmatrixtype, *dmatrix;

typedef struct {
  uint rows;
  uint cols;
  ltype ** M;
} lmatrixtype, *lmatrix;

typedef struct {
  uint rows;
  uint cols;
  ftype ** M;
} fmatrixtype, *fmatrix;

typedef struct {
  uint rows;
  uint cols;
  itype ** M;
} imatrixtype, *imatrix;

typedef unsigned int uint;
struct timespec start_time_mem, end_time_mem, start_time_run, end_time_run;

/* -------------------------------------------------------------------------- */
/* ------------------- Operations for FLOAT64-Typed Matrices ---------------- */
/* -------------------------------------------------------------------------- */

dmatrix new_dmatrix(uint rows, uint cols)
/*
  Make a new 'dmatrix' type and allocate memory for it.
  Access is done by: A->M[row][column].
*/
{
  uint i;
  dmatrix A = malloc(sizeof(dmatrixtype));
  A->rows = rows;
  A->cols = cols;
  A->M = malloc( sizeof( dtype * ) * rows );

  for (i = 0; i<rows; i++) {
    A->M[i] = malloc( sizeof( dtype * ) * cols);
  }

  return A;
}

void delete_dmatrix(dmatrix A)
/* Frees up the memory allocated for the dmatrix A. */
{
  uint row;
  for (row = 0; row<(A->rows); row++) { free(A->M[row]); }
  free(A->M);
  free(A);
}

void zero_dmatrix(dmatrix A)
/* Zeros out the dmatrix A. */
{
  uint row, col;
  for(row = 0; row<(A->rows); row++) {
    for(col = 0; col<(A->cols); col++) {
      A->M[row][col] = (dtype) 0;
    }
  }
}

void random_fill_dmatrix(dmatrix A, dtype lower, dtype upper)
/* Fills a dmatrix with random numbers over [lower, upper) */
{
  uint row, col;
  for (row = 0; row<(A->rows); row++) {
    for (col = 0; col<(A->cols); col++) {
      A->M[row][col] = ((dtype) rand() / (RAND_MAX)) * 
                       (upper - lower + 1) + lower;
    }
  }
}

dmatrix new_random_dmatrix(uint rows, uint cols, dtype lower, dtype upper)
/* Returns a random newly-allocated dmatrix. */
{
  dmatrix A = new_dmatrix(rows, cols);
  random_fill_dmatrix(A, lower, upper);
  return A;
}

void multiply_dmatrix(dmatrix A, dmatrix B, dmatrix C)
/*
   Multiplies A and B, and puts the result in C.
   C should be zeroed and initialized with size: (A->rows, B->cols).
*/
{
  zero_dmatrix(C);
  if (A->cols != B->rows) { exit(0); }
  uint row;
  uint col;
  uint i;
  for (row = 0; row<(C->rows); row++) {
    for (col = 0; col<(C->cols); col++) {
      for (i = 0; i<(A->cols); i++) {
         C->M[row][col] += A->M[row][i] * B->M[i][col];
      }
    }
  }
}

/* -------------------------------------------------------------------------- */
/* ------------------- Operations for INT64-Typed Matrices ------------------ */
/* -------------------------------------------------------------------------- */

lmatrix new_lmatrix(uint rows, uint cols)
/*
  Make a new 'lmatrix' type and allocate memory for it.
  Access is done by: A->M[row][column].
*/
{
  uint i;
  lmatrix A = malloc(sizeof(lmatrixtype));
  A->rows = rows;
  A->cols = cols;
  A->M = malloc( sizeof( ltype * ) * rows );

  for (i = 0; i<rows; i++) {
    A->M[i] = malloc( sizeof( ltype * ) * cols);
  }

  return A;
}

void delete_lmatrix(lmatrix A)
/* Frees up the memory allocated for the lmatrix A. */
{
  uint row;
  for (row = 0; row<(A->rows); row++) { free(A->M[row]); }
  free(A->M);
  free(A);
}

void zero_lmatrix(lmatrix A)
/* Zeros out the lmatrix A. */
{
  uint row, col;
  for(row = 0; row<(A->rows); row++) {
    for(col = 0; col<(A->cols); col++) {
      A->M[row][col] = (ltype) 0;
    }
  }
}

void random_fill_lmatrix(lmatrix A, ltype lower, ltype upper)
/* Fills a lmatrix with random numbers over [lower, upper) */
{
  uint row, col;
  for (row = 0; row<(A->rows); row++) {
    for (col = 0; col<(A->cols); col++) {
      A->M[row][col] = ((ltype) rand() / (RAND_MAX)) * 
                       (upper - lower + 1) + lower;
    }
  }
}

lmatrix new_random_lmatrix(uint rows, uint cols, ltype lower, ltype upper)
/* Returns a random newly-allocated lmatrix. */
{
  lmatrix A = new_lmatrix(rows, cols);
  random_fill_lmatrix(A, lower, upper);
  return A;
}

void multiply_lmatrix(lmatrix A, lmatrix B, lmatrix C)
/*
   Multiplies A and B, and puts the result in C.
   C should be zeroed and initialized with size: (A->rows, B->cols).
*/
{
  zero_lmatrix(C);
  if (A->cols != B->rows) { exit(0); }
  uint row;
  uint col;
  uint i;
  for (row = 0; row<(C->rows); row++) {
    for (col = 0; col<(C->cols); col++) {
      for (i = 0; i<(A->cols); i++) {
         C->M[row][col] += A->M[row][i] * B->M[i][col];
      }
    }
  }
}

/* -------------------------------------------------------------------------- */
/* ------------------- Operations for FLOAT32-Typed Matrices ---------------- */
/* -------------------------------------------------------------------------- */

fmatrix new_fmatrix(uint rows, uint cols)
/*
  Make a new 'fmatrix' type and allocate memory for it.
  Access is done by: A->M[row][column].
*/
{
  uint i;
  fmatrix A = malloc(sizeof(fmatrixtype));
  A->rows = rows;
  A->cols = cols;
  A->M = malloc( sizeof( ftype * ) * rows );

  for (i = 0; i<rows; i++) {
    A->M[i] = malloc( sizeof( ftype * ) * cols);
  }

  return A;
}

void delete_fmatrix(fmatrix A)
/* Frees up the memory allocated for the fmatrix A. */
{
  uint row;
  for (row = 0; row<(A->rows); row++) { free(A->M[row]); }
  free(A->M);
  free(A);
}

void zero_fmatrix(fmatrix A)
/* Zeros out the fmatrix A. */
{
  uint row, col;
  for(row = 0; row<(A->rows); row++) {
    for(col = 0; col<(A->cols); col++) {
      A->M[row][col] = (ftype) 0;
    }
  }
}

void random_fill_fmatrix(fmatrix A, ftype lower, ftype upper)
/* Fills a fmatrix with random numbers over [lower, upper) */
{
  uint row, col;
  for (row = 0; row<(A->rows); row++) {
    for (col = 0; col<(A->cols); col++) {
      A->M[row][col] = ((ftype) rand() / (RAND_MAX)) * 
                       (upper - lower + 1) + lower;
    }
  }
}

fmatrix new_random_fmatrix(uint rows, uint cols, ftype lower, ftype upper)
/* Returns a random newly-allocated fmatrix. */
{
  fmatrix A = new_fmatrix(rows, cols);
  random_fill_fmatrix(A, lower, upper);
  return A;
}

void multiply_fmatrix(fmatrix A, fmatrix B, fmatrix C)
/*
   Multiplies A and B, and puts the result in C.
   C should be zeroed and initialized with size: (A->rows, B->cols).
*/
{
  zero_fmatrix(C);
  if (A->cols != B->rows) { exit(0); }
  uint row;
  uint col;
  uint i;
  for (row = 0; row<(C->rows); row++) {
    for (col = 0; col<(C->cols); col++) {
      for (i = 0; i<(A->cols); i++) {
         C->M[row][col] += A->M[row][i] * B->M[i][col];
      }
    }
  }
}

/* -------------------------------------------------------------------------- */
/* ------------------ Operations for INT32-Typed Matrices-------------------- */
/* -------------------------------------------------------------------------- */

imatrix new_imatrix(uint rows, uint cols)
/*
  Make a new 'imatrix' type and allocate memory for it.
  Access is done by: A->M[row][column].
*/
{
  uint i;
  imatrix A = malloc(sizeof(imatrixtype));
  A->rows = rows;
  A->cols = cols;
  A->M = malloc( sizeof( itype * ) * rows );

  for (i = 0; i<rows; i++) {
    A->M[i] = malloc( sizeof( itype * ) * cols);
  }

  return A;
}

void delete_imatrix(imatrix A)
/* Frees up the memory allocated for the imatrix A. */
{
  uint row;
  for (row = 0; row<(A->rows); row++) { free(A->M[row]); }
  free(A->M);
  free(A);
}

void zero_imatrix(imatrix A)
/* Zeros out the imatrix A. */
{
  uint row, col;
  for(row = 0; row<(A->rows); row++) {
    for(col = 0; col<(A->cols); col++) {
      A->M[row][col] = (itype) 0;
    }
  }
}

void random_fill_imatrix(imatrix A, itype lower, itype upper)
/* Fills a imatrix with random numbers over [lower, upper) */
{
  uint row, col;
  for (row = 0; row<(A->rows); row++) {
    for (col = 0; col<(A->cols); col++) {
      A->M[row][col] = ((itype) rand() / (RAND_MAX)) * 
                       (upper - lower + 1) + lower;
    }
  }
}

imatrix new_random_imatrix(uint rows, uint cols, itype lower, itype upper)
/* Returns a random newly-allocated imatrix. */
{
  imatrix A = new_imatrix(rows, cols);
  random_fill_imatrix(A, lower, upper);
  return A;
}

void multiply_imatrix(imatrix A, imatrix B, imatrix C)
/*
   Multiplies A and B, and puts the result in C.
   C should be zeroed and initialized with size: (A->rows, B->cols).
*/
{
  zero_imatrix(C);
  if (A->cols != B->rows) { exit(0); }
  uint row;
  uint col;
  uint i;
  for (row = 0; row<(C->rows); row++) {
    for (col = 0; col<(C->cols); col++) {
      for (i = 0; i<(A->cols); i++) {
         C->M[row][col] += A->M[row][i] * B->M[i][col];
      }
    }
  }
}

/* ------------------------------------------------------------------------ */
/* -------------------------- Common Functions ---------------------------- */
/* ------------------------------------------------------------------------ */

double time_diff(struct timespec a, struct timespec b)
/* Finds the time difference. */
{
  double dt = (( b.tv_sec - a.tv_sec ) + 
               ( b.tv_nsec - a.tv_nsec ) / 1E9);
  return dt;
}

/* ------------------------------------------------------------------------ */
/* --------------------------- Main Function ------------------------------ */
/* ------------------------------------------------------------------------ */

int main (int argc, char *argv[])
{

  int i;

  /* Parse the input to get the matrix size. */
  uint M, N, rows, cols;
  char *endptrM;
  char *endptrN;

  if (argc > 2) {
    M = strtol(argv[1], &endptrM, 10);
    N = strtol(argv[2], &endptrN, 10);
  } else if (argc > 1){
    M = strtol(argv[1], &endptrM, 10);
    N = strtol(argv[1], &endptrN, 10);
  } else {
    M = 8; 
    N = 8; 
  }

  rows = M;
  cols = N;

  /* 'runs' is the number of times over which to average. 
     It is reduced gradually as the matrix size increases.*/
  int runs = 1048576 / N / M;
  if (N*M > 1024*1024) { runs++; }
  printf("N runs in C program: %i\n", runs);

  /* ------------------------------------------------------------------------ */
  /* -------------------- Benchmark for the F64 type ------------------------ */
  /* ------------------------------------------------------------------------ */

  /* Initialize the matrices */
  srand( time(0) );
  dmatrix A = new_random_dmatrix(rows, cols, 0, 10);
  dmatrix B = new_random_dmatrix(cols, rows, 0, 10);
  dmatrix C = new_dmatrix(rows, rows);
  
  /* Actual matrix multiply */
  clock_gettime(CLOCK_REALTIME, &start_time_run);

  /* Do it 'runs' times for consistency. */
  for (i=0; i<runs; i++) {
    multiply_dmatrix(A, B, C);
  }

  clock_gettime(CLOCK_REALTIME, &end_time_run);

  /* Free things up */
  delete_dmatrix(A);
  delete_dmatrix(B);
  delete_dmatrix(C);

  double dt_run = time_diff(start_time_run, end_time_run) / (double) runs;
  printf("F64RUNTIME: %.8f;rf64\n", dt_run);

  /* ------------------------------------------------------------------------ */
  /* -------------------- Benchmark for the I64 type ------------------------ */
  /* ------------------------------------------------------------------------ */

  /* Initialize the matrices */
  lmatrix X = new_random_lmatrix(rows, cols, 0, 10);
  lmatrix Y = new_random_lmatrix(cols, rows, 0, 10);
  lmatrix Z = new_lmatrix(rows, rows);
  
  /* Actual matrix multiply */
  clock_gettime(CLOCK_REALTIME, &start_time_run);

  /* Do it 'runs' times for consistency. */
  for (i=0; i<runs; i++) {
    multiply_lmatrix(X, Y, Z);
  }

  clock_gettime(CLOCK_REALTIME, &end_time_run);

  /* Free things up */
  delete_lmatrix(X);
  delete_lmatrix(Y);
  delete_lmatrix(Z);

  dt_run = time_diff(start_time_run, end_time_run) / (double) runs;
  printf("I64RUNTIME: %.8f;ri64\n", dt_run);


  /* ------------------------------------------------------------------------ */
  /* -------------------- Benchmark for the F32 type ------------------------ */
  /* ------------------------------------------------------------------------ */

  /* Initialize the matrices */
  fmatrix F = new_random_fmatrix(rows, cols, 0, 10);
  fmatrix G = new_random_fmatrix(cols, rows, 0, 10);
  fmatrix H = new_fmatrix(rows, rows);
  
  /* Actual matrix multiply */
  clock_gettime(CLOCK_REALTIME, &start_time_run);

  /* Do it 'runs' times for consistency. */
  for (i=0; i<runs; i++) {
    multiply_fmatrix(F, G, H);
  }

  clock_gettime(CLOCK_REALTIME, &end_time_run);

  /* Free things up */
  delete_fmatrix(F);
  delete_fmatrix(G);
  delete_fmatrix(H);

  dt_run = time_diff(start_time_run, end_time_run) / (double) runs;
  printf("F32RUNTIME: %.8f;rf32\n", dt_run);

  /* ------------------------------------------------------------------------ */
  /* -------------------- Benchmark for the I32 type ------------------------ */
  /* ------------------------------------------------------------------------ */

  /* Initialize the matrices */
  imatrix J = new_random_imatrix(rows, cols, 0, 10);
  imatrix K = new_random_imatrix(cols, rows, 0, 10);
  imatrix L = new_imatrix(rows, rows);
  
  /* Actual matrix multiply */
  clock_gettime(CLOCK_REALTIME, &start_time_run);

  /* Do it 'runs' times for consistency. */
  for (i=0; i<runs; i++) {
    multiply_imatrix(J, K, L);
  }

  clock_gettime(CLOCK_REALTIME, &end_time_run);

  /* Free things up */
  delete_imatrix(J);
  delete_imatrix(K);
  delete_imatrix(L);

  dt_run = time_diff(start_time_run, end_time_run) / (double) runs;
  printf("I32RUNTIME: %.8f;ri32\n", dt_run);

  return 0;
}
