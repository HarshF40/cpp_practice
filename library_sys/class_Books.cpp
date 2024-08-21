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

      Btemp.list_books();

      if(start == nullptr){

        start = new book;

        book *curr,*last;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        std::cout<<"\nEnter The Name of the book 1: ";
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

        std::cout<<"\nAdd book(enter) / Quit(q): ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::getline(std::cin,str);
        if(str == "q"){
          std::cout<<std::endl;
          return book_counter; 
        }

        int i=1;

       while(str!="q"){

         Btemp.list_books();


          curr = new book;

          std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        std::cout<<"\nEnter The Name of the book "<<i+1<<": ";
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

        if(str == "q"){
          std::cout<<std::endl;
          return book_counter;
        }

        }

      } else {

        Btemp.list_books();

          book *t,*curr;

         for(book* temp=start;temp!=nullptr;temp=temp->next){
           t=temp;
         }

          int i=0;
          do{

            std::string str;

             curr = new book;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        std::cout<<"\nEnter The Name of the book "<<i+1<<": ";
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

        if(str == "q"){
          std::cout<<std::endl;
          return book_counter;
        }
        
           }while(str!="q");
        }
      //just beacuse of error : )
      std::cout<<std::endl;
      return book_counter;
      }
   
void Books::list_books() const {
  system("clear");
  book* curr;
  if(start == nullptr){
    std::cout<<"\nNo books in Library!\n ";
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
  std::string book_name{};
  std::string str,contin;

  do{
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    int num_book{1},count{1};
    for(book* i=start;i!=nullptr;i=i->next){
      num_book++;
    }

    Btemp.list_books();
    std::cout<<"\nEnter The Name of the Book: ";
    std::getline(std::cin,book_name);

    book* temp=start;

  for(;temp!=nullptr;temp=temp->next){

    if(to_lower_string(book_name)==to_lower_string(temp->Name)){

    if(temp->next == nullptr && temp->prev== nullptr){
      std::cout<<"\n"<<temp->Name<<" has been deleted!\n";
        start = nullptr;
        delete temp;
        std::cout<<"\nPress Enter key to continue";
        std::getline(std::cin,contin);
        if(contin!="¶hshsha")
        break;
      } else if(temp->prev==nullptr){
        (temp->next)->prev = nullptr;
        start = temp->next;
        std::cout<<"\n"<<temp->Name<<" has been deleted!\n";
        delete temp;
        std::cout<<"\nPress Enter key to continue";
        std::getline(std::cin,contin);
        if(contin!="¶hsjsh")
        break;
      } else if(temp->next==nullptr) {
        (temp->prev)->next=nullptr;
        std::cout<<"\n"<<temp->Name<<" has been deleted!\n";
        delete temp;
        std::cout<<"\nPress Enter key to continue";
        std::getline(std::cin,contin);
        if(contin!="jwjsj¶")
        break;
      } else {
        (temp->next)->prev = temp->prev;
        (temp->prev)->next = temp->next;
        std::cout<<"\n"<<temp->Name<<" has been deleted!\n";
        delete temp;
        std::cout<<"\nPress Enter key to continue";
        std::getline(std::cin,contin);
        if(contin!="hsjs¶")
        break;
     }
    }
    count++;
  }
  Btemp.list_books();

  if(count == num_book)
    std::cout<<"\nBook not found!\n\n";

  std::cout<<"\nDelete Book(enter)/Quit(q) : ";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  std::getline(std::cin,str);
  deleted_books++;

  if(str == "q"){
    std::cout<<std::endl;
    return deleted_books;
  }
 }while(str!="q");
  std::cout<<std::endl;
  return deleted_books;
}

