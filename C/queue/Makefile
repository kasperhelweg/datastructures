CC=gcc
CFLAGS=-ansi -g -pedantic -Wall -Wextra

qtest: qtest.o queue.o
	$(CC) $(CFLAGS) qtest.o queue.o -o qtest.out

qtest.o: qtest.c queue.h
	$(CC) $(CFLAGS) -c qtest.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

clean: 	
	rm -f *.o
	rm -f qtest.out

all: qtest
