#include<iostream>
#include<iomanip>
#include"Lib.hpp"

User::User() {
head = nullptr;
}

void User::addUsers(){


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

  } else {

    long unsigned int contact_no;

    std::string exit,name;

     std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    std::cout<<"\nEnter Full Name: ";
    std::getline(std::cin,name);

    std::cout<<"\nEnter Contact No. : ";
    std::cin>>contact_no;

    for(user* i=head;i!=nullptr;i=i->next){
      if(i->contact_no == contact_no){
        std::cout<<"\nUser Contact No already exists!";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"\nPress Enter to continue.";
        std::getline(std::cin,exit);
        std::cout<<"\n";
        break;
      } else {

    user *temp = new user;
    temp->contact_no = contact_no;
    temp->name = name;

    last->next = temp;
    last = temp;
    last->start = nullptr;
    last->next=nullptr;
        break;

      }
    }

  }

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

  std::string userName;
  std::string ibook_name;
  user* find_user,*follower;
  bool user_check_flag = false;
  bool book_check_flag = false;
  Books::book* curr = B.start;

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  std::cout<<"\nEnter User's Name: ";
  getline(std::cin,userName);


  for(find_user = head ;find_user!=nullptr;find_user=find_user->next){
    if(to_lower_string(userName) == to_lower_string(find_user->name))
      user_check_flag = true;
    follower = find_user;
  }

  if(!user_check_flag){
    std::string exit;
    std::cout<<"\nUser Not Found!\nEnter Press to continue";
    std::getline(std::cin,exit);
    return;
  }

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  std::cout<<"\nEnter The name of the book: ";
  std::getline(std::cin,ibook_name);

for(;curr!=nullptr;curr=curr->next){
  if(to_lower_string(ibook_name) == to_lower_string(curr->Name)){
    book_check_flag = true;
  break;
  }
}

if(!book_check_flag){
  std::string exit;
  std::cout<<"\nBook Not Found!\nPress Enter To continue";
  std::getline(std::cin,exit);
  return;
}

if(follower->start == nullptr){

  beg = new book_borrowed;

  follower->start = beg;
  (follower->start)->book_name = ibook_name;
  std::cout<<"\nToday's Date: ";
  std::getline(std::cin,(follower->start)->borrow_date);
  std::cout<<"\nEnter Returning Date: ";
  std::getline(std::cin,(follower->start)->return_date);

  (follower->start)->next = nullptr;
  beg = nullptr;
  delete beg;
  //copies--
} else {

  book_borrowed* walker = follower->start;

 for(;walker->next!=nullptr;walker=walker->next){}

  book_borrowed* temp;

  temp = new book_borrowed;

  temp->book_name = ibook_name;
  std::cout<<"\nToday's Date: ";
  std::getline(std::cin,temp->borrow_date);
  std::cout<<"\nEnter Returning Date: ";
  std::getline(std::cin,temp->return_date);

    walker->next = temp;
    temp->next = nullptr ;

    temp = nullptr;
    delete temp;

//copies--
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
    std::cout<<"\nUser Not Found!!!";
    return;
  }

  //
  //

 for(book_borrowed *i = temp->start ; i!=nullptr ; i=i->next){
   //
   //
   std::cout<<"\n"<<i->book_name;
 } 

 std::cout<<'\n'<<std::endl;

}
