/*
  g++ -O3 -I ./utils/ -I ./nodes/ -I ./registries -I ./registries/stores/ -I ./registries/policies -I ./realizers -I ./containers -I ./ -std=c++11 -o priority_queues.out priority_queues.c++
*/

#include <iostream>
#include <assert.h>
#include <time.h>
#include <ctime>
#include <sys/time.h>
#include <algorithm>

#include "binomial_heap.hpp"
#include "fibonacci_heap.hpp"

#include "heap_a_node.h++"
#include "node_a_modifier.h++"
#include "heap_awh_node.h++"
#include "node_awh_modifier.h++"

#include "paper_store.h++"
#include "lazy_store.h++"

#include "numeral_consolidation_policy.h++"
#include "eager_consolidation_policy.h++"
#include "lazy_consolidation_policy.h++"

#include "root_registry.h++"

#include "numeral_binary_queue.h++"
#include "eager_binary_queue.h++"
#include "lazy_binary_queue.h++"

#include "meldable_priority_queue.h++"

typedef long E1;
typedef std::less<E1> C1;
typedef KHJ::thesis::heap_node::heap_a_node<E1> N1;
typedef KHJ::thesis::heap_node::heap_awh_node<E1> N2;
// Node modifier
typedef KHJ::thesis::modifier::node_a_modifier<N1, C1> M1;
typedef KHJ::thesis::modifier::node_awh_modifier<N2, C1> M2;
// Allocator
typedef std::allocator<N1> A1;
typedef std::allocator<N2> A2;
// Storage
typedef KHJ::thesis::store::paper_store<N1> S1;
typedef KHJ::thesis::store::lazy_store<N2> S2;

/* NUMERAL BINARY QUEUE */
// Policy policy
typedef KHJ::thesis::policy::numeral_consolidation_policy<N1, M1, S1> J1;
// Registry
typedef KHJ::thesis::registry::root_registry<N1, M1, S1, J1> F1;
// eager binary queue
typedef KHJ::thesis::queue::numeral_binary_queue<E1, C1, N1, M1, F1> R1;
typedef KHJ::thesis::priority_queue::meldable_priority_queue<E1, C1, A1, N1, R1> Q1;

/* EAGER BINARY QUEUE */
// Policy policy
typedef KHJ::thesis::policy::eager_consolidation_policy<N1, M1, S1> J2;
// Registry
typedef KHJ::thesis::registry::root_registry<N1, M1, S1, J2> F2;
// eager binary queue
typedef KHJ::thesis::queue::eager_binary_queue<E1, C1, N1, M1, F2> R2;
typedef KHJ::thesis::priority_queue::meldable_priority_queue<E1, C1, A1, N1, R2> Q2;

/* LAZY BINARY QUEUE */
// Policy policy
typedef KHJ::thesis::policy::lazy_consolidation_policy<N2, M2, S2> J3;
// Registry
typedef KHJ::thesis::registry::root_registry<N2, M2, S2, J3> F3;
// eager binary queue
typedef KHJ::thesis::queue::lazy_binary_queue<E1, C1, N2, M2, F3> R3;
typedef KHJ::thesis::priority_queue::meldable_priority_queue<E1, C1, A2, N2, R3> Q3;


