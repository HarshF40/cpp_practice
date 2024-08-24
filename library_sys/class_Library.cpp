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

    std::cout<<"\nList all books(l)\nAdd books(a)\nDelete Book(d)\nSearch Book(s)\nAdd User(u)\nList Users(f)\nQuit(q)";
    std::cout<<"\n\n~ ";
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

      case 'q' : return;

      default: std::cout<<"\nInvalid Input!\n\n";

    }
  }  
}


