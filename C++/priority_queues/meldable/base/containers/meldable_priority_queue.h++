#ifndef THESIS_MELDABLE_PRIORITY_QUEUE
#define THESIS_MELDABLE_PRIORITY_QUEUE
namespace KHJ  {
  namespace thesis  {
    namespace priority_queue  {
      template<typename V, typename C, typename A, typename E, typename R>
      class meldable_priority_queue {
      public:
        typedef V value_type;
        typedef C comparator_type;
        typedef A allocator_type;
        typedef E encapsulator_type;
        typedef R realizer_type;
        typedef meldable_priority_queue<V, C, A, E, R> container_type;
        
        explicit meldable_priority_queue( ) : 
          realizer_( realizer_type( )), allocator_( allocator_type( ) ) 
        { } 
        
        // accessors     
        value_type 
        top() const;       
        bool     
        empty() const;
        int       
        size() const;
        
        // modifiers     
        E*          
        push(E*);            
        E*       
        push(V const&);
        E*       
        extract();
        V            
        pop();               
        void       
        erase(E*);            
        void    
        increase(E*, V);            
        void    
        decrease(E*, V);            
        void        
        meld(meldable_priority_queue&);  
        E*       
        borrow();
        void       
        clear();
        
        /* KPH debug */
        void       
        print();
        /* end */
        
      private:
        realizer_type   
        realizer_;
        allocator_type 
        allocator_;
        
        E*    
        buy_(const V& val);
        void 
        sell_(E* );
      };
    }
  }
}
#include "meldable_priority_queue.i++"
#endif
