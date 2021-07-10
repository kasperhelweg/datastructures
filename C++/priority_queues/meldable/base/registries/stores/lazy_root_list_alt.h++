#ifndef THESIS_LAZY_ROOT_LIST_ALT
#define THESIS_LAZY_ROOT_LIST_ALT
#include <list>
#include <forward_list>
#include <vector>
#include <math.h>

namespace KHJ {
  namespace thesis {
    namespace root_list {
      template <typename N>        
      class lazy_root_list_alt {        
        
      public:     
        typedef std::list<N*> root_list_type;
               
        typedef typename root_list_type::iterator 
        iterator_type;
        typedef typename root_list_type::const_iterator 
        const_iterator_type;
          
         lazy_root_list_alt( );
        ~lazy_root_list_alt( );

        N*  top;
        int size_;

        int      
        size( )  const; 
        bool    
        empty( ) const; 
        bool 
        one_heap( ) const; 
    
        void 
        inject( N* S );
        N*    
        eject( );    

        void
        clear( );    
        
        void 
        insert_root( iterator_type, N* );
        N* 
        remove_root( iterator_type );
        void
        concatenate( lazy_root_list_alt& );

          
        /* maybe only support const iterators since "head_" is not supposed to be modified? */
        inline iterator_type 
        begin( ) { return root_list_.begin( ); }
        inline iterator_type 
        end( ) { return root_list_.end( ); }
        
        inline const_iterator_type 
        begin( ) const { return root_list_.begin( ); }
        inline const_iterator_type   
        end( ) const { return root_list_.end( );   }
        
        void 
        print( ) const;  
        root_list_type root_list_;
      private:  
       
      };
    }
  }
}
#include "lazy_root_list_alt.i++"
#endif
