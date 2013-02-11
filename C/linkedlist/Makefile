CC=gcc
CFLAGS=-ansi -g -pedantic -Wall -Wextra

listtest: listtest.o list.o
	$(CC) $(CFLAGS) listtest.o list.o -o listtest.out

listtest.o: listtest.c list.h
	$(CC) $(CFLAGS) -c listtest.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

clean: 	
	rm -f *.o
	rm -f listtest.out

all: listtest

