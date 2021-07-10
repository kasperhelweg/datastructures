#include <iostream>
#include <fstream>
#include <assert.h>
#include <time.h>
#include <ctime>
#include <sys/time.h>
#include <algorithm>

#include "benchmarks.h++"
#include "binomial_heap.hpp"
#include "fibonacci_heap.hpp"
#include "pairing_heap.hpp"


static long long comps;
template <typename T>
struct node
{
  T key;
  node(T i) : key(i) { }
};

template <typename N>
class counting_comparator {
public:
  counting_comparator( )
  {
    long long& c = comps;
  }
  
  bool operator()(N const& a, N const& b) const {
    ++comps;
    return a.key < b.key;
  }
};

typedef long long E;
typedef counting_comparator<node<E>> C1;
typedef boost::heap::binomial_heap<node<E>, boost::heap::compare<C1>>  Q_bin;
typedef Q_bin::handle_type binomial_node;
typedef boost::heap::fibonacci_heap<node<E>, boost::heap::compare<C1>> Q_fib;

typedef Q_fib::handle_type fibonacci_node;

typedef KHJ::thesis::benchmark::bench<fibonacci_node, E, Q_fib> B;
typedef KHJ::thesis::benchmark::bench<binomial_node, E, Q_bin> B1;

int main( ) 
{
  Q_bin pq_b;
  Q_bin pq_b1;
  Q_fib pq_f;
  Q_fib pq_f1;
  B benchmarker( comps, "fibonacci" );
  B1 benchmarker1( comps, "binomial" );
  
  std::cout << "---BOOST BINOMIAL---" << std::endl;
  //for( int i = 0; i < 2; i++ ) {  
  /*
    benchmarker1.pop( pq_b );
    pq_b.clear();
  */
  benchmarker1.emplace( pq_b );
  pq_b.clear();
    /*
    benchmarker1.erase_boost( pq_b );
    pq_b.clear();
    benchmarker1.decrease_key_boost( pq_b );
    pq_b.clear();
    benchmarker1.seq_a_boost( pq_b );
    pq_b.clear();
    benchmarker1.seq_b_boost( pq_b, pq_b1 );
    pq_b.clear();
    */
    //}

  std::cout << "---BOOST FIBONACCI---" << std::endl;
  //for( int i = 0; i < 2; i++ ) {  
  /*
    benchmarker.pop( pq_f );
    pq_f.clear();
  */
  benchmarker.emplace( pq_f );
  pq_f.clear();
    /*
    benchmarker.erase_boost( pq_f );
    pq_f.clear();
    benchmarker.decrease_key_boost( pq_f );
    pq_f.clear();
    benchmarker.seq_a_boost( pq_f );
    pq_f.clear();
    benchmarker.seq_b_boost( pq_f, pq_f1 );
    pq_f.clear();
    */
    //}
  return 0;
}
