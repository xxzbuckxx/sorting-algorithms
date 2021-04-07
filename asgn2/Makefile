CC=clang
CFLAGS=-Wall -Wextra -Werror -Wpedantic

all: mathlib.c

lrc: mathlib.c
	$(CC) -o mathlib mathlib.o
lrc.o: mathlib.c
	$(CC) $(CFLAGS) -c mathlib.c
clean:
	rm -f mathlib mathlib.o
scan-build: clean
	scan-build make
