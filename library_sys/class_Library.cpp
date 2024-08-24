#include<iostream>
#include<string>
#include<iomanip>
#include"Lib.hpp"

#define blue "\033[36m"
#define green "\033[32m"
#define reset "\033[0m"

Library::Library() = default;

    void Library::StartLib() {

      bool on = true;

      std::cout<<"\n\n";
      std::cout<<std::setw(30)<<blue<<"\\\\\\\\\\\\\\\\_YuLib_////////";
  std::cout<<"\n\n\n"<<reset;

  while(on){

    char choice;

    std::cout<<"\nList all books(l)\nAdd books(a)\nDelete Book(d)\nSearch Book(s)\nAdd User(u)\nList Users(f)\nDelete User(e)\nQuit(q)";
    std::cout<<green<<"\n\n~ "<<reset;
    std::cin>>choice;

    switch(choice){

      case 'l' : { 
                  B.list_books();
                  break;
                 }

      case 'a' : {
                  int num_of_books_add;
                  system("clear");
                  num_of_books_add = B.add_Books();
                  no_of_books_in_Lib+=num_of_books_add;
                  break;
                 }

      case 'd' : {
                 system("clear");
                 int d_books;
                 d_books = B.delete_book();
                 no_of_books_in_Lib-=d_books;
                 break;
                 }

      case 's' : {
                   system("clear");
                   std::string book_name;
                   std::cout<<"\nEnter The Name of the Book: ";
                   std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                   getline(std::cin,book_name);
                   B.searchBook(book_name);
                   break;
                 }

      case 'u': {
                system("clear");
                U.addUsers();
                break;
                }

      case 'f' : {
                   system("clear");
                   U.listUsers();
                   break;
                 }

      case 'e' : {
                   system("clear");
                   U.deleteUser();
                   break;
                 }

      case 'q' : return;

      default: std::cout<<"\nInvalid Input!\n\n";

    }
  }  
}


