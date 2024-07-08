#include<iostream>
#include"mine_f_decl.hpp"
#include<optional>
#include<random>

float money;

void gen_mine(char (*arr_ptr2)[5],int num_of_mines1){ // generates mine using mersenne twister random generator from the device.
  std::random_device rd{};
  std::seed_seq ss{rd(),rd(),rd(),rd(),rd(),rd(),rd(),rd()};
  std::mt19937 mt{ss};
  std::uniform_int_distribution genr{0,4};
  int r,c;
  for(int i=0;i<num_of_mines1;i++){
    loop:  // loop to check whether a mines exist on that position else generate a mine.
    r=genr(mt);
    c=genr(mt);
    if(arr_ptr2[r][c]=='*'){
      goto loop;
    } else {
      arr_ptr2[r][c]='*';
    }
    }
  }
  
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
   char backend_grid[5][5]; //This grid will contain all the data at backend. Like position of mine and diamond.
   char display_grid[9][9]={'#','|','#','|','#','|','#','|','#','-','|','-','|','-','|','-','|','-','#','|','#','|','#','|','#','|','#','-','|','-','|','-','|','-','|','-','#','|','#','|','#','|','#','|','#','-','|','-','|','-','|','-','|','-','#','|','#','|','#','|','#','|','#','-','|','-','|','-','|','-','|','-','#','|','#','|','#','|','#','|','#'}; //This grid will be used to display the grid and user will be able to interact with the grid;
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
   money-=bet_amount;
   system("clear");
   //loop do while quit,mine,open all mines.
   //std::cout<<std::endl<<"Remaining Money: "<<money<<"\n";
   int no_of_tiles=25 - no_of_mines;
   bool mine_open_flag=0;
   bool exit_flag=0;
 do{
   gen_be_grid(backend_grid,gen_mine,no_of_mines); //will generate backend_grid grid with mines and diamond.
   std::cout<<std::endl<<"Remaining Money: "<<money<<"\n";
   for(int i=0;i<9;i++){
     std::cout<<"\n";
     for(int j=0;j<9;j++){
       std::cout<<display_grid[i][j];
     }
   }
   
   int tiles_opened=0;
  // change formula
  // float total_win_amount = (1+(no_of_tiles/(25 - no_of_mines)))*(1+(no_of_mines/25))*bet_amount;
  // float multiplier = (1+(tiles_opened/(25 - no_of_mines)))*(1+(no_of_mines/25));
   int winmoney=0;
   
   std::cout<<"\nBet Amount: "<<bet_amount;
  // std::cout<<"\nMultiplier: "<<multiplier;
   std::cout<<"\nMoney Won: "<<winmoney;
  // std::cout<<"\nTotal Win Amount: "<<total_win_amount;
   
   //get the r & c inputs from user to start opening mines.
   exit_flag=1;
 }while(no_of_tiles>0 && mine_open_flag==0 && exit_flag==0 );
 if(money==0){
   quitch=std::nullopt;
 }
 std::cout<<std::endl<<"Quit or Stay(q/any key): ";
 char temp_quit_flag;
 std::cin>>temp_quit_flag;
 if(temp_quit_flag=='q' || temp_quit_flag=='Q') //else the loop will continue.
   quitch=std::nullopt;
 }
}