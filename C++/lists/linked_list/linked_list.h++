/* Header file for a standard linked list */
// We define two types : A Node type and a List type.
#ifndef __CPHSTL_LINKED_LIST__
#define __CPHSTL_LINKED_LIST__
namespace cphstl 
{
  typedef int Data;

  class list_node
  {
    friend class linked_list;
    
    // Private Data Members
    int key;
    Data data;
    list_node* east;
    list_node* west;
    list_node* north;
    list_node* south;
    
  public:
    // Structors    
    list_node( ) { };
    list_node( int, const Data& );
    
    // Function Members
    int  get_data( void ) const;
    void set_data( const Data& );
    
  private:
    
  };

  class linked_list
  {
    // Private Data Members
    int size_;
    list_node* head_;

  public:
    // Structors    
    linked_list( );

    // Function Member    
    list_node*  
    front( ) const;

    void  
    push_front( int, const Data& );
    
    void  
    pop_front( );

    int   
    size( ) const;

    list_node 
    remove( );
 
  private:
  };
}
#include "linked_list.i++"
#endif
