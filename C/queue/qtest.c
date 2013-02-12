#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*
 * internal prototypes
 ****************************/

int* mallocData( void ); 
void buildQueue( QNode**, int );
void deQueue( QNode**, int );
void printQueue( QNode* );
int value( Data );
int constant_value( Data );
int fsum( int );

/*
 * test program
 ****************************/

int main( void )
{
  /* Queue */
  QNode* queue = NULL;
  /*  Value function pointer */
  int (*val)( Data ) = NULL;  
  /* Number of items to put in queue */
  int n = 4;

  /* tests */
  printf("\n~Test~\n\n");
  
  /* edgecases */
  printf( "~Remove item from empty queue~\n");
  printf( "Should be: Empty queue ~ Is: ");
  deQueue( &queue, 1 );
  
  printf( "~Length of empty queue~\n");
  printf( "Should be: 0 ~ Is: ");
  printf( "%d\n", length( queue ) );
  
  printf( "~Sum of empty queue~\n");
  printf( "Should be: 0 ~ Is: ");
  printf( "%d\n", sum( queue, val = &constant_value ) );
  printf("\n");

  /* Build a queue with 1 element [1] */
  buildQueue( &queue, 1 );

  printf( "~Length of 1-element queue~\n");
  printf( "Should be: 1 ~ Is: ");
  printf( "%d\n", length( queue ) );
  
  printf( "~Sum of 1-element queue~\n");
  printf( "Should be: 1 ~ Is: ");
  printf( "%d\n", sum( queue, val = value ) );
  
  printf( "~Remove item from 1-element queue~\n");
  printf( "Should be: data: 1 ~ Is: ");
  deQueue( &queue, 1 );
  
  printf("\n");
 
  /* generel cases */

  /* Build a queue with n elements [1,2,3,...,n] */
  buildQueue( &queue, n );
  printQueue( queue );

  /* Test for length */
  printf( "~Length of %d-element queue~\n", n);
  printf( "Should be: %d ~ Is: ", n);
  printf( "%d\n", length( queue ) );
  
  printf( "~Sum of %d-element queue~\n", n);
  printf( "Should be: %d ~ Is: ", fsum( n ) );
  printf( "%d\n", sum( queue, val = value ) );
  
  printf("\n");

  printf( "~Test dequeue~\n" );
  deQueue( &queue, n );
  printQueue( queue );
  /* Test for length of empty queue */  
  printf( "~Length of empty queue~\n");
  printf( "Should be: 0 ~ Is: ");
  printf( "%d\n", length( queue ) );

  return 0;
}

void buildQueue( QNode** queue, int qe )
{
  int i = 1;
  
  /* Build the list, displaying length */
  while( i <= qe ) {
    int* x = mallocData( );
    Data data = x;
    
    *x = i;
    enqueue( queue, data );
    
    ++i;
  }
}

void deQueue( QNode** queue, int qe )
{
  int i = 0;
  void* data;
  /* Build the list, displaying length */
  while( i < qe ) {
    data = dequeue( queue );
    if( data ) {
      printf( "data: %d\n", *(int*)data);
      free( data );
      data = NULL; 
      ++i;
    } else {
      printf("Empty queue\n");
      break;
    }
  }
}

int value( Data data )
{
  return *(int*)data;
}

int constant_value( Data data )
{
  /* suppress compiler warning */
  data = data;

  return 1;
}

int fsum( int n )
{
  int sum = 0;
  if( n == 0 ) {
    return 0;
  } else {
    sum += n + fsum( n - 1);
  }
  return sum;
}

/* Prints the content of nodes in queue */
void printQueue( QNode* queue )
{
  printf("Printing queue:\n");
  if( !queue ) { 
    /* assumption is false, so correct it */
    printf("Empty queue\n"); 
  } else {
    /* we need a way of knowing if we are done traversing the queue */
    QNode* head = queue; 
    /* traverse queue and increment length */
    
    while( head->link != queue ) {
      printf("%d->", *(int*)head->content);
      head = head->link;
    }
    printf("%d\n", *(int*)head->content);   
  }
}

int* mallocData( void ) 
{
  int* data = (int*)malloc( sizeof( int ));

  if ( data == NULL ) {
    printf( "Out of memory.\n" );
    exit( EXIT_FAILURE );
  }  
  return data;
}

