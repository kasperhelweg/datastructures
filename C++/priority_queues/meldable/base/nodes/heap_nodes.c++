// g++ -O3 -I ../utils/ -I ./ -std=c++11 -o heap_nodes.out heap_nodes.c++

#include <iostream>
#include <assert.h>
#include <time.h>
#include <deque>

#include "heap_a_node.h++"
#include "node_a_modifier.h++"
#include "heap_utils.h++"

typedef int E1;
typedef KHJ::thesis::heap_node::heap_a_node<E1> N1;

typedef std::less<N1> C1;
typedef KHJ::thesis::modifier::node_a_modifier<N1, C1> M1;

// Utils
typedef KHJ::thesis::utils::pfb<N1, M1> pfb_N1;
//template<> std::deque<N1*> pfb_N1::heap = { };

int main( )
{
  typedef M1 modifier;
  
  N1 node_a( 4 );
  N1 node_b( 5 );

  assert( node_a < node_b );
  assert( node_a == node_a );
  
  assert( node_b > node_a );
  assert( !(node_a > node_b) );
  
  assert( node_a <= node_b );
  assert( !(node_a >= node_b) );
  
  assert( node_b >= node_a );
  assert( !(node_b <= node_a) );
  
  std::srand( (unsigned) time(NULL) );
  
  
  for( int i = 0; i != 1000; i++ ) {
    N1* root = pfb_N1::build_and_inject( 10 );     
    pfb_N1::assert_heap( root );
    pfb_N1::clear_heap( root );
  }
  std::cout << "DONE BUILDING" << std::endl;

  N1* root;
  std::cout << "START REPLACE" << std::endl;
  for( int k = 0; k != 16; k++ ) {
 
    root = pfb_N1::build_and_inject( k );
    assert( root->is_root( ));
    pfb_N1::assert_heap( root  );
    assert( root->is_root( ));
    for( int i = 0; i != 1000; i++ ) {
      root = pfb_N1::replace_rand( root );
      pfb_N1::assert_heap( root );
    }
    pfb_N1::clear_heap( root );
  }
     
  //assert( modifier::compare_( node_a, node_b ) );
  //std::cout << modifier::val( &node_a ) << std::endl;
  //std::cout << pfb_N1::value( &node_a ) << std::endl;
  return 0;
}
