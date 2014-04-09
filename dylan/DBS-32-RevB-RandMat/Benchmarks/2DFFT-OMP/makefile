# September 2013 - Dylan Rudolph

SHELL = /bin/sh

CFLAGS = -fopenmp -lfftw3_omp -lm -lrt -lfftw3 -Wall -O2
CC = gcc

MAIN = 2dfft_omp.c
OUT = 2dfft_omp

all: $(MAIN)
	$(CC) $(MAIN) -o $(OUT) $(CFLAGS)

clean: 
	rm -f $(OUT)
