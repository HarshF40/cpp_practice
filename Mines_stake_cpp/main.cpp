#include<iostream>
#include"mine_f_decl.hpp"
#include<optional>

float money;

int main(){
  
  char choice; // choice whether to start,read rules or quit;
  
  system("clear"); //to clear the all other things from screen.
  std::cout<<std::endl<<"M!NES"<<std::endl<<std::endl<<std::endl;
  std::cout<<std::endl<<" Play(p)"<<std::endl<<" Rules(r)"<<std::endl<<" Quit(q)"<<std::endl;
  
  //do while loop till user enters a valid  input.
  
  do{
  std::cout<<std::endl<<"Enter your Choice: ";
  std::cin>>choice;
  }while(choice != 'p' && choice != 'P' && choice != 'r' && choice != 'q' && choice != 'R' && choice != 'Q');
switch(choice){
  case 'r' :
  case 'R' : return 0; // read rules will come afterwards. Will redirect to a function with rules and after that user will get choice to play or quit.
  case 'q':
  case 'Q': return 0; //Quits the Program.
  default : money=getmoney();
 }
 std::optional<char> quitch= 'c' ; //c for continue.
 while(quitch!=std::nullopt && *quitch!='q' && *quitch!='Q'){ //if money == 0 ;quitch = std::nullopt; 
   system("clear");
   //remaining program.
   quitch=std::nullopt;
 }
}