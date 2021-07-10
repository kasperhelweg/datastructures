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
#ifndef THESIS_HEAP_AWH_NODE
#define THESIS_HEAP_AWH_NODE
#include <assert.h>
//#include <memory>
#include <math.h>
#include "node_awh_modifier.h++"
namespace KHJ {
  namespace thesis {
    namespace heap_node {  
      template <typename E>        
      class heap_awh_node {    

      public:
        // maybe private ?
        typedef E value_type;
        typedef heap_awh_node<E> N;
        
        explicit heap_awh_node( const E& ); 
        explicit heap_awh_node( const E&, bool ); 
        ~heap_awh_node( ); 

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
        int   height_;
        N*      left_;
        N*     right_;
        
        // Should be friends will all modifier types...
        template<typename N, typename C> 
        friend class KHJ::thesis::modifier::node_awh_modifier;
      };
    }
  }
}
#include "heap_awh_node.i++"
#endif
