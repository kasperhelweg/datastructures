#include "heap_awh_node.h++"
#include "node_awh_modifier.h++"
#include "lazy_root_list.h++"
#include "lazy_root_registry.h++"
#include "lazy_binary_queue.h++"
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
typedef KHJ::thesis::root_list::lazy_root_list<N> S;
typedef KHJ::thesis::root_registry::lazy_root_registry<N, M, S> F;
/* LAZY BINARY QUEUE */
typedef KHJ::thesis::queue::lazy_binary_queue<E, C1, N, M, F> R;
typedef KHJ::thesis::priority_queue::meldable_priority_queue<E, C1, A, N, R>  Q;

typedef KHJ::thesis::benchmark::bench<N, E, Q> B;

int main( )
{
  B benchmarker( comps, "lazy_vec" );
  Q lazy_vec_Q;
  
  std::cout << "---LAZY VEC---" << std::endl;
  //for( int i = 0; i < 2; i++ ) {
    benchmarker.push( lazy_vec_Q );
    lazy_vec_Q.clear( );
    /*
    benchmarker.push( lazy_vec_Q );
    lazy_vec_Q.clear( );
    benchmarker.pop( lazy_vec_Q );
    lazy_vec_Q.clear( );
    benchmarker.emplace( lazy_vec_Q );
    lazy_vec_Q.clear( );
    benchmarker.erase( lazy_vec_Q );
    lazy_vec_Q.clear( );
    benchmarker.decrease_key( lazy_vec_Q );
    lazy_vec_Q.clear( );
    benchmarker.seq_a( lazy_vec_Q ); 
    lazy_vec_Q.clear( );
    */
    //}
 return 0;
}
