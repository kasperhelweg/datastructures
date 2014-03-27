/**
 * Forward lists are sequence containers that allow constant time insert and erase operations anywhere within the sequence.
 *
 * Forward lists are implemented as singly-linked lists; 
 * Singly linked lists can store each of the elements they contain in different and unrelated storage locations. 
 * The ordering is kept by the association to each element of a link to the next element in the sequence.
 *
 * @author KHJ
 *
 */
#ifndef THESIS_FORWARD_LIST
#define THESIS_FORWARD_LIST
namespace KHJ {
  namespace thesis {
    template <typename T, typename A = std::allocator<T>>
      class forward_list
      {          
        // Private Data Members
        //
        struct node_ 
        {
          explicit node_( const T &val ) : val_( val ), next_( nullptr ) 
          { };
          
          T       val_;
          node_ *next_;
        };
        
        template <typename RefT, typename PtrT>
        struct iterator_ : std::iterator<std::forward_iterator_tag, T>
        {
          iterator_( ) : ptr( nullptr ) 
          { };
          
          explicit iterator_( node_ *p ) : ptr( p ) 
          { };

          typedef PtrT pointer;
          typedef RefT reference;
          
          T&           operator*( ) const;
          iterator_&  operator++( );
          iterator_   operator++( int );
          bool        operator==( const iterator_ & ) const;
          bool        operator!=( const iterator_ & ) const;
          
          operator iterator_<const T &, const T *>() const { return iterator_<const T &, const T *>(); }

        private:
          node_ *ptr;
        };
   
      public:
        // Structors    
        //
         forward_list( );
        ~forward_list( );
        
        forward_list( const forward_list & );
        forward_list& operator=( const forward_list<T,A> & );

        // Typedefs
        //
        typedef T              value_type;
        typedef A          allocator_type;
        typedef T&              reference;
        typedef const T&  const_reference;
        
        // Allocator
        //
        typedef typename allocator_type::template rebind<node_>::other node_allocator;
      
        // Iterators
        //
        typedef iterator_<T&, T*>                   iterator;
        typedef iterator_<const T&, const T*> const_iterator;
        
        iterator        begin( );
        iterator          end( );
        const_iterator  begin( ) const;
        const_iterator    end( ) const;
        
        // Function Members
        //
        bool           empty( ) const;
        reference      front( ) const;
        void      push_front( const_reference );
        void       pop_front( );
        void          remove( T );
                
      private:
        // Variable Members
        //
        node_allocator alloc_;
        node_             *h_;

        // Function Members
        //
        node_ *buy_node_( const T & ); 
        void  sell_node_( node_ * ); 
        void       clear( );
      };
  }
}
#include "forward_list.i++"
#endif
