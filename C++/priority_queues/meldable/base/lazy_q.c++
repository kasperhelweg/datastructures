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
typedef counting_comparator<E> C1;
typedef KHJ::thesis::heap_node::heap_awh_node<E> N;
// Node modifier
typedef KHJ::thesis::modifier::node_awh_modifier<E, N, C1> M;
// Allocator
typedef std::allocator<N> A;
// Storage
typedef KHJ::thesis::root_list::lazy_root_list_alt<N> S1;
typedef KHJ::thesis::root_registry::lazy_root_registry_alt<N, M, S1> F1;
/* LAZY BINARY QUEUE */
typedef KHJ::thesis::queue::lazy_binary_queue<E, C1, N, M, F1> R1;
typedef KHJ::thesis::priority_queue::meldable_priority_queue<E, C1, A, N, R1> Q1;


typedef KHJ::thesis::benchmark::bench<N, E, Q1> B1;

int main( )
{
  B1 benchmarker1( comps, "lazy" );
  
  Q1 lazy_Q;
  Q1 lazy_Q1;

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
