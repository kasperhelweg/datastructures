#ifndef THESIS_AWH_NODE_MODIFIER
#define THESIS_AWH_NODE_MODIFIER
#include "heap_utils.h++"
namespace KHJ  {
  namespace thesis  {
    namespace modifier  {
      template <typename V, typename N, typename C>
      class node_awh_modifier {     
        // Debug utils
        template<typename node_type, typename M> 
        friend class KHJ::thesis::utils::pfb;
      
      public:
        typedef N node_type;
        typedef C comparator_type;
        constexpr static comparator_type compare_ = C( );
        
        /**
         * join( )
         * 
         * complexity is O(1).
         * @author KHJ
         *
         */
        static void join( N* S, N* L, N* R )
        {
          (*L).right_ = R; 
          (*R).right_ = S; (*R).color_ = 1;
          (*S).left_  = L;
          
          (*S).height_ = (*L).height_ + 1;
        }
        
        /**
         * join_heaps( )
         * 
         * unlike join, this method assert that all join nodes are roots.
         * complexity is O(1).
         * @author KHJ
         *
         */
        static void join_heaps( N* S, N* L, N* R )
        {
          join( S, L, R );
        }
      
        /**
         * replace( )
         * 
         * complexity is O(1).
         * @author KHJ
         *
         */
        static N* replace( N* S, N* O )
        {
          (*O).left_   = (*S).left_;
          (*O).right_  = (*S).right_;
          (*O).color_  = (*S).color_;
          (*O).height_ = (*S).height_;
          
          if( (*O).is_root( ) && (*O).is_leaf( ) ) { /* no-op */ }
          else if( !(*O).is_root( ) && !(*O).is_leaf( ) ) {
            if( (*O).color_ == 0) {
              (*(*(*O).left_).right_).right_ = O;
              (*(*(*O).right_).right_).left_ = O;
            } else {
              (*(*(*O).left_).right_).right_ = O;
              (*(*(*O).right_).left_).right_ = O;
            }
          } else {
            if( (*O).is_root( ) ) {
              (*(*(*O).left_).right_).right_ = O;
            } else {
              if( (*O).color_ == 0 ) {
                (*(*(*O).right_).right_).left_ = O;
              } else {
                (*(*(*O).right_).left_).right_ = O;
              }
            }
          }
          (*S).left_   = nullptr;
          (*S).right_  = nullptr;
          (*S).height_ = 0;
                    
          return S;
        }

        static void replace_element( N* S, V v )
        {
          (*S).element_ = v;
        }
        
        static N** split( N* S )
        {
          N** st = new N*[2];
          st[0]  = (*S).left_ ;
          st[1]  = (*(*S).left_).right_; (*st[1]).color_ = 0;
          
          (*st[1]).right_ = nullptr; 
          (*st[0]).right_ = nullptr; 
          (*S).left_      = nullptr; 
          
          (*S).height_ = 0;
          
          return st;
        }

        static void siftup( N* S )
        {
          N* O = (*S).parent( );
          while( !(*S).is_root( ) && ( compare_( (*S).element(), (*O).element() ) ) ) {
            exchange_( S, O ); 
            swap_heights_( S, O );
            O = (*S).parent( );
          }
        }
      
        static void siftdown( N* S )
        {
          N* L; N* R; N* O;  
                  
          while( !(*S).is_leaf( ) ) {
            L = (*S).left_;
            R = (*(*S).left_).right_;
            if( compare_( (*L).element(), (*R).element() ) ) {
              O = L; 
            } else { 
              O = R; 
            }
            if( compare_( (*O).element(),  (*S).element() ) ) {
              exchange_( O, S ); 
              swap_heights_( S, O );
            } else { 
              break; 
            }
          }
        }

        static int incremental_siftdown( N* S )
        {
          N* L; N* R; N* O;  
          char d = -1;

          if( !(*S).is_leaf( )  ) {
            L = (*S).left_;
            R = (*(*S).left_).right_;
            if( compare_( (*L).element(), (*R).element() ) ) {
              O = L;
            } else { 
              O = R; 
            }
            if( compare_( (*O).element(),  (*S).element() ) ) {
              exchange_( O, S ); 
              swap_heights_( S, O );
              d = (O == R);
            } 
          }
          return d;
        }

