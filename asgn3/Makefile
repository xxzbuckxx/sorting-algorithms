CC=clang
CFLAGS=-Wall -Wextra -Werror -Wpedantic

all: 

clean:
	rm -f mathlib-test a.out *.jpg *.txt
format:
	clang-format -i -style=file *.[ch]
scan-build: clean
	scan-build make
