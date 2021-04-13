CC=clang
CFLAGS=-Wall -Wextra -Werror -Wpedantic

all: mathlib.o mathlib-test.o
	$(CC) $(CFLAGS) mathlib.o mathlib-test.o -o test -lm

mathlib.o: mathlib.c mathlib.h
	$(CC) $(CFLAGS) -c mathlib.c
mathlib-test.o: mathlib-test.c mathlib.h
	$(CC) $(CFLAGS) -c mathlib-test.c 
clean:
	rm -f mathlib-test.o mathlib.o test
scan-build: clean
	scan-build make
