#ifndef LIB_HPP
#define LIB_HPP

class Books;

class User {

  private:

    struct book_borrowed{
      std::string book_name;
      std::string borrow_date;
      std::string return_date;
      book_borrowed* next;
    };

    struct user{
      std::string name;
      long unsigned int contact_no;
      user* next;
      book_borrowed* start=nullptr;
    }*head,*last;

  public: 

    User();
    void addUsers();
    void listUsers() const ;
    void deleteUser();
    void borrow_book(Books& B);
    void ListBorrowedBooksByUser() const ;
    void ReturnBook();

};



class Books{

  public:

    struct book{                    
      std::string Name;
      std::string Author;
      long unsigned int no_of_pages;
      long unsigned int no_of_copies;       
      long unsigned int ISBN;
      book *prev,*next;
    }*start;

    Books();
    int add_Books();
    void list_books() const ;
    int delete_book();
    void searchBook(std::string str) const ;

};


class Library{

  private:

    int no_of_books_in_Lib;
    Books B;
    User U;

  public:

    Library();
    
    void StartLib();

};

const std::string to_lower_string(std::string sv);

#endif
