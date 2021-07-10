//g++ -O3 -I ../utils/ -I ../nodes/ -I ./stores/ -I ./policies -I ./ -std=c++11 -o registry.out registry.c++
#include <iostream>
#include <assert.h>
#include <time.h>
#include <ctime>
#include <sys/time.h>
#include <algorithm>
#include <queue>

#include "heap_a_node.h++"
#include "heap_awh_node.h++"
#include "node_a_modifier.h++"
#include "node_awh_modifier.h++"
#include "paper_store.h++"
#include "lazy_store.h++"
#include "root_registry.h++"

#include "lazy_consolidation_policy.h++"
#include "eager_consolidation_policy.h++"
#include "numeral_consolidation_policy.h++"


long long comps = 0;
template <typename T>
class counting_comparator {
public:

  bool operator()(T const& a, T const& b) const {
    ++comps;
    return a < b;
  }
};

// Node
typedef long E1;
typedef std::less<E1> C1;
typedef counting_comparator<E1> C2;
typedef KHJ::thesis::heap_node::heap_a_node<E1> N1;
typedef KHJ::thesis::heap_node::heap_awh_node<E1> N2;

// Node modifier
typedef KHJ::thesis::modifier::node_a_modifier<N1, C2> M1;
typedef KHJ::thesis::modifier::node_awh_modifier<N2, C2> M2;
// Storage
typedef KHJ::thesis::store::paper_store<N1> S1;
typedef KHJ::thesis::store::lazy_store<N2> S2;
// Registries
typedef KHJ::thesis::policy::numeral_consolidation_policy<N1, M1, S1> J1;
typedef KHJ::thesis::registry::root_registry<N1, M1, S1, J1> R1;

typedef KHJ::thesis::policy::eager_consolidation_policy<N1, M1, S1> J2;
typedef KHJ::thesis::registry::root_registry<N1, M1, S1, J2> R2;

typedef KHJ::thesis::policy::lazy_consolidation_policy<N2, M2, S2> J3;
typedef KHJ::thesis::registry::root_registry<N2, M2, S2, J3> R3;


