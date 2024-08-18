#ifndef LIB_HPP
#define LIB_HPP

class Books{

  private:

    struct book{                    
      std::string Name;
      std::string Author;
      long unsigned int no_of_pages;
      long unsigned int no_of_copies;       
      long unsigned int ISBN;
      book *prev,*next;
    }*start;

  public:

    Books();

    void add_Books(int num_of_book);

    void list_books() const ;

};


class Library{

  private:

    int no_of_books_in_Lib;
    Books B;

  public:

    Library();
    
    void StartLib();

};


#endif
