#ifndef LIB_HPP
#define LIB_HPP

class USER{

  public:
 struct Book_Borrowed {
    std::string Book_Name{};
    std::string Date{};
    std::string return_date{};
  };

  private:

  std::string Name{};
  std::string ID{};
  int no_of_books_borrowed{};

  public:
 
  Book_Borrowed* bb;
  USER() = default;
  USER(std::string_view name,std::string_view id,int num_bb=0);
  void getUserdata();
  std::string_view display_USER_id();
  std::string_view display_USER_name();
  int getNo_of_Books_Borrowed();
  void books_borrowed_plus();

};

class Book{
  private:

    std::string Title;
    std::string Author;
    std::string Isbn;
    int no_of_pages;
    int no_of_copies;

  public:

    Book() = default;
    Book(std::string_view title,std::string_view author,std::string_view isbn,int pages,int copies);
    void get_Book_details();
    void display_details();
    std::string_view getTitle();
    int getNo_ofCopies();

};

class Library{

  private:
    int no_of_books{0};
    Book* books;
    int no_of_users;
    USER* users;

  public:

    Library(int num_of_books=0,Book* b=nullptr,int num_of_users=0,USER* u=nullptr);
    void add_books(int new_books=0);
   void listAll_Books_inLib();
   void add_users(int new_users=0);
   void listAll_Users_inLib();
   std::optional<int> check_book_availibility(std::string book_name);
   void borrow_book(std::string_view username,std::string_view book_name);

};


#endif
