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
   float bet_amount;
   int no_of_mines;
   char change; // this will take yes or no from user as y or n to edit the inputs, the loop will go on till user enters n.
   do{
   std::cout<<"Amount in Wallet: "<<money;
   std::cout<<std::endl<<"\nEnter the Bet Amount: ";
   std::cin>>bet_amount;
   std::cout<<std::endl<<"Enter No. of Mines: ";
   std::cin>>no_of_mines;
   std::cout<<std::endl<<"Edit the choices?(y/n): \n";
   std::cin>>change;
   if(bet_amount>money || no_of_mines<1 || no_of_mines>24)
   change='y';
   }while(change=='y' || change == 'Y');
   system("clear");
   money-=bet_amount;
   std::cout<<std::endl<<"Remaining Money: "<<money;
   quitch=std::nullopt;
 }
}