#include<iostream>
#include<optional>
int main(){
  std::optional<int> num = 5;
  std::cout<<*num;
}