#include <iostream>
#include "linked_list.h++"

/* Prototypes */
int fun( const cphstl::list_node& );
int fun_inefficient( cphstl::list_node );

void pass_by_value( int );
void pass_by_reference( int& );

int main( )
{
  cphstl::list_node node;

  cphstl::list_node node_b ( 10, 5 );
  
  std::cout << "data at node_b: " << node_b.get_data( ) << std::endl;
  
  node.set_data( 25 );
  std::cout << "adress of node: "      << &node << std::endl;
  std::cout << "value( effifcient ): " << fun( node ) << std::endl;
  std::cout << "value: "               << fun_inefficient( node ) << std::endl;
  
  int a = 0;
  std::cout << "Value of a before pass_by_value: " << a << std::endl;
  pass_by_value( a );
  std::cout << "Value of a after pass_by_value: "  << a << std::endl;  
  
  //int* p = &a;
  std::cout << "Value of a before pass_by_reference: " << a << std::endl;
  pass_by_reference( a );
  std::cout << "Value of a after pass_by_reference: "  << a << std::endl;

  // inC you would do
  // prototype : void pass_by_reference( int* )
  // call      : pass_by_reference( &a );
  // and then dereference in pass_by_reference : *a = 5;
  // or  : int* p = &a;
  // call: pass_by_reference( p )

  /* NEW andDELETE code */
  //cphstl::list_node* node = new cphstl::list_node; 
  //delete node; node = nullptr;
  
  cphstl::linked_list list;
  std::cout << "Size of new list: " << list.size( ) << std::endl;
  list.push_front( 0, 10 );
  std::cout << "Size of 1-elem list: " << list.size( ) << std::endl;
  list.push_front( 1, 15 );
  std::cout << "Size of 2-elem list: " << list.size( ) << std::endl;

  std::cout << "About to pop: " << (list.front( ))->get_data() << std::endl;
  list.pop_front( );
  std::cout << "Size after pop: " << list.size( ) << std::endl;
  
  std::cout << "About to pop: " << (list.front( ))->get_data() << std::endl;
  list.pop_front( );
  std::cout << "Size after pop: " << list.size( ) << std::endl;
    
  list.pop_front( );
  std::cout << "Size after pop: " << list.size( ) << std::endl;
  
  
  return 0;
}

int fun( const cphstl::list_node& node )
{
  std::cout << &node << std::endl;
  return node.get_data( );
}

int fun_inefficient( cphstl::list_node node )
{
  std::cout << &node << std::endl;
  return node.get_data( );
}

void pass_by_value( int a )
{
  a = 10;
}

void pass_by_reference( int& a )
{
  a = 10;
}
