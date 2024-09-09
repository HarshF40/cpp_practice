#include<iostream>
#include<thread>

void func(unsigned int num){
  std::cout<<"Other Thread"<<std::endl;
  std::cout<<"Arguement Passed: "<<num<<std::endl;
}

int main(){

  std::thread thread1(&func,100);
  thread1.join();
  
  std::cout<<"Main Thread!"<<std::endl;

  return 0;
}
