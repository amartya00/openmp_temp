# September 2013 - Dylan Rudolph

SHELL = /bin/sh

CFLAGS = -lfftw3_omp -lm -lrt -lfftw3 -Wall -O2
CC = gcc

MAIN = 1dfft_omp.c
OUT = 1dfft_omp

all: $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) -o $(OUT)

clean:
	rm -f $(OUT)
