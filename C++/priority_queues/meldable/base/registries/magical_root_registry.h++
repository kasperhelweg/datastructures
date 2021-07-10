/* 
  A root registry keeps track of the roots of the perfect binary heaps
  in a binary queue. The implicit numeral system used depends on store type and consolidation policy type.
  
  Author : KHJ 2014
*/

#ifndef THESIS_MAGICAL_ROOT_REGISTRY
#define THESIS_MAGICAL_ROOT_REGISTRY
#include <memory>
#include "heap_utils.h++"

namespace KHJ  {
  namespace thesis  {
    namespace root_registry  {
      template<typename N, typename M, typename S>
      class magical_root_registry {
      public:
        typedef N node_type;
        typedef M modifier_type;
        typedef S root_table_type;
                
        typedef typename root_table_type::iterator_type 
        iterator_type;
        typedef iterator_type I;
        
        explicit magical_root_registry( );
        ~magical_root_registry( ); 
        
        N*     
        top()   const;
        bool 
        empty() const;
        int   
        size()  const;
        void 
        print() const;
        
        N*    
        eject();        
        void 
        inject(N*);
        void 
        update_top();        
        void 
        update_top(N*);        
        
        inline iterator_type 
        begin( ) { return root_table_.begin( ); }
        inline iterator_type 
        end( )   { return root_table_.end( ); }
        
        // Debug utils
        KHJ::thesis::utils::pfb<N, M> utils;
      private:
        int 
        size_;
        N* 
        top_;
        
        root_table_type 
        root_table_;
        std::vector<iterator_type> 
        hi_;
        std::vector<iterator_type> 
        lo_;

        std::vector<iterator_type> 
        state_;
        
        void 
        fix_( iterator_type );
        void 
        unfix_( iterator_type );

        bool 
        in_idle_state_( ) const;
        void 
        update_lo_( iterator_type );
    
        void 
        swap_nodes_( N* [], int, int );
      };
    }
  }
}
#include "magical_root_registry.i++"
#endif
