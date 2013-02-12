#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

/*
 * internal prototypes
 ****************************/

static QNode* mallocNode( void );

/*
 * implementation
 ****************************/

/* return number of elements in queue */
int length( QNode* queue )
{
  /* assume queue of length = 0 */
  int length = 0;
  
  if( queue != NULL ) { 
    /* pointer to walk the queue */
    QNode* current = queue->link; 
    /* traverse queue and increment length */
    do {
      ++length;
      current = current->link;
    } while( current != queue->link );
  }
  return length;
}

/* add element at rear end */
void enqueue( QNode** queue, Data el )
{
  /* allocate space for the new node */
  QNode* new_node = mallocNode( );
  
  /* set up new queue structure */
  if( *queue == NULL ) {
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
 
  if( *queue != NULL ) {
    /* pointer to the node that should be removed. extract data */
    QNode* node_to_dequeue = (*queue)->link;
    data = node_to_dequeue->content;
    /* set up new queue structure */
    if( *queue == node_to_dequeue ) {
      /* only one element in queue. queue should be set to empty */
      *queue = NULL;
    } else {
      /* completely detach node from queue */
      (*queue)->link = node_to_dequeue->link;
      node_to_dequeue->link = NULL;
    }
    /* free the memory */
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
  
  if( queue != NULL ) {
    /* start at head and walk queue, summing data elements */
    QNode* current = queue->link;
    
    do {
      sum += (*val)(current->content);
      current = current->link;
    } while( current != queue->link );  
  }
  return sum;
}

/*
 * implementation internals
 ****************************/

/* call malloc and cast to type QNode* */
QNode* mallocNode( void ) 
{ 
  QNode* new_node = (QNode*)malloc( sizeof( QNode ) );

  if ( !new_node ) {
    printf ( "Out of memory.\n" );
    exit ( EXIT_FAILURE );
  } 
  return new_node;
}

