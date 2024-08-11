#include<iostream>
#include<string>
#include<string_view>
#include<limits>

class Book{
  private:
    std::string Title;
    std::string Author;
    std::string Isbn;
    int no_of_pages;
    int no_of_copies;

  public:
    Book() = default;

    Book(std::string_view title,std::string_view author,std::string_view isbn,int pages,int copies) : Title{title},Author{author},Isbn{isbn},no_of_pages{pages},no_of_copies{copies} {}

    void get_Book_details(){
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout<<"\nEnter the title of the book: ";
      getline(std::cin,Title);
    //  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout<<"\nEnter the name of the Author: ";
      getline(std::cin,Author);
    //  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout<<"\nEnter the ISBN no.: ";
      getline(std::cin,Isbn);
    //  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout<<"\nEnter the no. of pages: ";
      std::cin>>no_of_pages;
      std::cout<<"\nEnter the no of copies: ";
      std::cin>>no_of_copies;
      std::cout<<'\n';
    }

    void display_details() const {
      std::cout<<"\nTitle: "<<Title<<"\nAuthor: "<<Author<<"\nISBN: "<<Isbn<<"\nNo. of pages: "<<no_of_pages<<"\nNo. of copies: "<<no_of_copies;
    }

    std::string_view getTitle() const {
      return Title;
    }

    int getNo_ofCopies() const {
      return no_of_copies;
    }
};

class Library{

  private:
    int no_of_books{0};
    Book* books;

  public:

    Library(int num_of_books=0,Book* b=nullptr) : no_of_books{num_of_books},books{b}{
      books = new Book[no_of_books];
    }

    void add_books(int new_books=0){
      int range = no_of_books+new_books;
      for(int i=no_of_books;i<range;i++){
        books[i].get_Book_details();
        no_of_books++;
      }
    } 


   void listAll_Books_inLib() const {
     std::cout<<"\nAvailable Books\nTitle: \n";
     for(int i=0;i<no_of_books;){
       if(books[i].getNo_ofCopies > 0){
       std::cout<<i<<". "<<books[i].getTitle()<<'\n';
       i++;
       }
     }
   } 
};

int main(){
  Book B{};

  int num;
  std::cout<<"\nEnter Number of Books to add in Library: ";
  std::cin>>num;


  Library L{};
  L.add_books(num);
  //B.display_details();
  L.listAll_Books_inLib();

  std::cout<<"\nCalling add books(3)\n";
  L.add_books(3);
  L.listAll_Books_inLib();
  return 0;
}
