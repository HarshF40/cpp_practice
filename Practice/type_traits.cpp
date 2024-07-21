#include<iostream>
#include<type_traits>

enum class Color{
  pig,
  cat,
};

constexpr auto operator+(Color color){
  return static_cast<std::underlying_type_t<Color>>(color);
}

int main(){
  Color a{Color::pig};
  std::cout<<+a;
}