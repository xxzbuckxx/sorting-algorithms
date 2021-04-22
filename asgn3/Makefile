CC=clang
CFLAGS=-Wall -Wextra -Werror -Wpedantic

all: sorting

sorting:
	$(CC) $(CFLAGS) -o sorting sorting.c bubble.c shell.c
sorting.o:
	$(CC) $(CFLAGS) -c sorting.c
bubble.o:
	$(CC) $(CFLAGS) -c bubble.c
shell.o:
	$(CC) $(CFLAGS) -c shell.c
clean:
	rm -f sorting *.o *.gch
format:
	clang-format -i -style=file *.[ch]
scan-build: clean
	scan-build make
