CC=gcc
CFLAGS=-Wall -Werror -Wextra
fortnite: scanner.c
	$(CC) -o compile parser.c scanner.c $(CFLAGS)
run:
	$(CC) -o compile parser.c scanner.c $(CFLAGS)
	./compile < example.txt

scanner:
	$(CC) -o scan scanner.c $(CFLAGS)
	./scan < example.txt

clean:
	rm -f scan
	rm -f parser
	rm -f dll
	rm -f symtable