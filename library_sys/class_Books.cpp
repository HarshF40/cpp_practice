#include<iostream>
#include<string>
#include<string_view>
#include<limits>
#include<iomanip>
#include"Lib.hpp"

Books::Books(){
  start = nullptr;
}

 void Books::add_Books(int num_of_books){

   system("clear");

      if(start == nullptr){

        start = new book;

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

         for(book* temp=start;temp!=nullptr;temp=temp->next){
           t=temp;
         }

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

        t->next = curr;
        curr->next = nullptr;
        curr->prev = t;
        t=curr;

           }
        }     
      }
   
void Books::list_books() const {
  system("clear");
  book* curr;
  if(start == nullptr){
    std::cout<<"No books in Library!"<<std::endl;
  } else {
    int i=1;
    std::cout<<std::setw(20)<<std::left<<"Sr. No."<<std::setw(5)<<std::setw(20)<<std::left<<"Book Name"<<"\n";
    std::cout<<"-----------------------------"<<'\n';
    for(curr = start;curr!=nullptr;curr=curr->next){
      std::cout<<std::setw(20)<<std::left<<i<<std::setw(5)<<std::setw(20)<<std::left<<curr->Name<<"\n";
      i++;
     }
   }
  std::cout<<std::endl;
 }

