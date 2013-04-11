#include <stdlib.h>
#include <stdio.h>
#include "list.h"

/*
 * internal prototypes
 ****************************/
Listnode* mallocNode( void );

/*
 * implementation
 ****************************/

/*
 * Append a node to the list
 */
/**
 * Append a node to the linked list.
 *
 * @param head A pointer to the head of the linked list
 *
 */

void append( Listnode** head, Data elem )
{
  /* malloc space for new node and put data in node. make the next->NULL. */
  Listnode* new_node = mallocNode( );
  new_node->content = elem; new_node->next = NULL;
 
  /* follow pointers to the end. */ 
  while ( *head != NULL ) {
    head = &(*head)->next;
  } 

  /* insert new node. */ 
  *head = new_node;
}

/*
 * Prepend a node to the list
 */
void prepend( Listnode** head, Data elem )
{
  /* malloc space for new node. make next point to current head */
  Listnode* new_node =  mallocNode( );  
  new_node->content = elem; new_node->next = *head;

  /* make the new node the new head */
  *head = new_node;
}

/*
 * Remove node from list and return it. 
 * The userprogram is responsible for freeing the memory
*/
void* remv( Listnode** head, int (*match)( Data ))
{
  Listnode* current = *head; 
  Listnode** last = head;
  
  while ( current != NULL && !(*match)( current->content ) ) {
    last = &(current->next);
    current = current->next;
  }
    
  if ( current != NULL ) *last = current->next;
  return current;
}

/*
 * Return the first content element of the list
 */										
Data head( Listnode* head )
{
  return head->content;
}

/*
 * Return lenght of list
 */
int length( Listnode* head )
{  
  int length = 0;

  /* count the length */
  while ( head != NULL ) {
    head = head->next;
    ++length;
  }  

  return length;
}

/*
 * implementation internals
 ****************************/

/*
 * call malloc and cast to type Listnode* 
*/
Listnode* mallocNode( void ) 
{ 
  Listnode* new_node = (Listnode*)malloc( sizeof( Listnode ) );

  if ( new_node == NULL ) {
    printf ( "Out of memory.\n" );
    exit ( EXIT_FAILURE );
  } 
 
  return new_node;
}
