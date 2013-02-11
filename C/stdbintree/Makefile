CC=gcc
CFLAGS=-ansi -g -pedantic -Wall -Wextra

BSTtest: BSTtest.o stdBSTree.o
	$(CC) $(CFLAGS) BSTtest.o stdBSTree.o -o BSTtest.out

BSTtest.o: BSTtest.c stdBSTree.h
	$(CC) $(CFLAGS) -c BSTtest.c

stdBSTree.o: stdBSTree.c stdBSTree.h
	$(CC) $(CFLAGS) -c stdBSTree.c

clean: 	
	rm -f *.o
	rm -f BSTtest.out

all: BSTtest
