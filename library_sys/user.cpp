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

    user* temp = new user;

     std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    std::cout<<"\nEnter Full Name: ";
    std::getline(std::cin,temp->name);

    std::cout<<"\nEnter Contact No. : ";
    std::cin>>temp->contact_no;

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
