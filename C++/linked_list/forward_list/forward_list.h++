#ifndef THESIS_FORWARD_LIST
#define THESIS_FORWARD_LIST
namespace thesis {
  template <class T, class A = std::allocator<T>>
    class forward_list
    {          
      // Private Data Members
      //
      struct list_node_ {
        list_node_( T data, list_node_ *next ) : data_( data ), next_( next ) 
        { };
        
        T           data_;
        list_node_ *next_;
      };
      
    public:
      // Structors    
      //
      forward_list( );
      
      // Typedefs
      //
      typedef T& reference;
      typedef const T& const_reference;
      
      // Allocator
      //
      typedef A Allocator;
      typedef typename Allocator::template rebind<list_node_>::other node_allocator;
      
      // Function Members
      //
      reference front( ) const;
      void push_front( const_reference );
      void pop_front ( );
      
    private:
      // Variables
      //
      node_allocator alloc_;
      list_node_     *h_, *t_;
    };
}
#include "forward_list.i++"
#endif
