#include<iostream>
#include"mine_f_decl.hpp"

float getmoney(){ //will return money which will be stored in variable throughout the game. Limit to the money in the wallet is 1000.
  system("clear");
  float money;
  do{
  std::cout<<std::endl<<"Enter The Amount of money to start with(1-1000): ";
  std::cin>>money;
  }while(money>1000 || money<0);
  return money;
}