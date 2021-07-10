/* 
  A root registry keeps track of the roots of the perfect binary heaps
  in a binary queue. The implicit numeral system used depends on store type and consolidation policy type.
  
  Author : KHJ 2014
*/

#ifndef THESIS_REGULAR_ROOT_REGISTRY
#define THESIS_REGULAR_ROOT_REGISTRY
#include <list>
#include "heap_utils.h++"
namespace KHJ  {
  namespace thesis  {
    namespace root_registry  {
      template<typename N, typename M, typename S>
      class regular_root_registry {
      public:
        typedef N node_type;
        typedef M modifier_type;
        typedef S root_table_type;
                
        typedef typename root_table_type::iterator_type 
        iterator_type;
        typedef iterator_type I;
        typedef typename root_table_type::root_list_node 
        root_list_node;
        typedef typename root_table_type::root_list_iterator_type 
        root_list_iterator_type;
        typedef root_list_iterator_type RLI;
        
        explicit regular_root_registry( );
        ~regular_root_registry( ); 
     
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
        update_top(N*); 
        void 
        meld( regular_root_registry& );
                
        inline iterator_type 
        begin() { return root_table_.begin( ); }
        inline iterator_type 
        end()   { return root_table_.end( ); }
        
        // Debug utils
        KHJ::thesis::utils::pfb<N, M> utils;
      private:
        int 
        size_;
        N* 
        top_;

        root_table_type 
        root_table_;
        std::list<iterator_type> 
        hi_;
        std::list<iterator_type> 
        wall_;
        
        void   
        transfer_(iterator_type, N*);
        void     
        reduce_(iterator_type);
        void     
        reduce_by_(iterator_type, int);
        void 
        reduce_to_zero_(iterator_type);
        void 
        arbitrary_inject_( N*, int );
        void 
        swap_nodes_(N* [], int, int);
      };
    }
  }
}
#include "regular_root_registry.i++"
#endif
