# DU1 IJC - Makefile
# Autor: David Oravec (xorave05@stud.fit.vutbr.cz)
# Datum: 20.3.2019

# poziadavky ladiacich informacii

CC=gcc
CFLAGS= -O2 -std=c11 -pedantic -Wall -Wextra

all: primes primes-i steg-decode

bit_array.h: error.o

bit_array.o: bit_array.c bit_array.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c bit_array.c -o $@

primes: primes.o error.o eratosthenes.o
	$(CC) $(CFLAGS) primes.o error.o eratosthenes.o -lm -o $@

primes.o: bit_array.h primes.c eratosthenes.h
	$(CC) $(CFLAGS) -c primes.c -o $@

eratosthenes.o: eratosthenes.c eratosthenes.h bit_array.h
	$(CC) $(CFLAGS) -c eratosthenes.c -o $@

eratosthenes-i.o: eratosthenes.c eratosthenes.h bit_array.h 
	$(CC) $(CFLAGS) -DUSE_INLINE -c eratosthenes.c -o $@

primes-i: primes-i.o error.o eratosthenes-i.o bit_array.o
	$(CC) $(CFLAGS) primes-i.o error.o eratosthenes-i.o bit_array.o -lm -o $@

primes-i.o: primes.c bit_array.h eratosthenes.c bit_array.c
	$(CC) $(CFLAGS) -DUSE_INLINE -c primes.c -o $@

steg-decode: steg-decode.o error.o ppm.o eratosthenes.o
	$(CC) $(CFLAGS) steg-decode.o error.o ppm.o eratosthenes.o -lm -o $@

steg-decode.o: steg-decode.c error.h ppm.h eratosthenes.h
	$(CC) $(CFLAGS) -c steg-decode.c -o $@

ppm.o: ppm.c ppm.h error.h
	$(CC) $(CFLAGS) -c ppm.c -o $@

error.o: error.c error.h
	$(CC) $(CFLAGS) -c error.c -o $@

clean:
	rm -f *.o
	rm -f primes primes-i steg-decode 

pack:
	zip xorave05.zip *.c *.h Makefile

run:
	time ./primes
	time ./primes-i
	./steg-decode du1-obrazek.ppm