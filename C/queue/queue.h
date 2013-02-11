#ifndef QUEUE_H
#define QUEUE_H

typedef void* Data; 

typedef struct QNode_ {
  Data content;
  struct QNode_ *link;
} QNode;

/* return number of elements in queue */
int length( QNode* queue ); 

/* add element at rear end */
void enqueue( QNode** queue, Data el );

/* remove and return front element */
Data dequeue( QNode** queue );

/* sum values of all data in queue */
int sum( QNode* queue, int (*val)( Data ) );

#endif /* QUEUE_H */
