CC=clang
CFLAGS=-Wall -Wextra -Werror -Wpedantic

all: sorting

sorting:
	$(CC) $(CFLAGS) -o sorting sorting.c bubble.c shell.c quick.c stack.c
sorting.o:
	$(CC) $(CFLAGS) -c sorting.c
bubble.o:
	$(CC) $(CFLAGS) -c bubble.c
shell.o:
	$(CC) $(CFLAGS) -c shell.c
clean:
	rm -f sorting *.o *.gch valgrind-out.txt
format:
	clang-format -i -style=file *.[ch]
leak-check: clean all
	valgrind --leak-check=full\
         --show-leak-kinds=all\
         --track-origins=yes\
         --verbose\
         --log-file=valgrind-out.txt\
         ./sorting -sb -n 200
scan-build: clean
	scan-build make
