#include<iostream>
#include<string>
#include<string_view>
#include<limits>
#include<iomanip>
#include"Lib.hpp"

Books::Books() = default;

 void Books::add_Books(int num_of_books){

   system("clear");

      if(start->next == nullptr){

        book *curr,*last;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        std::cout<<"Enter The Name of the book 1: ";
        std::getline(std::cin,start->Name);

        std::cout<<"Enter Author's name: ";
        std::getline(std::cin,start->Author);

        std::cout<<"Enter No. of pages: ";
        std::cin>>start->no_of_pages;

        std::cout<<"Enter No. of copies: ";
        std::cin>>start->no_of_copies;

        std::cout<<"Enter ISBN: ";
        std::cin>>start->ISBN;
        std::cout<<"\n";

        start->prev = nullptr;
        start->next = nullptr;
        last = start;

        for(int i=1;i<num_of_books;i++){

          curr = new book;

 std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        std::cout<<"Enter The Name of the book "<<i+1<<": ";
        std::getline(std::cin,curr->Name);

        std::cout<<"Enter Author's name: ";
        std::getline(std::cin,curr->Author);

        std::cout<<"Enter No. of pages: ";
        std::cin>>curr->no_of_pages;

        std::cout<<"Enter No. of copies: ";
        std::cin>>curr->no_of_copies;

        std::cout<<"Enter ISBN: ";
        std::cin>>curr->ISBN;
        std::cout<<"\n";

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

        std::cout<<"Enter The Name of the book "<<i+1<<": ";
        std::getline(std::cin,curr->Name);

        std::cout<<"Enter Author's name: ";
        std::getline(std::cin,curr->Author);

        std::cout<<"Enter No. of pages: ";
        std::cin>>curr->no_of_pages;

        std::cout<<"Enter No. of copies: ";
        std::cin>>curr->no_of_copies;

        std::cout<<"Enter ISBN: ";
        std::cin>>curr->ISBN;
        std::cout<<"\n";

        curr->next = nullptr;
        curr->prev = t;
        t->next = curr;
        t = curr;

           }
        }     
      }
   
void Books::list_books() const {
  system("clear");
  book* curr;
  if(start == nullptr){
    std::cout<<"No books in Library!";
  } else {
    int i=1;
    std::cout<<std::left<<"Sr. No."<<std::setw(20)<<"Book\n";
    for(curr = start;curr!=nullptr;curr=curr->next){
      std::cout<<i<<std::setw(29)<<curr->Name<<'\n';
      i++;
     }
   }
  std::cout<<std::endl;
 }

