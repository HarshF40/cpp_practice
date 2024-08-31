#include<iostream>
#include<iomanip>
#include"Lib.hpp"

User::User() {
head = nullptr;
}

void User::addUsers(){

  do{

  if(head == nullptr){

    head = new user;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    std::cout<<"\nEnter Full Name: ";
    std::getline(std::cin,head->name);

    std::cout<<"\nEnter Contact No. : ";
    std::cin>>head->contact_no;

    head->next = nullptr;
    head->start = nullptr;
    last=head;

    std::cout<<"\nUser Added Succesfully!\n";

  } else {

    long unsigned int contact_no;

    std::string exit,name;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    std::cout<<"\nEnter Full Name : ";
    std::getline(std::cin,name);

    std::cout<<"\nEnter Contact No. : ";
    std::cin>>contact_no;

    bool check_contact = true;

    for(user* i = head;i!=nullptr;i=i->next){
      if(i->contact_no == contact_no){
        check_contact = false;
        break;
      }
    }

    if(!check_contact){
      std::cout<<"\nUser Already Exists!";
      std::cout<<std::endl;
    } else {
    user *temp = new user;
    temp->contact_no = contact_no;
    temp->name = name;

    last->next = temp;
    last = temp;
    last->start = nullptr;
    last->next=nullptr;

    std::cout<<"\nUser Added successfully!\n";

    }

  }

    char choice;
    std::cout<<"\nAdd User(u)/Quit(q): ";
    std::cin>>choice;

    if(choice == 'q')
      break;

    system("clear");
  }while(true);

}

void User::listUsers() const {

  if(head==nullptr){
    std::cout<<"\nNo Users In The Library!";
  } else {
    std::cout<<std::setw(20)<<std::left<<"Sr.No."<<std::setw(5)<<std::setw(5)<<std::left<<"User\n";
    std::cout<<"_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
    int i=1;
    user* temp;

  for(temp = head;temp!=nullptr;temp=temp->next,i++){
 std::cout<<std::setw(20)<<std::left<<i<<std::setw(5)<<std::setw(5)<<std::left<<temp->name<<'\n'; 
  }
 }
  std::cout<<std::endl;
}

void User::deleteUser(){

  if(head == nullptr){
    std::cout<<"\nNo Users";
  } else {

    listUsers();

    long unsigned int contact_no;

    std::cout<<"\nEnter The users contact No. : ";
    std::cin>>contact_no;

    bool flag = false;
    user* temp = head;
    user* follower = nullptr;
    for(;temp!=nullptr;temp=temp->next){
      if(temp->contact_no == contact_no){
        flag = true;
        if(temp == head){
          head = head -> next;
          std::cout<<temp->name<<" has been deleted!\n";          
          delete temp;
          break;
        } else if(temp == last){
          last = follower;
          last->next=nullptr;
          std::cout<<temp->name<<" has been deleted!\n";
          delete temp;
        } else {
          follower->next = temp->next;
          temp->next=nullptr;
           std::cout<<temp->name<<" has been deleted!\n";
           delete temp;
        }
      }
      follower = temp;
    }

  }
}

void User::borrow_book(Books& B){

  system("clear");

  bool check_book = false;

  std::cout<<"\nEnter Book Name: ";
  std::string book_name;
  std::cin>>book_name;
  Books::book *Bcurr=B.start;
  for(;Bcurr!=nullptr;){
    if(to_lower_string(book_name) == to_lower_string(Bcurr->Name)){
      check_book = true;
      break;
    }
    Bcurr=Bcurr->next;
  }

  if(check_book == false){
    std::cout<<"Book Not Found!";
  } else {

    bool check_user = false;

    std::cout<<"\nEnter Users Name: ";
    std::string user_name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::getline(std::cin,user_name);
    user *Ucurr = head;
    for(;Ucurr!=nullptr;){
      if(to_lower_string(user_name) == to_lower_string(Ucurr->name)){
        check_user = true;
        break;
      }
      Ucurr=Ucurr->next;
    }

    if(check_user == false){
      std::cout<<"\nUser Not Found!";
    } else {
      if(Ucurr->start == nullptr){
        book_borrowed* temp = new book_borrowed;
        temp->book_name = Bcurr->Name;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"\nBorrow Date: ";
        std::getline(std::cin,temp->borrow_date);
        std::cout<<"\nReturn Date: ";
        std::getline(std::cin,temp->return_date);
        temp->next = nullptr;
        Ucurr->start = temp;
        temp = nullptr;
      } else {
        book_borrowed* b_last = Ucurr->start;
        for(; b_last -> next != nullptr; b_last = b_last -> next){}
        book_borrowed* temp = new book_borrowed;
        temp->book_name = Bcurr->Name;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"\nBorrow Date: ";
        std::getline(std::cin,temp->borrow_date);
        std::cout<<"\nReturn Date: ";
        std::getline(std::cin,temp->return_date);
        temp->next = nullptr;
        b_last->next = temp;
        temp = nullptr;
      }
    }

  }

}

void User::ListBorrowedBooksByUser() const {

  system("clear");

  std::string name;

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  std::cout<<"\nEnter The Users Name: ";
  std::getline(std::cin,name);

  user *temp = head;

  for(;temp!=nullptr;temp=temp->next){
    if(to_lower_string(name) == to_lower_string(temp->name)){
      break;
    }
  }

  if(temp == nullptr){
    std::cout<<"\nUser Not Found!!!"<<std::endl;
    return;
  }

 for(book_borrowed *i = temp->start ; i!=nullptr ; i=i->next){
   std::cout<<"\nBook Name: "<<i->book_name;
   std::cout<<"\nBorrow Date: "<<i->borrow_date;
   std::cout<<"\nReturn Date: "<<i->return_date;
   std::cout<<'\n';
 } 

 std::cout<<'\n'<<std::endl;

}

void User::ReturnBook(){
  system("clear");
  std::cout<<"\nEnter Users Name: ";
  std::string uname;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  std::getline(std::cin,uname);
  user *u = head;
  for(;u!=nullptr;u=u->next){
    if(to_lower_string(uname) == to_lower_string(u->name))
      break;
  }
  if(u==nullptr){
    std::cout<<"\nUser Not Found!";
  }else{
    std::string bname;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout<<"\nEnter Book Name: ";
    std::getline(std::cin,bname);

    book_borrowed *temp,*follower;
    for(temp = u->start;temp!=nullptr;temp=temp->next){
      if(to_lower_string(bname) == to_lower_string(temp->book_name)){
        std::cout<<"true";
        break;
      }

      follower = temp;
    }

    if(temp == nullptr){
      std::cout<<"\nBook not found!";
    } else {
      if(temp == u->start){
        u->start = nullptr;
        delete temp;
      } else {
        follower->next = temp -> next;
        temp->next = nullptr;
        delete temp;
      }
      std::cout<<"\nBook has been deleted successfully!";
  }
    std::cout<<'\n';
}
}
