#include<iostream>
#include<string>
#include<iomanip>
#include"Lib.hpp"

Library::Library() = default;

    void Library::StartLib() {

      bool on = true;

      std::cout<<"\n\n";
      std::cout<<std::setw(30)<<"\\\\\\\\\\\\\\\\_YuLib_////////";
  std::cout<<"\n\n\n";

  while(on){

    char choice;

    std::cout<<"List all books(l)\nAdd books(a)\nQuit(q)";
    std::cout<<"\n\n~ ";
    std::cin>>choice;


    switch(choice){

      case 'l' : B.list_books();
                  break;

      case 'a' : int num_of_books_add;
                 system("clear");
                  std::cout<<"\nEnter No. of books to add: ";
                  std::cin>>num_of_books_add;
                  B.add_Books(num_of_books_add);
                  no_of_books_in_Lib+=num_of_books_add;
                 break;

      case 'q' : return;

      default: std::cout<<"\nInvalid Input!\n\n";

    }
  }  
}


