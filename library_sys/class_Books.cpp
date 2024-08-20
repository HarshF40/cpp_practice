#include<iostream>
#include<string>
#include<string_view>
#include<limits>
#include<iomanip>
#include"Lib.hpp"

Books::Books(){
  start = nullptr;
}

 int Books::add_Books(const Books& Btemp){

   int book_counter=1;
   std::string str;

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

        Btemp.list_books();

       // for(int i=1;i<num_of_books;i++){
       //
        std::cout<<"\nAdd book(enter) / Quit(q): ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::getline(std::cin,str);
        std::cout<<std::endl;
        if(str == "q")
          return book_counter; 

        int i=1;

       while(str!="q"){


          curr = new book;
          //std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

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

        Btemp.list_books();

        std::cout<<"\nAdd book(enter) / Quit(q): ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::getline(std::cin,str);

        i++;
        book_counter++;

        if(str == "q")
          return book_counter;

        }//

      } else {

          book *t,*curr;

         for(book* temp=start;temp!=nullptr;temp=temp->next){
           t=temp;
         }

          // for(int i=0;i<num_of_books;i++){
          //
          int i=0;
          do{

            std::string str;

             curr = new book;

            // std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

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

        Btemp.list_books();

        std::cout<<"\nAdd book(enter) / Quit(q): ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::getline(std::cin,str);

        i++;
        book_counter++;

        if(str == "q")
          return book_counter;
        
           }while(str!="q");
        }
      //just beacuse of error : )
      return book_counter;
      }
   
void Books::list_books() const {
  system("clear");
  book* curr;
  if(start == nullptr){
    std::cout<<"\nNo books in Library!"<<std::endl;
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

int Books::delete_book(const Books& Btemp){

  int deleted_books;
  std::string book_name;
  std::string str;

  do{

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    Btemp.list_books();

    std::cout<<"\nEnter The Name of the Book: ";
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::getline(std::cin,book_name);

  book* temp=start;

  for(;temp!=nullptr;temp=temp->next){
    if(to_lower_string(book_name)==to_lower_string(temp->Name)){

      if(temp->prev==nullptr){
        (temp->next)->prev = nullptr;
        start = temp->next;
        std::cout<<"\n"<<temp->Name<<" has been deleted!\n";
        delete temp;
      } else if(temp->next==nullptr) {
        (temp->prev)->next=nullptr;
        std::cout<<"\n"<<temp->Name<<" has been deleted!\n";
        delete temp;
      } else {
        (temp->next)->prev = temp->prev;
        (temp->prev)->next = temp->next;
        std::cout<<"\n"<<temp->Name<<" has been deleted!\n";
        delete temp;
     }
    }
  }
  std::cout<<"Delete Book(enter)/Quit(q) : ";
  std::getline(std::cin,str);
  deleted_books++;
  if(str == "q")
    return deleted_books;
 }while(str!="q");
  return deleted_books;
}

