#ifndef QUEUE_H
#define QUEUE_H

typedef void* Data; 

typedef struct QNode_ {
  Data content;
  struct QNode_ *link;
} QNode;

/* return number of elements in queue */
int length( QNode* ); 

/* add element at rear end */
void enqueue( QNode**, Data );

/* remove and return front element */
Data dequeue( QNode** );

/* sum values of all data in queue */
int sum( QNode*, int (*)( Data ) );

#endif /* QUEUE_H */
