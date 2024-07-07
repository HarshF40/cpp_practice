#include<iostream>


int main(){
  
  char choice; // choice whether to start,read rules or quit;
  
  system("clear"); //to clear the all other things from screen.
  std::cout<<std::endl<<"M!NES"<<std::endl<<std::endl<<std::endl;
  std::cout<<std::endl<<" Play(p)"<<std::endl<<" Rules(r)"<<std::endl<<" Quit(q)"<<std::endl;
  
  //do while loop till user enters a valid  input.
  
  do{
  std::cout<<std::endl<<"Enter your Choice: ";
  std::cin>>choice;
  }while(choice != 'p' && choice != 'r' && choice != 'q' && choice != 'P' && choice != 'R' && choice != 'Q');
  
}