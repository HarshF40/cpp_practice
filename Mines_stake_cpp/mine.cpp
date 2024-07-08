#include<iostream>
#include"mine_f_decl.hpp"
#include<random>

float getmoney(){ //will return money which will be stored in variable throughout the game. Limit to the money in the wallet is 1000.
  system("clear");
  float money;
  do{
  std::cout<<std::endl<<"Enter The Amount of money to start with(1-1000): ";
  std::cin>>money;
  }while(money>1000 || money<0);
  return money;
}

void gen_be_grid(char (*arr_ptr)[5],void (*funcptr)(char (*)[5],int),int num_mines){ //generates grid full of diamond then passes the array through genmine with pointers to create mimnes.
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      arr_ptr[i][j]='0';
    }
  }
  funcptr(arr_ptr,num_mines);
}
