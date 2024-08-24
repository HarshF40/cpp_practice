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
    last=head;

  } else {

    long unsigned int contact_no;

    user* temp = new user;

     std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    std::cout<<"\nEnter Full Name: ";
    std::getline(std::cin,temp->name);

    std::cout<<"\nEnter Contact No. : ";
    std::cin>>contact_no;

    for(user* temp=head;temp!=nullptr;temp=temp->next){
      if(temp->contact_no == contact_no){
        std::string exit;
        std::cout<<"\nUser Contact No already exists!";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"\nPress Enter to continue.";
        std::getline(std::cin,exit);
        std::cout<<"\n";
        delete temp;
        break;
      }
    }

    last->next = temp;
    last = temp;
    last->next=nullptr;

  }

}

void User::listUsers() const {

  if(head==nullptr){
    std::cout<<"\nNo Users In The Library!";
  } else {
    std::cout<<std::setw(20)<<std::left<<"Sr.No."<<std::setw(5)<<std::setw(20)<<std::left<<"User"<<std::setw(5)<<std::setw(20)<<std::left<<"Contact No.\n";
    std::cout<<"-------------------------------------\n";
    int i=1;
    user* temp;
  for(temp = head;temp!=nullptr;temp=temp->next,i++){
 std::cout<<std::setw(20)<<std::left<<i<<std::setw(5)<<std::setw(20)<<std::left<<temp->name<<std::setw(5)<<std::setw(20)<<std::left<<temp->contact_no<<'\n'; 
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
