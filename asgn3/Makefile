# Makefile compiling (lines 2-16) adapted from Proffessor Long https://piazza.com/class/kmfs2bmdr9syz?cid=63
EXEC = sorting

SOURCES = sorting.c bubble.c shell.c quick.c stack.c queue.c set.c
OBJECTS = $(SOURCES:%.c=%.o)

CC=clang
CFLAGS=-Wall -Wextra -Werror -Wpedantic

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) -o $@ $^ $(LFLAGS)

%.o: %.clean
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f sorting *.o valgrind-out.txt

format:
	clang-format -i -style=file *.[ch]

leak-check: clean all
	valgrind --leak-check=full\
         --show-leak-kinds=all\
         --track-origins=yes\
         --verbose\
         --log-file=valgrind-out.txt\
         ./sorting -a -n 200
	vim valgrind-out.txt

scan-build: clean
	scan-build make
