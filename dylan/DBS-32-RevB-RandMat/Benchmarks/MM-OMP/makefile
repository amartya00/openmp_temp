# September 2013 - Dylan Rudolph

SHELL = /bin/sh

CFLAGS = -fopenmp -lm -lrt -Wall -O2
CC = gcc

MAIN = mm_omp.c
OUT = mm_omp

all: $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) -o $(OUT)

clean: 
	rm -f $(OUT)
