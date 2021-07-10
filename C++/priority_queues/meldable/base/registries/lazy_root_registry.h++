/* 
  A root registry keeps track of the roots of the perfect binary heaps
  in a binary queue. The implicit numeral system used depends on store type and consolidation policy type.
  
  Author : KHJ 2014
*/

#ifndef THESIS_LAZY_ROOT_REGISTRY
#define THESIS_LAZY_ROOT_REGISTRY
#include <memory>
#include <utility>
#include "heap_utils.h++"
#include "lazy_binary_queue.h++"
namespace KHJ  {
  namespace thesis  {
    namespace root_registry  {
      template<typename N, typename M, typename S>
      class lazy_root_registry {
        template<typename E, typename C, typename U, typename B, typename R>
        friend class KHJ::thesis::queue::lazy_binary_queue;
      public:
        typedef N node_type;
        typedef M modifier_type;
        typedef S root_list_type;
                
        typedef typename root_list_type::iterator_type 
        iterator_type;
        typedef iterator_type I;
        
        explicit lazy_root_registry( );
        ~lazy_root_registry( ); 
        
        N*     
        top()   const;
        bool 
        empty() const;
        int   
        size()  const;
        void 
        print() const;
        
        void 
        inject(N*);
        N*   
        eject();        
        void 
        update_top(); 
        void
        update_top( N* Q );
        void 
        consolidate();
     
        inline iterator_type 
        begin( ) { return root_list_.begin( ); }
        inline iterator_type 
        end( )   { return root_list_.end( ); }
        
        // Debug utils
        KHJ::thesis::utils::pfb<N, M> utils;
      private:
        int 
        size_;
        N*  
        top_;
        bool 
        cons_;

        root_list_type 
        root_list_;
              
        void 
        swap_nodes_(N* [], int, int);
      };
    }
  }
}
#include "lazy_root_registry.i++"
#endif
