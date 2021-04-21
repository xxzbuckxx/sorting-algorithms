CC=clang
CFLAGS=-Wall -Wextra -Werror -Wpedantic

all: sorting

sorting: sorting.o bubble_sort.o
	$(CC) $(CFLAGS) -o sorting sorting.o bubble.o
sorting.o:
	$(CC) $(CFLAGS) -c sorting.c
bubble_sort.o:
	$(CC) $(CFLAGS) -c bubble.c bubble.h
clean:
	rm -f sorting *.o
format:
	clang-format -i -style=file *.[ch]
scan-build: clean
	scan-build make
