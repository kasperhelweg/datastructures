#include "heap_a_node.h++"
#include "heap_awh_node.h++"
#include "node_a_modifier.h++"
#include "node_awh_modifier.h++"
#include "paper_root_table.h++"
#include "magical_root_registry.h++"
#include "magical_binary_queue.h++"
#include "meldable_priority_queue.h++"

#include "benchmarks.h++"

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
typedef KHJ::thesis::root_table::paper_root_table<N> S;
/* LAZY BINARY QUEUE */
// Registry
typedef KHJ::thesis::root_registry::magical_root_registry<N, M, S> F;
// eager binary queue
typedef KHJ::thesis::queue::magical_binary_queue<E, C1, N, M, F> R;
typedef KHJ::thesis::priority_queue::meldable_priority_queue<E, C1, A, N, R> Q;

// Benchmarking
typedef KHJ::thesis::benchmark::bench<N, E, Q> B;

int main( )
{  
  B benchmarker( comps, "magic" );
  Q magic_Q;

  std::cout << "---MAGIC---" << std::endl;
  //for( int i = 0; i < 2; i++ ) {
  
  benchmarker.push( magic_Q );
  magic_Q.clear( );
  
  /*
  benchmarker.pop( magic_Q );
  magic_Q.clear( );
  benchmarker.emplace( magic_Q );
  magic_Q.clear( );
  benchmarker.erase( magic_Q );
  magic_Q.clear( );
  benchmarker.decrease_key( magic_Q );
  magic_Q.clear( );
  
  benchmarker.seq_a( magic_Q ); 
  magic_Q.clear( );
  */
  //}
  /*
  benchmarker.decrease_cache( magic_Q ); 
  //benchmarker.pop_cache( magic_Q ); 
  magic_Q.clear( );
  */
  return 0;
}
