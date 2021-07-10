#include "heap_awh_node.h++"
#include "node_awh_modifier.h++"
#include "regular_root_table.h++"
#include "regular_root_registry.h++"
#include "regular_binary_queue.h++"
#include "meldable_priority_queue.h++"

#include "benchmarks.h++"

#include <bitset>

static long long comps;
template <typename T>
class counting_comparator {
public:  
  long long& c = comps;
  bool operator()(T const& a, T const& b) const {
    ++comps;
    return a < b;
  }
};

typedef long long E;
typedef std::less<E> C;
typedef counting_comparator<E> C1;
typedef KHJ::thesis::heap_node::heap_awh_node<E> N;
// Node modifier
typedef KHJ::thesis::modifier::node_awh_modifier<E, N, C1> M;
// Allocator
typedef std::allocator<N> A;
// Storage
typedef KHJ::thesis::root_table::regular_root_table<N> S;
/* LAZY BINARY QUEUE */
typedef KHJ::thesis::root_registry::regular_root_registry<N, M, S> F;
// eager binary queue
typedef KHJ::thesis::queue::regular_binary_queue<E, C1, N, M, F> R;
typedef KHJ::thesis::priority_queue::meldable_priority_queue<E, C1, A, N, R> Q;

typedef KHJ::thesis::benchmark::bench<N, E, Q> B;

int main( )
{

  B benchmarker( comps, "regular" );
  Q regular_Q;
  Q regular_Q1;
  
  std::cout << "---REGULAR---" << std::endl;
  //for( int i = 0; i < 2; i++ ) {
    benchmarker.push( regular_Q );
    regular_Q.clear( );
    /*
    benchmarker.pop( regular_Q );
    regular_Q.clear( );
    benchmarker.emplace( regular_Q );
    regular_Q.clear( );
    benchmarker.erase( regular_Q );
    regular_Q.clear( );
    benchmarker.decrease_key( regular_Q );
    regular_Q.clear( );
    benchmarker.seq_a( regular_Q ); 
    regular_Q.clear( );
    benchmarker.seq_b( regular_Q, regular_Q1 ); 
    regular_Q.clear( );
    regular_Q1.clear( );
    */
    //}

  //


  
  // TINY
  
  /*
  for( long long i = 0; i < 30; i++ ) {
    regular_Q.push( i );
  }

  for( long long i = 27; i < 48; i++ ) {
    regular_Q1.push( i );
  }
  */
  

  
  // MEDIUM
  
  
  /*
  for( long long i = 0; i < 1210; i++ ) {
    regular_Q.push( i );
  }
  
  for( long long i = 1210; i < 1816; i++ ) {
    regular_Q1.push( i );
  }
  */
  
  
  // LARGE
  
  
  /*
  for( long long i = 0; i < 80000; i++ ) {
    regular_Q.push( i );
  }
  
  for( long long i = 80000; i < 100000; i++ ) {
    regular_Q1.push( i );
  }
  */

  /*
  
  std::cout << "BEGIN------------------" << std::endl << std::endl;
  regular_Q.print( );
  regular_Q1.print( );

  regular_Q.meld( regular_Q1 );

  std::cout << "END------------------" << std::endl << std::endl;
  regular_Q.print( );
  regular_Q1.print( );
  */
  
  /*
    
  regular_Q.clear();
  regular_Q1.clear();
  
  */
  

  return 0;
}
