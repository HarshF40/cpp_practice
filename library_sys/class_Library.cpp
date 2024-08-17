#include<iostream>
#include<string>
#include"Lib.hpp"

/*class Library{

  private:

    int no_of_books_in_Lib{0};
    Books B;

  public: */

Library::Library() = default;

    void Library::StartLib() {

      bool on = true;

      std::cout<<"             \\\\\\\\\\\\\\\\_YuLib_////////";
  std::cout<<"\n\n\n\n\n";

  while(on){

    char choice;

    std::cout<<"List all books(l)\nAdd books(a)\nQuit(q)";
    std::cout<<"\n\n\n~ ";
    std::cin>>choice;


    switch(choice){

      case 'l' : B.list_books();
                  break;

      case 'a' : int num_of_books_add;
                  std::cout<<"\nEnter No. of books to add: ";
                  std::cin>>num_of_books_add;
                  B.add_Books(num_of_books_add);
                  no_of_books_in_Lib+=num_of_books_add;
                 break;

      case 'q' : //B.Books_del();
                 return;

      default: std::cout<<"\nInvalid Input!\n\n";

    }


  }


    }