      private:
        static void swap_colors_( N* S, N* O )
        {
          bool oc = (*O).color_;
          (*O).color_ = (*S).color_; (*S).color_ = oc;
        }
        
        static void swap_heights_( N* S, N* O )
        {
          int h = (*O).height_;
          (*O).height_ = (*S).height_;
          (*S).height_ = h;             
        }

        static void exchange_( N* S, N* O )
        {
          if( (*O).is_root( ) && (*S).color_ == 0 ) {
            //             
            //     O           S
            //    / \   <=>   / \
            //   S - Q       O - Q
            //  /   /       /   /
        
            N* Q = (*S).right_;
          
            // Cut out
            (*S).right_ = (*O).right_;
            (*O).left_  = (*S).left_;
            (*Q).right_ = S;
          
            (*S).left_  = O;
            (*O).right_ = Q;
          
            if( !(*O).is_leaf( )) { (*(*(*O).left_).right_).right_ = O; }
          } 
          else if( (*O).is_root( ) && (*S).color_ == 1 ) { 
            //               
            //     O           S
            //    / \   <=>   / \
            //   Q - S       Q - O
            //  /   /       /   /
                     
            N* Q = (*O).left_;
   
            (*S).right_ = (*O).right_;
            (*O).left_  = (*S).left_;
            (*Q).right_ = O;
                    
            (*S).left_  = Q;
            (*O).right_ = S;
          
            if( !(*O).is_leaf( )) { (*(*(*O).left_).right_).right_ = O; }
            
            swap_colors_( S, O );
          }
          else if( (*O).color_ == 0 && (*S).color_ == 0 ) { 
            
            //      /           /
            //     O-          S-
            //    / \   <=>   / \
            //   S - Q       O - Q
            //  /   /       /   /

            N* Q = (*S).right_;

            (*S).right_ = (*O).right_;
            (*O).left_  = (*S).left_;
            (*S).left_  = O;
            (*O).right_ = Q;
            (*Q).right_ = S;
          
            if( !(*S).is_root( )) { (*(*(*S).right_).right_).left_ = S; }
            if( !(*O).is_leaf( )) { (*(*(*O).left_).right_).right_ = O; }
          }
          else if( (*O).color_ == 0 && (*S).color_ == 1 ) { 
                  
            //      /           /
            //     O-          S-
            //    / \   <=>   / \
            //   Q - S       Q - O
            //  /   /       /   /

            N* Q = (*O).left_;

            (*S).right_ = (*O).right_;
            (*O).left_  = (*S).left_;
            (*S).left_  = Q;
            (*O).right_ = S;
            (*Q).right_ = O;
          
            if( !(*S).is_root( )) { (*(*(*S).right_).right_).left_ = S; }
            if( !(*O).is_leaf( )) { (*(*(*O).left_).right_).right_ = O; }
            swap_colors_( S, O );
          }
          else if( (*O).color_ == 1 && (*S).color_ == 0 ) {
          
            //    \           \
            //    -O          -S
            //    / \   <=>   / \
            //   S - Q       O - Q
            //  /   /       /   /

            N* Q = (*S).right_;

            (*S).right_ = (*O).right_;
            (*O).left_  = (*S).left_;
            (*S).left_  = O;
            (*O).right_ = Q;
            (*Q).right_ = S;
          
            if( !(*S).is_root( )) { (*(*(*S).right_).left_).right_ = S; }
            if( !(*O).is_leaf( )) { (*(*(*O).left_).right_).right_ = O; }

            swap_colors_( S, O );
          }
          else if( (*O).color_ == 1 && (*S).color_ == 1 ) { 
                    
            //    \           \
            //    -O          -S
            //    / \   <=>   / \
            //   Q - S       Q - O
            //  /   /       /   /

            N* Q = (*O).left_;
          
            (*S).right_ = (*O).right_;
            (*O).left_  = (*S).left_;
            (*S).left_  = Q;
            (*O).right_ = S;
            (*Q).right_ = O;
          
            if( !(*S).is_root( )) { (*(*(*S).right_).left_).right_ = S; }
            if( !(*O).is_leaf( )) { (*(*(*O).left_).right_).right_ = O; }
          } else {
            // Handle pathology
          }
        }
      };
    }
  }
}
#endif
