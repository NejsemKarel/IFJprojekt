CC=gcc
CFLAGS=-Wall -Werror -Wextra
ahoj: scanner.c
	$(CC) -o scan scanner.c $(CFLAGS)
	$(CC) -o parser parser.c $(CFLAGS)
	$(CC) -o dll dll.c $(CFLAGS)
	$(CC) -o symtable symtable.c $(CFlags)

run:
	$(CC) -o scan scanner.c $(CFLAGS)
	$(CC) -o parser parser.c $(CFLAGS)
	$(CC) -o dll dll.c $(CFLAGS)
	$(CC) -o symtable symtable.c $(CFlags)
	./parser < example.txt

scanner:
	$(CC) -o scan scanner.c $(CFLAGS)
	./scan < example.txt

clean:
	rm -f scan
	rm -f parser
	rm -f dll
	rm -f symtable