int main( ) 
{
  Q1 magic_Q;
  Q2 eager_Q;
  Q3  lazy_Q;

  boost::heap::binomial_heap<E1>  pq_b;
  boost::heap::fibonacci_heap<E1> pq_f;
  
  E1 elements = 1000000;
  std::vector<E1> data;
  for (E1 i = elements; i >= 1; --i) data.push_back( i );
  std::random_shuffle ( data.begin( ), data.end( ) );

  clock_t cpu0;
  clock_t cpu1;
  double cpu_time;

  std::cout << std::endl ; 
  std::cout << "----------------------MAGIC QUEUE----------------------" << std::endl;
  
  std::vector<N1*> nodes;
  std::vector<N1*> nodes_awh;
  cpu0  = clock( );
  for( auto it = data.begin( ) ; it != data.end( ) ; it++ ) {
    nodes.push_back( magic_Q.emplace( *it ) );
  }
  cpu1  = clock();
  cpu_time = static_cast<double>( cpu1 - cpu0 )  / CLOCKS_PER_SEC;

  std::cout << "-----------------" << std::endl ; 
  std::cout << "CPU Push( ): " << cpu_time * 1000 << std::endl;
  std::cout << "-----------------" << std::endl ; 
  std::cout << std::endl ; 
  
  std::random_shuffle ( nodes.begin( ), nodes.end( ) );
  cpu0  = clock( );
  for( int i = 1; i < elements - 5  ; ++i ) {
    magic_Q.pop( );
    //magic_Q.erase( nodes.back( ) );
    //nodes.pop_back( );
  }
  cpu1  = clock();
  cpu_time = static_cast<double>( cpu1 - cpu0 )  / CLOCKS_PER_SEC;
  //assert( nodes.size() == 1 );
  
  std::cout << "-----------------" << std::endl ; 
  std::cout << "CPU Pop( ): " << cpu_time * 1000 << std::endl;
  std::cout << "-----------------" << std::endl ; 
  std::cout << std::endl ; 
  
  std::cout << std::endl ; 
  std::cout << "----------------------EAGER BINARY QUEUE----------------------" << std::endl;
  
  cpu0  = clock( );
  for( auto it = data.begin( ) ; it != data.end( ) ; it++ ) {
    eager_Q.emplace( *it );
  }
  cpu1  = clock();
  cpu_time = static_cast<double>( cpu1 - cpu0 )  / CLOCKS_PER_SEC;

  std::cout << "-----------------" << std::endl ; 
  std::cout << "CPU Push( ): " << cpu_time * 1000 << std::endl;
  std::cout << "-----------------" << std::endl ; 
  std::cout << std::endl ; 
    
  cpu0  = clock( );
  for( int i = 1; i < elements - 5  ; ++i ) {
    eager_Q.pop( );
  }
  cpu1  = clock();
  cpu_time = static_cast<double>( cpu1 - cpu0 )  / CLOCKS_PER_SEC;
  //assert( nodes.size() == 1 );
  
  std::cout << "-----------------" << std::endl ; 
  std::cout << "CPU Pop( ): " << cpu_time * 1000 << std::endl;
  std::cout << "-----------------" << std::endl ; 
  std::cout << std::endl; 

  std::cout << std::endl; 
  std::cout << "----------------------LAZY BINARY QUEUE----------------------" << std::endl;
  
  cpu0  = clock( );
  for( auto it = data.begin( ) ; it != data.end( ) ; it++ ) {
    lazy_Q.emplace( *it );
  }
  cpu1  = clock();
  cpu_time = static_cast<double>( cpu1 - cpu0 )  / CLOCKS_PER_SEC;

  std::cout << "-----------------" << std::endl ; 
  std::cout << "CPU Push( ): " << cpu_time * 1000 << std::endl;
  std::cout << "-----------------" << std::endl ; 
  std::cout << std::endl ; 
  

  std::cout << std::endl ; 
  std::cout << "----------------------BOOST BINOMIAL QUEUE----------------------" << std::endl;
  cpu0  = clock( );
  for( auto it = data.begin( ) ; it != data.end( ) ; it++ ) {
    pq_b.push( *it );
  }
  cpu1  = clock();
  cpu_time = static_cast<double>( cpu1 - cpu0 )  / CLOCKS_PER_SEC;

  std::cout << "-----------------" << std::endl ; 
  std::cout << "CPU Push( ): " << cpu_time * 1000 << std::endl;
  std::cout << "-----------------" << std::endl ; 
  std::cout << std::endl ; 

  cpu0  = clock( );
  for( auto it = data.begin( ) ; it != data.end( ) ; it++ ) {
    pq_b.pop( );
  }
  cpu1  = clock();
  cpu_time = static_cast<double>( cpu1 - cpu0 )  / CLOCKS_PER_SEC;

  std::cout << "-----------------" << std::endl ; 
  std::cout << "CPU Pop( ): " << cpu_time * 1000 << std::endl;
  std::cout << "-----------------" << std::endl ; 
  std::cout << std::endl ; 

  std::cout << std::endl ; 
  std::cout << "----------------------BOOST FIB HEAP----------------------" << std::endl;
  cpu0  = clock( );
  for( auto it = data.begin( ) ; it != data.end( ) ; it++ ) {
    pq_f.push( *it );
  }
  cpu1  = clock();
  cpu_time = static_cast<double>( cpu1 - cpu0 )  / CLOCKS_PER_SEC;

  std::cout << "-----------------" << std::endl ; 
  std::cout << "CPU Push( ): " << cpu_time * 1000 << std::endl;
  std::cout << "-----------------" << std::endl ; 
  std::cout << std::endl ; 

  cpu0  = clock( );
  for( auto it = data.begin( ) ; it != data.end( ) ; it++ ) {
    pq_f.pop( );
  }
  cpu1  = clock();
  cpu_time = static_cast<double>( cpu1 - cpu0 )  / CLOCKS_PER_SEC;

  std::cout << "-----------------" << std::endl ; 
  std::cout << "CPU Pop( ): " << cpu_time * 1000 << std::endl;
  std::cout << "-----------------" << std::endl ; 
  std::cout << std::endl ; 
  
  




  /*
  std::vector<E1> sort_vec;
  cpu0  = clock( );
  for( int i = 1; i <= elements-5  ; ++i ) {
    sort_vec.push_back( magic_Q.pop( ) );
  }
  cpu1  = clock();
  cpu_time = static_cast<double>( cpu1 - cpu0 )  / CLOCKS_PER_SEC;
  assert( sort_vec.size() == elements - 5 );
  assert( std::is_sorted( sort_vec.begin(),sort_vec.end() ));

  std::cout << "-----------------" << std::endl ; 
  std::cout << "CPU Pop( ): " << cpu_time * 1000 << std::endl;
  std::cout << "-----------------" << std::endl ; 
  std::cout << std::endl ; 
  */
  return 0;
}

