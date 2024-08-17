#ifndef LIB_HPP
#define LIB_HPP

class Books{

  private:

    struct book{                    
      std::string Name;
      std::string Author;
      int no_of_pages;
      int no_of_copies;       
      long int ISBN;
      book *prev,*next;
    }*start = new book;//add *last if needed
             //
         //  start = new book;
          //  start = NULL;
        //  start->next = NULL;
  public:

    Books();

    void add_Books(int num_of_book);

    void list_books(int books_in_Lib) const ;

   // void Books_del();
};


class Library{

  private:

    int no_of_books_in_Lib;
    Books B;
    //start = new book;

  public:

    Library();
    
    void StartLib();

};


#endif
