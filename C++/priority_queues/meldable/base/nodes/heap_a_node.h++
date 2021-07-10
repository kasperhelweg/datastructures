

/**
 * Desc : A two-pointer basic heap node used in a perfect binary heap.
 * Auth : KHJ
 * Ref  :
 * 
 *     R >|
 *   >/ \<
 *   S > O
 *  /   /
 *
 * @author KHJ
 *
 */
#ifndef THESIS_HEAP_A_NODE
#define THESIS_HEAP_A_NODE
#include <assert.h>
//#include <memory>
#include <math.h>
#include "node_a_modifier.h++"
namespace KHJ {
  namespace thesis {
    namespace heap_node {  
      template <typename E>        
      class heap_a_node {    

      public:
        // maybe private ?
        typedef E value_type;
        typedef heap_a_node<E> N;
        
        explicit heap_a_node( const E& ); 
        explicit heap_a_node( const E&, bool ); 
        ~heap_a_node( ); 

        // Operators
        inline bool  operator<( const N& ) const;
        inline bool  operator>( const N& ) const;
        inline bool operator==( const N& ) const;
        inline bool operator!=( const N& ) const;
        inline bool operator<=( const N& ) const;
        inline bool operator>=( const N& ) const;

        // Accessors
        bool     is_root( ) const;
        bool     is_leaf( ) const;
        bool     is_left( ) const;
        bool    is_right( ) const;
        int       height( ) const;
        int         size( ) const;
        N*        parent( ) const;
        N*    left_child( ) const;
        N*   right_child( ) const;
        N*     find_root( ) const;
        E        element( ) const;
        
      private:
        E    element_;      
        bool   color_;
        N*      left_;
        N*     right_;

        // Should be friends will all modifier types...
        template<typename N, typename C> 
        friend class KHJ::thesis::modifier::node_a_modifier;
      };
    }
  }
}
#include "heap_a_node.i++"
#endif
