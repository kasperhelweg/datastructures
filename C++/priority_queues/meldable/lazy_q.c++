#include "heap_awh_node.h++"
#include "node_awh_modifier.h++"
#include "lazy_root_list_alt.h++"
#include "lazy_root_registry_alt.h++"
#include "lazy_binary_queue.h++"
#include "meldable_priority_queue.h++"

#include "benchmarks.h++"

static long long comps;
template <typename T>
class counting_comparator {
public:  
  //long long& c = comps;
  bool operator()(T const& a, T const& b) const {
    ++comps;
    return a < b;
  }
};

typedef long long E;
typedef std::less<E> C;
typedef counting_comparator<E> CC;
typedef KHJ::thesis::heap_node::heap_awh_node<E> N;
// Node modifier
typedef KHJ::thesis::modifier::node_awh_modifier<E, N, CC> M;
// Allocator
typedef std::allocator<N> A;
// Storage
typedef KHJ::thesis::root_list::lazy_root_list_alt<N> S;
typedef KHJ::thesis::root_registry::lazy_root_registry_alt<N, M, S> F;
/* LAZY BINARY QUEUE */
typedef KHJ::thesis::queue::lazy_binary_queue<E, CC, N, M, F> R;
typedef KHJ::thesis::priority_queue::meldable_priority_queue<E, CC, A, N, R> Q;

typedef KHJ::thesis::benchmark::bench<N, E, Q> B;

int main( )
{
  B benchmarker( comps, "lazy" );
  
  Q lazy_Q;
  Q lazy_Q1;
  
  benchmarker.push( lazy_Q );
  lazy_Q.clear( );
 
  lazy_Q.push( 10 );
  std::cout << lazy_Q.pop() << std::endl;  
  /*
    std::cout << "---LAZY LIST---" << std::endl;  
    //for( int i = 0; i < 2; i++ ) {
    benchmarker1.push( lazy_Q );
    lazy_Q.clear( );
    /*
    benchmarker1.pop( lazy_Q );
    lazy_Q.clear( );
    benchmarker1.emplace( lazy_Q );
    lazy_Q.clear( );
    benchmarker1.erase( lazy_Q );
    lazy_Q.clear( );
    benchmarker1.decrease_key( lazy_Q ); 
    lazy_Q.clear( );
    benchmarker1.seq_a( lazy_Q ); 
    lazy_Q.clear( );
    benchmarker1.seq_b( lazy_Q, lazy_Q1 ); 
    lazy_Q.clear( );
    lazy_Q1.clear( );
  */
  //}
 
 return 0;
}
