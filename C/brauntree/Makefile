CC=gcc
CFLAGS=-g -pedantic -Wall -Wextra

brauntest: braunseqtest.o braunseq.o
	$(CC) $(CFLAGS) braunseqtest.o braunseq.o -o brauntest.out

braunseqtest.o: braunseqtest.c braunseq.h
	$(CC) $(CFLAGS) -c braunseqtest.c

braunseq.o: braunseq.c braunseq.h
	$(CC) $(CFLAGS) -c braunseq.c

clean: 	
	rm -f *.o
	rm -f brauntest.out

all: brauntest
