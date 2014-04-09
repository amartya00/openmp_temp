# September 2013 - Dylan Rudolph

SHELL = /bin/sh

CFLAGS = -lm -lrt -Wall
CC = gcc

MAIN = dot_naive.c
OUT = dot_naive

all: $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) -o $(OUT)

clean: 
	rm -f $(OUT)
