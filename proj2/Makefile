####################################################################
# Subor: Makefile												   #
# Autor: David Oravec (xorave05@stud.fit.vutbr.cz)				   #
# Fakulta: Fakulta  informačních technologii (FIT)				   #
# Datum: 24.04.2019												   #
# 																   #
####################################################################

C=gcc
CPP=g++
CFLAGS=-std=c99 -pedantic -g -Wall -Wextra -O0
CPPFLAGS=-std=c++11 -pedantic -Wall

OBJ= htab_hash_function.o htab_init.o htab_lookup_add.o htab_begin.o htab_end.o \
	 htab_iterator_next.o htab_bucket_count.o htab_size.o htab_clear.o htab_free.o \
	 extern.o

LD_LIBRARY_PATH=.

all: tail tail2 wordcount wordcount-dynamic

## Ukol 1 C program	
tail: tail.o
	$(C) $(CFLAGS) tail.o -o $@
tail.o: tail.c tail.h
	$(C) $(CFLAGS) -c tail.c -o $@

## Ukol 1 C++ program

tail2: tail2.o
	$(CPP) $(CPPFLAGS) tail2.o -o $@

tail2.o: tail2.cc
	$(CPP) $(CPPFLAGS) -c tail2.cc -o $@

## Ukol 2
## Object files

htab_hash_function.o: htab_hash_function.c htab.h
	$(C) $(CFLAGS) -c -fPIC htab_hash_function.c -o $@

htab_init.o: htab_init.c htab.h
	$(C) $(CFLAGS) -c -fPIC htab_init.c -o $@

htab_lookup_add.o: htab_lookup_add.c htab.h
	$(C) $(CFLAGS) -c -fPIC htab_lookup_add.c -o $@

htab_begin.o: htab_begin.c htab.h
	$(C) $(CFLAGS) -c -fPIC htab_begin.c -o $@

htab_end.o: htab_end.c htab.h
	$(C) $(CFLAGS) -c -fPIC htab_end.c -o $@

htab_iterator_next.o: htab_iterator_next.c htab.h
	$(C) $(CFLAGS) -c -fPIC htab_iterator_next.c -o $@

htab_bucket_count.o: htab_bucket_count.c htab.h
	$(C) $(CFLAGS) -c -fPIC htab_bucket_count.c -o $@

htab_size.o: htab_size.c htab.h
	$(C) $(CFLAGS) -c -fPIC htab_size.c -o $@

htab_clear.o: htab_clear.c htab.h
	$(C) $(CFLAGS) -c -fPIC htab_clear.c -o $@

htab_free.o: htab_free.c htab.h
	$(C) $(CFLAGS) -c -fPIC htab_free.c -o $@

extern.o: extern.c htab.h
	$(C) $(CFLAGS) -c -fPIC extern.c -o $@

wordcount.o:wordcount.c io.h htab.h
	$(C) $(CFLAGS) -c wordcount.c -o $@

io.o: io.c io.h htab.h
	$(C) $(CFLAGS) -c io.c -o $@

## Staticka verzia spolu s kniznicou
wordcount: wordcount.o io.o libhtab.a
	$(C) $(CFLAGS) -static wordcount.o io.o libhtab.a -o wordcount

libhtab.a: $(OBJ) 
	ar rcs libhtab.a $(OBJ)

## Dynamicka verzia spolu s kniznicou

wordcount-dynamic: wordcount.o io.o libhtab.so
	$(C) $(CFLAGS) -L$(LD_LIBRARY_PATH) -Wl,-rpath=$(LD_LIBRARY_PATH) -fPIC wordcount.o io.o libhtab.so -o $@ libhtab.so

libhtab.so:$(OBJ)
	$(C) $(CFLAGS) -shared -o libhtab.so  -fPIC $(OBJ) -L$(LD_LIBRARY_PATH)


pack:
	zip xorave05.zip *.c *.h *.cc Makefile

clean:
	rm -f *.o