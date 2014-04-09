# September 2013 - Dylan Rudolph

SHELL = /bin/sh

CFLAGS = -lm -lrt -lfftw3 -Wall -O2
CC = gcc

MAIN = 2dfft_onethread.c
OUT = 2dfft_onethread

all: $(MAIN)
	$(CC) $(MAIN) -o $(OUT) $(CFLAGS)

clean: 
	rm -f $(OUT)
