# September 2013 - Dylan Rudolph

SHELL = /bin/sh

CFLAGS = -lm -lrt -Wall -O2
CC = gcc

MAIN = dot_onethread.c
OUT = dot_onethread

all: $(MAIN)
	$(CC) $(MAIN) -o $(OUT) $(CFLAGS)

clean:
	rm -f $(OUT)
