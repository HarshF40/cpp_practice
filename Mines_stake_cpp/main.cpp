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
  
  rule_loop:
  char rulevar;
  
  char choice; // choice whether to start,read rules or quit;
  
  system("clear"); //to clear the all other things from screen.
  std::cout<<std::endl<<"M!NES"<<std::endl<<std::endl<<std::endl;
  std::cout<<std::endl<<" Play(p)"<<std::endl<<" Read(r)"<<std::endl<<" Quit(q)"<<std::endl;
  
  //do while loop till user enters a valid  input.
  
  
  do{
  std::cout<<std::endl<<"Enter your Choice: ";
  std::cin>>choice;
  }while(choice != 'p' && choice != 'P' && choice != 'r' && choice != 'q' && choice != 'R' && choice != 'Q');
switch(choice){
  case 'r' :
  case 'R' : read_rules(); //some info about the Game.
             std::cout<<"Quit or Continue(q/any key): ";
             std::cin>>rulevar;
             if(rulevar=='q' || rulevar=='Q'){
               return 0;
             } else {
               goto rule_loop;
             }
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
   int diamonds_opened=0;
   // Adjust the factors as needed for desired scaling.
   float mine_factor = 15.5f; // Factor to amplify the effect of mines.
   float diamond_factor = 3.0f; // Factor to amplify the effect of diamonds.
   int no_of_diamonds=25 - no_of_mines;
   bool mine_open_flag=0;
   bool exit_flag=0;
   float multiplier = 1;
   
   int winmoney=0;
   int text_continue_or_quit=0;
   
 while(mine_open_flag==0 && exit_flag==0 ){
   gen_be_grid(backend_grid,gen_mine,no_of_mines); //will generate backend_grid grid with mines and diamond.
   multiplier = multiplier * (1 + (mine_factor * no_of_mines / 25.0f) +
   (diamond_factor * diamonds_opened / 25.0f));
   system("clear");
   std::cout<<std::endl<<"Remaining Money: "<<money<<"\n";
   
   for(int i=0;i<9;i++){
     std::cout<<"\n";
     for(int j=0;j<9;j++){
       std::cout<<display_grid[i][j];
     }
   }
   
   
   
   // float total_win_amount = (no_of_diamonds+no_of_mines)*(bet_amount/5);
   
   int row,column;
   
   
   
   //
   if(diamonds_opened==no_of_diamonds){
     system("clear");
     money+=winmoney;
     std::cout<<"\nOpened All The diamonds!";
     std::cout<<"\nMoney Won: "<<winmoney;
     std::cout<<"\nTotal Money: "<<money;
     for(int i=0;i<5;i++){
       for(int j=0;j<5;j++){
         display_grid[i*2][j*2]=backend_grid[i][j];
       }
     }
     //display the grid with diamonds and mines.
     for(int i=0;i<9;i++){
       std::cout<<"\n";
       for(int j=0;j<9;j++){
         std::cout<<display_grid[i][j];
       }
     }
    // exit_flag=1;
     break; // will come out of do-while. If only exit flag=1 is kept.. the inside do - while will execute anyways.
   }
   //get the row & column inputs from user to start opening mines.
   //do while will run until row and column are less than 4 and greater than 0 and if the position is already opened.
   
   
   
     std::cout<<"\nBet Amount: "<<bet_amount;
   std::cout<<"\nMultiplier: "<<multiplier;
   std::cout<<"\nMoney Won: "<<winmoney;
  // std::cout<<"\nTotal Win Amount: "<<total_win_amount;
  if(text_continue_or_quit){
     char con_q;
     std::cout<<"\nContinue Or Stop The Round?(c/q)";
     std::cin>>con_q;
     if(con_q=='q'){
       //exit_flag=1;
       money+=winmoney;
       break;
     }
   }
   
   do{
     
   std::cout<<std::endl<<"Enter The Position to open the tile: ";
   std::cin>>row>>column;
   }while(row>4 && row<0 || column>4 && column <0 || display_grid[row*2][column*2]!='#');
   if(backend_grid[row][column]=='*'){
     system("clear");
     std::cout<<"You have Opened a mine!";
     for(int i=0;i<5;i++){
       for(int j=0;j<5;j++){
         display_grid[i*2][j*2]=backend_grid[i][j];
       }
     }
     //display the grid with diamonds and mines.
     for(int i=0;i<9;i++){
       std::cout<<"\n";
       for(int j=0;j<9;j++){
         std::cout<<display_grid[i][j];
       }
     }
     std::cout<<"\nMoney lost: "<<bet_amount;
    //will get back to it to see if it breaks of off loop or not.
     mine_open_flag=1;
   } else if(backend_grid[row][column]=='0'){
     display_grid[row*2][column*2]=backend_grid[row][column];
     winmoney=bet_amount*multiplier;
    // money+=winmoney;
     diamonds_opened++;
     text_continue_or_quit=1;
   }
   
   //just to close loop
   //exit_flag=1;
 }
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