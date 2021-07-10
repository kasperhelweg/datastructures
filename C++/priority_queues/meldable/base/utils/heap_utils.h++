#ifndef THESIS_HEAP_UTILS
#define THESIS_HEAP_UTILS
#include <stdlib.h>
#include <math.h>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
namespace KHJ {
  namespace thesis {
    namespace utils {
      template<typename N, typename M>
      class pfb {
        typedef N node_type; 
        typedef M modifier_type; 
        
      public:
        //static std::deque<N*> heap;

        static typename node_type::value_type value( N* R )
        {
          return  modifier_type::val( R );
        }

        static std::deque<N*> breadth_traverse( N* R )
        {
          //std::cout << "TRAVERSE" << std::endl;; 
          std::deque<N*> aux;
          std::deque<N*> b;
          
          aux.push_back( R ); b.push_back( R );
                    
          int l = (*R).height( );
          for( int i = 0; i != l; i++ ) {
            for( int j = 0; j != pow( 2, i ); j++ ) {
              N* T = aux.front( );
              N* P = T->left_child( );
              N* Q = T->right_child( );
          
              aux.push_back( P ); b.push_back( P );
              aux.push_back( Q ); b.push_back( Q );
                
              aux.pop_front( );
            }
          }
          aux.clear( );
          return b;
        }

        static void assert_heap( N* R, bool hp = true  )
        {
          std::deque<N*> bf = breadth_traverse( R );
          assert( bf.size( ) == (pow( 2, (*R).height( ) + 1 ) - 1) );
          
          int l = floor( log2( bf.size( ) - 1 ) );
          int h = 0;
          
          for (auto S = bf.begin( ); S != bf.end( );) {
            for( int i = 0; i != pow(2,h); i++ ) {
              if( h != l) {
                if( h == 0 ){
                  assert( (*S)->is_root( ) );
                  assert((*S)->is_left( ));
                } else {
                  // assert heap prop here.
                  if( hp ) {
                    assert( *(*S) <= *((*S)->left_child( )) ); 
                    assert( *(*S) <= *((*S)->right_child( )) ); 
                  }
                  assert((*S)->left_child( )->is_left( ));
                  assert((*S)->right_child( )->is_right( ));
                }
              } else {
                //std::cout << h << std::endl;
                assert((*S)->is_leaf());
              }
              S++;
            }
            h++;
          }
        }
           
        static N* build_and_inject( int h )
        {
          std::deque<N*> aux;
          
          // Construct root
          int nn = pow( 2, h + 1 ) - 1;
          int rv = rand( ) % (nn * 3) + 0;
          
          node_type* R = new node_type( rv );
          aux.push_front( R );
          
          for( int i = 0; i != h; i++ ) {
            for( int j = 0; j != pow(2,i); j++ ) {
              node_type* S = aux.front( );
              aux.pop_front( );
              
              // cons
              node_type* P = new node_type( (rand( ) % nn * pow(2,i) + 0) + 
                                            (rand( ) % nn + 0), 0 );
              node_type* Q = new node_type( (rand( ) % nn * pow(2,i) + 0) + 
                                            (rand( ) % nn + 0), 1 );
              
              modifier_type::join( S, P, Q );
          
              assert(S->left_child( ) == P);
              assert(S->right_child( ) == Q);

              aux.push_back( P );
              aux.push_back( Q );
            }
          }
          aux.clear( );
          //heap.push_front( R );
          
          // Restore heap property
          std::deque<N*> bh = breadth_traverse( R );
                    
          for (auto S = bh.begin(); S != bh.end(); S++) {
            modifier_type::siftup_( *S );
          }
          R = R->find_root( );
          return R;
        }
        
        static N* replace_rand( N* R )
        {
          std::deque<N*> bf = breadth_traverse( R );

          int r = rand( ) % bf.size( ) + 0;
          node_type* O = new node_type( r );
          N* P         = bf[r];          
          
          modifier_type::replace( P, O );     
          delete P; P = nullptr;   
                   
          modifier_type::siftup_( O );
          modifier_type::siftdown_( O );
   
          return O->find_root( );
        }
    

        static void clear_heap( N* R )
        {
          std::deque<N*> bh = breadth_traverse( R );
          for (auto n = bh.begin(); n != bh.end();) {
            delete *n; *n = nullptr;
            n = bh.erase( ( n ) );            
          }
        }

        static void breadth_first_draw( N* R )
        {
          static std::string def_color  = "\033[0m";
          static std::string color      = "\033[36m";
          static std::string null_color = "\033[34m";
          
          std::deque<N*> heap = breadth_traverse( R );
          
          int h = 0;
          int l = floor( log2( heap.size( ) - 1 ) );
          int off = l * 10;

          std::cout << "-------------------------------" << std::endl; 
          for (auto n = heap.begin( ); n != heap.end( );) {
            for( int i = 0; i != pow( 2, h ); i++ ) {
              
              std::cout << (*n)->element() << " "; 
              
              n++;
            }
            std::cout << std::endl;
            h++;
            l--;
          }
           std::cout << "-------------------------------" << std::endl; 
        }
      };
    }
  }
}
#endif
