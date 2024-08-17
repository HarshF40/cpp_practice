#include<iostream>
#include<string>
#include<string_view>
#include<limits>
#include<iomanip>
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
void Books::list_books() const {
  book* curr;
  if(start == nullptr){
    std::cout<<"No books in Library!";
  } else {
    int i=1;
    std::cout<<std::setw(5)<<"Sr. No."<<std::setw(10)<<"Book";
    for(curr = start;curr!=nullptr;curr=curr->next){
      std::cout<<std::setw(5)<<i+1<<std::setw(10)<<curr->Name<<'\n';
      i++;
     }
   }
 }

