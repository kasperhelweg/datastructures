#include <iostream>
#include <string>
#include "forward_list.h++"
#include <iterator>
#include <algorithm>

typedef std::string E;
typedef KHJ::thesis::forward_list<E> L;

/* can't pass const since using output iterators. could if using const iterators */
void list( L& f_list )
{  
  for ( auto i : f_list ) { std::cout << i << std::endl; }
  std::cout << "" << std::endl;
}

/* can pass const since no mods. */
void list2( const L& f_list )
{  
  std::cout << "LIST " << std::endl;
  std::cout << "Front: " << f_list.front( ) << std::endl;
  std::cout << "LIST END " << std::endl;
}

/* Destroys everything! */
void list3( L f_list )
{  
  std::cout << "LIST " << std::endl;
  std::cout << "Front: " << f_list.front( ) << std::endl;
  std::cout << "LIST END " << std::endl;
}

int main( )
{ 
  // Instance
  L f_list;
  
  // Check that list is empty
  if( f_list.empty( ) ) {
    std::cout << "empty\n" << std::endl;
  }
  
  // Push a few sweet names
  f_list.push_front( "Zarima" );
  f_list.push_front( "<3" );
  f_list.push_front( "Kasper" );
  
  L::iterator result = std::find( f_list.begin( ), f_list.end( ), "Zarima" );
  if( result != f_list.end( ) ) {
    std::cout << "FIND: " << *result << std::endl; }
  
  list( f_list );
  
  std::cout << "Front: " << f_list.front( ) << std::endl;
  f_list.pop_front( );
  std::cout << "Front: " << f_list.front( ) << std::endl;
  f_list.pop_front( );
  std::cout << "Front: " << f_list.front( ) << std::endl;
  f_list.pop_front( );
    
  //std::cout << "Post front: "      << *(++f_list.begin( )) << std::endl;
  //std::cout << "Post post Front: " << *(f_list.begin( ))   << std::endl;
  
  // Iterators
  
  typedef const L::iterator::pointer val_t;    
  //this causes the dereference to fail, as it should : typedef const L::const_iterator::pointer val_t;     
  L::const_iterator::value_type s = "kasper";
 
  
  val_t val = &s;
  *val = "hello";
  std::cout << "VAL: " << *val << std::endl;
  
  //typedef L::iterator::difference_type diff_t;    

  return 0;
}
