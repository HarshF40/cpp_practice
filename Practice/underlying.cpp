#include<iostream>
#include<type_traits>
#include<utility>

enum Color{
  red,
  blue,
};

int main(){
  Color color{Color::red};
  using underlyingType = std::underlying_type_t<Color>;
  underlyingType a = static_cast<underlyingType>(color);
  std::cout<<a;
  
  std::cout<<std::__to_underlying(color);
}