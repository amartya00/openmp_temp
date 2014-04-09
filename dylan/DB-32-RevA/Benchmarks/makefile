# September 2013 - Dylan Rudolph

SHELL = /bin/sh

all: matmult dot 1dfft 2dfft

matmult:
	cd MM-Naive; make
	cd MM-OneThread; make
	cd MM-OMP; make

dot:
	cd DOT-Naive; make
	cd DOT-OneThread; make

1dfft:
	cd 1DFFT-OneThread; make
	cd 1DFFT-OMP; make

2dfft:
	cd 2DFFT-OneThread; make
	cd 2DFFT-OMP; make

clean:
	cd MM-Naive; make clean
	cd MM-OneThread; make clean
	cd MM-OMP; make clean
	cd DOT-Naive; make clean
	cd DOT-OneThread; make clean
	cd 1DFFT-OneThread; make clean
	cd 1DFFT-OMP; make clean
	cd 2DFFT-OneThread; make clean
	cd 2DFFT-OMP; make clean


