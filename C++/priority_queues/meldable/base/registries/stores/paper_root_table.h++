#ifndef THESIS_PAPER_ROOT_TABLE
#define THESIS_PAPER_ROOT_TABLE
#include <list>
#include <forward_list>
#include <vector>
#include <math.h>

namespace KHJ {
  namespace thesis {
    namespace root_table {
            
      template <typename N>        
      class paper_root_table {        

        // Template of two types: Container and Adapter
        struct root_table_node {
          typedef std::vector<N*> 
          root_list_type;
          typedef typename root_list_type::iterator       
          iterator_type;
          typedef typename root_list_type::const_iterator 
          const_iterator_type;
          
          root_table_node( ) : size_( 0 ), root_list_( root_list_type( ) ) {}
          
          int size_;
          root_list_type root_list_;       
          
          int size( ) const 
          { return size_; }
          bool empty( ) const 
          { return size_ == 0; }
          
          iterator_type begin( ) 
          { return root_list_.begin( ); }     
          iterator_type   end( ) 
          { return root_list_.end( ); }     
        };

      public:        
        typedef std::list<root_table_node> root_table_type;

        typedef typename root_table_type::iterator 
        iterator_type;
        typedef typename root_table_type::const_iterator 
        const_iterator_type;
        
        typedef typename root_table_node::iterator_type 
        node_iterator_type;
        typedef typename root_table_node::const_iterator_type 
        const_node_iterator_type;
        
        paper_root_table( );
        ~paper_root_table( );

        int  
        size( )  const; 
        bool 
        empty( ) const; 

        void 
        inject( N* S );  // inject
        N* 
        eject( );       // eject
        void 
        insert_root( iterator_type, N* ); // insert_root     
        N* 
        remove_root( iterator_type );     // remove_root
        N* 
        remove_root( iterator_type, node_iterator_type );
          
        /* should return custom iterator if need be */
        inline iterator_type begin( ) 
        { return root_table_.begin( ); }
        inline iterator_type end( ) 
        { return root_table_.end( );   }
        
        inline const_iterator_type begin( ) const 
        { return root_table_.begin( ); }
        inline const_iterator_type   end( ) const 
        { return root_table_.end( );   }

        inline const_iterator_type last( )  const 
        { return std::prev( root_table_.end( ) );   }
        
        void   grow( );  
        void shrink( );  
        
        void print( ) const;  
        
      private:   
        root_table_type root_table_;
      };
    }
  }
}
#include "paper_root_table.i++"
#endif
