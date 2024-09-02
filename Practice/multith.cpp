#include<iostream>
#include<thread>

long unsigned int i=0;
bool flag = false;

void print(){
 while(!flag){
  i++;
 }
}


int main(){

 std::thread worker(print);

 std::cin.get();

 flag = true;

 worker.join();

 std::cout<<i;

 return 0;
}
