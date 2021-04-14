CC=clang
CFLAGS=-Wall -Wextra -Werror -Wpedantic

all: mathlib-test

mathlib: mathlib.c mathlib.h
	$(CC) $(CFLAGS) -c mathlib.c -lm
mathlib-test: mathlib-test.c mathlib.h mathlib.c
	$(CC) $(CFLAGS) -o mathlib-test mathlib-test.c mathlib.c -lm
clean:
	rm -f mathlib-test a.out
scan-build: clean
	scan-build make
