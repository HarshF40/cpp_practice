#include<iostream>
#include<string>
#include<string_view>
#include<limits>
#include<cctype>
#include<optional>
#include "lib_decl.hpp"

USER::USER(std::string_view name,std::string_view id,int num_bb=0) : Name{name} , ID{id}, no_of_books_borrowed{num_bb} {
    bb = new Book_Borrowed[no_of_books_borrowed];
  }

  void USER::getUserdata(){
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout<<"\nEnter Name of the User: ";
      getline(std::cin,Name);
      //will be improved afterwards.
      std::cout<<"\nEnter Unique ID: ";
      getline(std::cin,ID);
  }

  std::string_view USER::display_USER_id(){
    return ID;
  }

  std::string_view USER::display_USER_name(){
    return Name;
  }

  int USER::getNo_of_Books_Borrowed(){
    return no_of_books_borrowed; 
  }

  void USER::books_borrowed_plus(){
    no_of_books_borrowed++;
  }

Book::Book() = default;

Book::Book(std::string_view title,std::string_view author,std::string_view isbn,int pages,int copies) : Title{title},Author{author},Isbn{isbn},no_of_pages{pages},no_of_copies{copies} {}

    void Book::get_Book_details(){
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout<<"\nEnter the title of the book: ";
      getline(std::cin,Title);
      std::cout<<"\nEnter the name of the Author: ";
      getline(std::cin,Author);
      std::cout<<"\nEnter the ISBN no.: ";
      getline(std::cin,Isbn);
      std::cout<<"\nEnter the no. of pages: ";
      std::cin>>no_of_pages;
      std::cout<<"\nEnter the no of copies: ";
      std::cin>>no_of_copies;
      std::cout<<'\n';
    }

    void Book::display_details() const {
      std::cout<<"\nTitle: "<<Title<<"\nAuthor: "<<Author<<"\nISBN: "<<Isbn<<"\nNo. of pages: "<<no_of_pages<<"\nNo. of copies: "<<no_of_copies;
    }

    std::string_view Book::getTitle() const {
      return Title;
    }

    int Book::getNo_ofCopies() const {
      return no_of_copies;
    }

Library::Library(int num_of_books=0,Book* b=nullptr,int num_of_users=0,USER* u=nullptr) : no_of_books{num_of_books},books{b}{
        books = new Book[no_of_books];
        users = new USER[no_of_users];
    }

    void Library::add_books(int new_books=0){
      int range = no_of_books+new_books;
      for(int i=no_of_books;i<range;i++){
        books[i].get_Book_details();
        no_of_books++;
      }
    } 


   void Library::listAll_Books_inLib() const {
     std::cout<<"\nAvailable Books\nTitle: \n";
     for(int i=0;i<no_of_books;){
       //borrowed copies will be chceked
       if(books[i].getNo_ofCopies()> 0){
       std::cout<<i<<". "<<books[i].getTitle()<<'\n';
       i++;
       }
     }
   } 

   void Library::add_users(int new_users=0){
     int range = no_of_users+new_users;
     for(int i=no_of_users;i<range;i++){
       users[i].getUserdata();
       no_of_users++;
     }
   }

   void Library::listAll_Users_inLib() const {
     std::cout<<"\nUsers: \n";
     for(int i=0;i<no_of_users;i++){
       std::cout<<users[i].display_USER_id()<<' '<<users[i].display_USER_name()<<'\n'; 
     }
   }
   
   std::optional<int> Library::check_book_availibility(std::string book_name){
     int i=0;
     for(;i<no_of_books;i++){
       if((std::tolower(book_name) == std::tolower(books[i].getTitle())) && books[i].getNo_ofCopies()>0 ){
         return i;
       }
     }
     return std::nullopt;
   }

   void Library::borrow_book(std::string_view username,std::string_view book_name){
     std::optional<int> flag = check_book_availibility(book_name);
     if(std::isnum(flag)){
       //finding user
       std::string_view ToloweredTitle;
       for(int i=0;i<no_of_users;i++){
         ToloweredTitle = users[i].display_USER_name();
         if(std::tolower(username) == std::tolower(ToloweredTitle)){
           users[i].bb[users[i].getNo_of_Books_Borrowed()].Book_Name = book_name;
           users[i].books_borrowed_plus();
           books[flag].no_of_copies--;
           std::cout<<"\nEnter Todays Date: ";
           getline(std::cin,users[i].bb[getNo_of_Books_Borrowed()].Date);
           std::cout<<"\nEnter Return Date: ";
           getline(std::cin,users[i].bb[users[i].getNo_of_Books_Borrowed()].return_date);
           break;
         } else {
           std::cout<<"\nUser Not Found!";
         }
       }
     } else {
       std::cout<<"\nBook Not Found!";
     }
   }