int main( )
{
  R1 registry;
  R2 eager_registry;
  R3 lazy_registry;
  std::priority_queue<E1, std::vector<E1>, std::greater<E1> > mypq;

  E1 elements = 10000000;
  std::vector<E1> data;
  for (E1 i = elements; i >= 1; --i) data.push_back( i );
  std::random_shuffle ( data.begin( ), data.end( ) );
  
  std::vector<N1*> nodes;
  std::vector<N2*> nodes_awh;
 

  //----------------------PAPER REGISTRY----------------------
  for( auto it = data.begin( ) ; it != data.end( ) ; it++ ) {
    N1* S = new N1( *it );
    nodes.push_back( S );
  }
  
  std::cout << std::endl ; 
  std::cout << "----------------------PAPER REGISTRY----------------------" << std::endl;
  clock_t cpu0  = clock( );

  for( auto it = nodes.begin( ) ; it != nodes.end( ) ; it++ ) {
    registry.insert( *it );
    registry.consolidate( );
  }
  
  clock_t cpu1  = clock();
  double cpu_time = static_cast<double>( cpu1 - cpu0 )  / CLOCKS_PER_SEC;

  std::cout << "-----------------" << std::endl ; 
  std::cout << "CPU Push( ): " << cpu_time * 1000 << std::endl;
  std::cout << "compares: " << comps - elements + 1 << std::endl ; 
  std::cout << "-----------------" << std::endl ; 
  std::cout << std::endl ;   
  registry.print( );
  std::cout << std::endl ; 

  //----------------------PAPER REGISTRY EXTRACT----------------------
  comps = 0;
  cpu0  = clock( );
  for( int i = 1; i <= elements - 5  ; ++i ) {
    N1* S = registry.extract( );
    //delete S; S = nullptr;
  }
  cpu1  = clock();
  cpu_time = static_cast<double>( cpu1 - cpu0 )  / CLOCKS_PER_SEC;
  
  std::cout << "-----------------" << std::endl ; 
  std::cout << "CPU Pop( ): " << cpu_time * 1000 << std::endl;
  std::cout << "compares: " << comps  << std::endl ;
  std::cout << "-----------------" << std::endl ; 
  std::cout << std::endl ; 
  registry.print( );
  std::cout << std::endl ; 

  nodes.clear();
 
  //----------------------EAGER REGISTRY----------------------

  std::cout << "----------------------EAGER REGISTRY----------------------" << std::endl;
  
  for( auto it = data.begin( ) ; it != data.end( ) ; it++ ) {
    N1* S = new N1( *it );
    nodes.push_back( S );
  }

  comps = 0;
  cpu0  = clock( );
  for( auto it = nodes.begin( ) ; it != nodes.end( ) ; it++ ) {
    eager_registry.insert( *it );
    eager_registry.consolidate( );
  }
  cpu1  = clock( );

  cpu_time = static_cast<double>( cpu1 - cpu0 )  / CLOCKS_PER_SEC;
  
  std::cout << "-----------------" << std::endl ; 
  std::cout << "CPU Push( ) - Eager: " << cpu_time * 1000 << std::endl;
  std::cout << "compares: " << comps - elements + 1 << std::endl ;
  std::cout << "-----------------" << std::endl ; 
  std::cout << std::endl ; 

  eager_registry.print( );
  std::cout << std::endl ; 

  //----------------------EAGER REGISTRY EXTRACT----------------------

  comps = 0;
  cpu0  = clock( );
  std::random_shuffle ( nodes.begin( ), nodes.end( ) );
  for( int i = 1; i <= elements-5  ; ++i ) {
    N1* S = eager_registry.extract( );
    //std::cout << S->element( ) << std::endl ; 
    //delete S; S = nullptr;
  }
  cpu1  = clock( );

  cpu_time = static_cast<double>( cpu1 - cpu0 )  / CLOCKS_PER_SEC;
  
  std::cout << "-----------------" << std::endl ; 
  std::cout << "CPU Pop( ) - Eager: " << cpu_time * 1000 << std::endl;
  std::cout << "compares: " << comps << std::endl ;
  std::cout << "-----------------" << std::endl ; 
  std::cout << std::endl ; 

  eager_registry.print( );
  std::cout << std::endl ;

  nodes.clear();

  //----------------------LAZY REGISTRY----------------------

  for( auto it = data.begin( ) ; it != data.end( ) ; it++ ) {
    N2* S = new N2( *it );
    nodes_awh.push_back( S );
  }

  comps = 0;
  cpu0  = clock( );
  for( auto it = nodes_awh.begin( ) ; it != nodes_awh.end( ) ; it++ ) {
    lazy_registry.insert( *it );
  }
  cpu1  = clock( );

  cpu_time = static_cast<double>( cpu1 - cpu0 )  / CLOCKS_PER_SEC;
  
  std::cout << "-----------------" << std::endl ; 
  std::cout << "CPU Push( ) - Lazy: " << cpu_time * 1000 << std::endl;
  std::cout << "compares: " << comps - elements + 1 << std::endl ;
  std::cout << "-----------------" << std::endl ; 
  std::cout << std::endl ; 

  //lazy_registry.print( );
  std::cout << std::endl ; 

  comps = 0;
  cpu0  = clock( );
  for( int i = 1; i <= elements - 5  ; ++i ) {
    //lazy_registry.print( );
    lazy_registry.extract( );
    //std::cout << "EX 2" << std::endl;
    lazy_registry.consolidate( );
  }
  cpu1  = clock( );

  cpu_time = static_cast<double>( cpu1 - cpu0 )  / CLOCKS_PER_SEC;
  
  std::cout << "-----------------" << std::endl ; 
  std::cout << "CPU Pop( ) - Lazy: " << cpu_time * 1000 << std::endl;
  std::cout << "compares: " << comps << std::endl ;
  std::cout << "-----------------" << std::endl ; 
  std::cout << std::endl ; 

  lazy_registry.print( );
  std::cout << std::endl ; 
  
  nodes_awh.clear();
  


  //----------------------STD PQ----------------------

  std::cout << "----------------------STD PQueue----------------------" << std::endl; 
  cpu0  = clock( );
  for( auto it = data.begin( ) ; it != data.end( ) ; it++ ) {
    mypq.push( *it );
  }
  cpu1  = clock( );

  cpu_time = static_cast<double>( cpu1 - cpu0 )  / CLOCKS_PER_SEC;
  
  std::cout << "-----------------" << std::endl ; 
  std::cout << "CPU Push( ) - STD: " << cpu_time * 1000 << std::endl;
  std::cout << "-----------------" << std::endl ; 
  std::cout << std::endl ; 


  cpu0  = clock( );
  for( int i = 1; i <= elements-5  ; ++i ) {
    mypq.pop( );
  }
  cpu1  = clock( );

  cpu_time = static_cast<double>( cpu1 - cpu0 )  / CLOCKS_PER_SEC;
  
  std::cout << "-----------------" << std::endl ; 
  std::cout << "CPU Pop( ) - STD: " << cpu_time * 1000 << std::endl;
  std::cout << "-----------------" << std::endl ; 
  std::cout << std::endl ; 

  return 0;
}
