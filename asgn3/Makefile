CC=clang
CFLAGS=-Wall -Wextra -Werror -Wpedantic

all: sorting

sorting:
	$(CC) $(CFLAGS) -o sorting sorting.c

clean:
	rm -f sorting
format:
	clang-format -i -style=file *.[ch]
scan-build: clean
	scan-build make
