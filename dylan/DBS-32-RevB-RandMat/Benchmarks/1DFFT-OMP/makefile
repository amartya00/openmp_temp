# September 2013 - Dylan Rudolph

SHELL = /bin/sh

CFLAGS =  -fopenmp -lm -lrt -lfftw3_omp -lfftw3 -Wall -O2
CC = cc

MAIN = 1dfft_omp.c
OUT = 1dfft_omp

all: $(MAIN)
	$(CC) $(MAIN) -o $(OUT) $(CFLAGS)

clean:
	rm -f $(OUT)
