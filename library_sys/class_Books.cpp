#include<iostream>
#include<string>
#include<string_view>
#include<limits>
#include<iomanip>
#include"Lib.hpp"

Books::Books(){
  start = nullptr;
}

 int Books::add_Books(){

   int book_counter=1;
   char str;
   std::string book_name;

      list_books();

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

        list_books();

        std::cout<<"\nAdd book(any letter) / Quit(q): ";
        std::cin>>str;
        if(str == 'q'){
          std::cout<<std::endl;
          return book_counter; 
        }

        int i=1;

       while(str!='q'){

         list_books();

//loop2:

          //curr = new book;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        std::cout<<"\nEnter The Name of the book "<<i+1<<": ";
        std::getline(std::cin,book_name);

        for(book* i = start;i!=nullptr;i=i->next){
          if(to_lower_string(i->Name) == to_lower_string(book_name)){
            std::cout<<"\nBook Copy added.\n\n\n";
            (i->no_of_copies)++;
            //goto loop2;
            return 0;
          }
        }

        curr = new book;

        curr->Name = book_name;


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

        list_books();

        std::cout<<"\nAdd book(any letter) / Quit(q): ";
        std::cin>>str;

        i++;
        book_counter++;

        if(str == 'q'){
          std::cout<<std::endl;
          return book_counter;
        }

        }

      } else {

        list_books();

          book *t,*curr;

         for(book* temp=start;temp!=nullptr;temp=temp->next){
           t=temp;
         }

          int i=0;
          do{

//loop3:

            char str;

             curr = new book;

             std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        std::cout<<"\nEnter The Name of the book "<<i+1<<": ";
        std::getline(std::cin,book_name);

        for(book* i = start;i!=nullptr;i=i->next){
          if(to_lower_string(i->Name) == to_lower_string(book_name)){
            std::cout<<"\nBook Copy added.\n\n\n";
            (i->no_of_copies)++;
            //goto loop3;
            return 0;
          }
        }

        curr->Name=book_name;

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
        curr->prev = t;
        t=curr;
        t->next = nullptr;

        list_books();

        std::cout<<"\nAdd book(any letter) / Quit(q): ";
        std::cin>>str; 

        i++;
        book_counter++;

        if(str == 'q'){
          std::cout<<std::endl;
          return book_counter;
        }
        
           }while(str!='q');
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



int Books::delete_book() {
    int deleted_books = 0;
    std::string book_name{};
    std::string contin;
    char str;

    do {
        std::cin.ignore();
        list_books();
        std::cout << "\nEnter The Name of the Book: ";
        std::getline(std::cin, book_name);  

        bool book_flag = false;

        for (book* temp = start; temp != nullptr; temp = temp->next) {
            if (to_lower_string(book_name) == to_lower_string(temp->Name)) {
                // Deleting the book node
                if (temp->next == nullptr && temp->prev == nullptr) {
                    start = nullptr;
                } else if (temp->prev == nullptr) {
                    start = temp->next;
                    start->prev = nullptr;
                } else if (temp->next == nullptr) {
                    temp->prev->next = nullptr;
                } else {
                    temp->next->prev = temp->prev;
                    temp->prev->next = temp->next;
                }

                std::cout << "\nPress Enter key to continue";
                std::getline(std::cin, contin); 

                std::cout << "\n" << temp->Name << " has been deleted!\n";
                delete temp;
                book_flag = true;
                deleted_books++;
                break;
            }
        }

        if (!book_flag) {
            std::cout << "\nBook not found!\n\n";
        }

        std::cout << "\nDelete another Book (any letter)/Quit (q): ";
        std::cin>>str;

        if (str == 'q') {
            std::cout << std::endl;
            return deleted_books;
        }
    } while (str != 'q');

    std::cout << std::endl;
    return deleted_books;
}

void Books::searchBook(std::string str) const {

  book* temp=start;
  bool flag = true;
  for(;temp!=nullptr;temp=temp->next){
    if(to_lower_string(str) == to_lower_string(temp->Name)){
      flag=true;
      std::cout<<"\nBook Name: "<<temp->Name<<"\nAuthor: "<<temp->Author<<"\nNo. of pages: "<<temp->no_of_pages<<"\nNo. of copies: "<<temp->no_of_copies<<"\nISBn: "<<temp->ISBN;
      break;
    } else 
      flag = false;
  }
  if(!flag)
    std::cout<<"Book Not Found!";

  //for Pause
  std::string sv;
  std::cout<<"\n\nPress Enter to continue!";
  getline(std::cin,str);


}
