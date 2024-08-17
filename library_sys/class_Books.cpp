#include<iostream>
#include<string>
#include<string_view>
#include<limits>
#include"Lib.hpp"

Books::Books() = default;

 void Books::add_Books(int num_of_books){

      //if the linked list is empty:
      if(start->next == nullptr){

        book *curr,*last;
     //   start = new book;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        std::cout<<"\nEnter The Name of the book: ";
        std::getline(std::cin,start->Name);

        std::cout<<"\nEnter Author's name: ";
        std::getline(std::cin,start->Author);

        std::cout<<"\nEnter No. of pages: ";
        std::cin>>start->no_of_pages;

        std::cout<<"\nEnter No. of copies: ";
        std::cin>>start->no_of_copies;

        std::cout<<"\nEnter ISBN: ";
        std::cin>>start->ISBN;

        start->prev = nullptr;
        start->next = nullptr;
        last = start;

        for(int i=1;i<num_of_books;i++){
          curr = new book;
 std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        std::cout<<"\nEnter The Name of the book: ";
        std::getline(std::cin,curr->Name);

        std::cout<<"\nEnter Author's name: ";
        std::getline(std::cin,curr->Author);

        std::cout<<"\nEnter No. of pages: ";
        std::cin>>curr->no_of_pages;

        std::cout<<"\nEnter No. of copies: ";
        std::cin>>curr->no_of_copies;

        std::cout<<"\nEnter ISBN: ";
        std::cin>>curr->ISBN;

        last->next = curr;
        curr->prev = last;
        curr->next = nullptr;
        last = curr;

        }
      } else {

          book *t,*curr;

         for(t=start;t!=nullptr;t=t->next)

           for(int i=0;i<num_of_books;i++){

             curr = new book;

             std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        std::cout<<"\nEnter The Name of the book: ";
        std::getline(std::cin,curr->Name);

        std::cout<<"\nEnter Author's name: ";
        std::getline(std::cin,curr->Author);

        std::cout<<"\nEnter No. of pages: ";
        std::cin>>curr->no_of_pages;

        std::cout<<"\nEnter No. of copies: ";
        std::cin>>curr->no_of_copies;

        std::cout<<"\nEnter ISBN: ";
        std::cin>>curr->ISBN;

        curr->next = nullptr;
        curr->prev = t;
        t->next = curr;
        t = curr;

           }
        }     
      }
   
//rewrite
void Books::list_books(int books_in_lib) const {
  //std::cout<<"hi";
  book* curr = start;
  for(int i=0;i<books_in_lib;i++){
    if(curr == nullptr)
      break;
    else {
    std::cout<<curr->Name<<'\n';
    curr = curr->next;
  }
}
}

/*void Books::Books_del(){
  book* current = start;
  while(current!=nullptr){
    book* nextnode = current->next;
    delete current;
    current = nextnode;
  }
  start = nullptr;
}*/


