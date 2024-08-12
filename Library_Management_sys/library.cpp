//code in progress!!!!
#include<iostream>
#include<string>
#include<string_view>
#include<limits>
#include<cctype>
#include"lib_decl.hpp"

int main(){
  Book B{};

  int num;
  std::cout<<"\nEnter Number of Books to add in Library: ";
  std::cin>>num;


  Library L{};
  L.add_books(num);
  //B.display_details();
  L.listAll_Books_inLib();

//  std::cout<<"\nCalling add books(3)\n";
//  L.add_books(3);
 // L.listAll_Books_inLib();

  std::cout<<"\nAdd user\n\n";

  std::cout<<"\nEnter No. of users: ";
  int unum;
  std::cin>>unum;
  L.add_users(unum);
  L.listAll_Users_inLib();
  return 0;
}
