#ifndef THESIS_MAGICAL_BINARY_QUEUE
#define THESIS_MAGICAL_BINARY_QUEUE
namespace KHJ  {
  namespace thesis  {
    namespace queue  {
      template<typename E, typename C, typename N, typename M, typename R>
      class magical_binary_queue {
      public:
        typedef E element_type;
        typedef C comparator_type;
        typedef N node_type;
        typedef M modifier_type;
        typedef R registry_type;
        
        typedef typename registry_type::iterator_type 
        iterator_type;
                
        explicit magical_binary_queue( ) : registry_( R( )) { } 

        int 
        size() const;
        bool
        empty() const;
        
        N*   
        find_min();       
        void   
        insert(N*); 
        N*  
        erase_min();
        void
        decrease_key(N*, E);
        void    
        erase(N*);  
        
        void  
        meld(magical_binary_queue&);       
        void 
        clear();
        
      private:
        registry_type 
        registry_;
      };
    }
  }
}
#include "magical_binary_queue.i++"
#endif
