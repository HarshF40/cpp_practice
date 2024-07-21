//to check if function parameters support auto.

#include<iostream>

template <typename T,typename U>
U calc(T a,U b){
  return a+b;
}

int main(){
  int a=5;
  double b=0.2;
  std::cout<<calc(a,b);
}