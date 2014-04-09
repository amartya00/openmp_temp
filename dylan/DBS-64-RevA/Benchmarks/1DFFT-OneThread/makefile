
# Makefile for FFTW-Based FFT Benchmark
# September 2013 - Dylan Rudolph

SHELL = /bin/sh

CFLAGS = -lm -lrt -lfftw3 -Wall -O2
CC = gcc

MAIN = 1dfft_onethread.c
OUT = 1dfft_onethread

all: $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) -o $(OUT)

clean: 
	rm -f $(OUT)

