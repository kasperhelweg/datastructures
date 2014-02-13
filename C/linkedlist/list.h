#ifndef LIST_H
#define LIST_H

typedef void* Data;

typedef struct listnode {
  Data content;
  struct listnode* next;
} Listnode;

/* 
   add an element at the end of the list
   we need a ** in order to not overwrite the actual rootnode
*/
void append( Listnode** start, Data elem );

/* 
   add an element at the front
   we need a ** in order to easily make changes permanent when leaving procedure
*/
void prepend( Listnode** start, Data elem );

void* remv( Listnode** start, int ( *match )( Data ));

/* length */
int length( Listnode* start );

/* return first element (if not empty) */
Data head( Listnode* start );

void printList( Listnode* );

#endif
