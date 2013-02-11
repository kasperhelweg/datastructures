#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void buildList( Listnode** );
void prependToList( Listnode** );
int match( Data );
void printList( Listnode* );
int* mallocData( void ); 
/*
  This is a test for the linked list implementation. Very much not complete.
 */

int main( void )
{ 
  /* Initial list */
  Listnode* list = NULL;
  void* node = NULL;
  /* Match function pointer */
  int (*fp)( Data ) = NULL;  
  fp = &match;
  
  /* printf( "Head of list: %d\n", *(int*)head( list ) ); */ 

  printf( "~Build list with append~\n" );
  printf( "Length of list: %d\n", length( list ) ); 
  buildList( &list );  
  printList( list ); 
  printf( "Length of list: %d\n", length( list ) ); 
  printf( "Head of list: %d\n", *(int*)head( list ) ); 

  printf( "\n" ); 

  printf( "~Prepend~\n" );  
  prependToList( &list );
  printList( list ); 
  printf( "Length of list: %d\n", length( list ) ); 
  printf( "Head of list: %d\n", *(int*)head( list ) ); 

  printf( "\n" ); 

  printf( "~Remove~\n" );  
  
  node = remv( &list, fp );
  if ( node ) { free( node ); node = NULL; }

  printList( list ); 

  return 0;
} 

void buildList( Listnode** head )
{
  int i = 0;
  
  /* Build the list, displaying length */
  while( i < 10 ) {
    int* x = mallocData( );
    Data data = x;
    
    *x = i;
    append( head, data );
    
    ++i;
  }
}

void prependToList( Listnode** head )
{  
  int* x = mallocData( );
  Data data = x;
  *x = 11;
  
  prepend( head, data);
}

int match( Data data )
{
  if ( *(int*)data == 2 )
    {
      return 1;
    }
  
  return 0;
}

void printList( Listnode* head )
{
  printf( "List is: " );

  while ( head ){
    printf( "%d ", *(int*)(head->content) );
    head = head->next;
  }  
    printf( "\n" );
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

