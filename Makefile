CC=gcc
CFLAGS=-Wall -Werror -Wextra
ahoj: scanner.c
	$(CC) -o scan scanner.c $(CFLAGS)
clean:
	rm -f scan