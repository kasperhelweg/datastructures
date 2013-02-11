#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

/*
 * internal prototypes
 ****************************/

QNode* mallocNode( void );

/*
 * implementation
 ****************************/

/* return number of elements in queue */
int length( QNode* queue )
{
  /* assume queue of length >= 1 */
  int length = 1;
  
  if( !queue ) { 
    /* assumption is false, so correct it */
    --length; 
  } else {
    /* we need a way of knowing if we are done traversing the queue */
    QNode* current = queue->link; 
    /* traverse queue and increment length */
    while( current != queue ) {
      current = current->link;
      ++length;
    }
  }
  return length;
}

/* add element at rear end */
void enqueue( QNode** queue, Data el )
{
  /* allocate space for the new node */
  QNode* new_node = mallocNode( );
  
  /* set up new queue structure */
  if( !(*queue) ) {
    /* this is the first element so it should point to itself */
    new_node->link = new_node;
  } else {
    /* setup correct links */
    new_node->link = (*queue)->link;
    (*queue)->link = new_node;
  }
  /* finish off */
  new_node->content = el; *queue = new_node;
}

/* remove and return front element 
 * returns NULL pointer if queue is empty 
 */
Data dequeue( QNode** queue )
{ 
  Data data = NULL;
 
  if( *queue ) {
    QNode* node_to_dequeue = (*queue)->link;
    data = node_to_dequeue->content;
    
    if( *queue == node_to_dequeue ) {
      *queue = NULL;
    } else {
      (*queue)->link = node_to_dequeue->link;
      node_to_dequeue->link = NULL;
    }

    free( node_to_dequeue );
    node_to_dequeue = NULL;
  } 
  return data;
}

/* sum values of all data in queue 
 * the value 0 is returned for the empty queue
 * it's up to the caller to make sure that it's sensible to call sum( )
*/
int sum( QNode* queue, int (*val)( Data ) )
{
  int sum = 0;
  
  if( queue ) {
    /* start at head and walk queue, adding data elements */
    QNode* current = queue->link;
    while( current != queue ) {
      sum += (*val)(current->content);
      current = current->link;
    }
    /* remember the tail element*/
    sum += (*val)(queue->content);
  }
  return sum;
}

/*
 * implementation internals
 ****************************/
/* call malloc and cast to type Listnode* */
QNode* mallocNode( void ) 
{ 
  QNode* new_node = (QNode*)malloc( sizeof( QNode ) );

  if ( !new_node ) {
    printf ( "Out of memory.\n" );
    exit ( EXIT_FAILURE );
  } 
 
  return new_node;
}

