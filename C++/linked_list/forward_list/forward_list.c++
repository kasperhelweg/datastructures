#include <iostream>
#include <string>
#include "forward_list.h++"

int main( )
{
  thesis::forward_list<std::string> f_list;
  
  f_list.push_front( "Kasper" );
  f_list.push_front( "Some_name" );
  f_list.front( ) =  "Zarima";
  
  std::cout << "Front: " << f_list.front( ) << std::endl;
  f_list.pop_front( );
  std::cout << "Front: " << f_list.front( ) << std::endl;
  f_list.pop_front( );
  
  return 0;
}
