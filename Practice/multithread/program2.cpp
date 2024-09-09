#include<iostream>
#include<thread>
#include<string>
#include<unistd.h>
#include<functional>
#include<chrono>

static bool flag = true;

void count(int &num){

  while(flag){
    num++;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

}

int main(){

  int num= 0;
  std::string name;

  std::thread timer(&count,std::ref(num));

  std::cout<<"\nEnter Your Name: ";
  getline(std::cin,name);

  std::cout<<"\n\nTime: "<<num<<std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(5));

  std::cout<<"\nHello "<<name;

  flag = false ;
  timer.join();

  std::cout<<"\n\nTime: "<<num;

  return 0;
}
