#include<iostream>
#include<string_view>

enum Pet{
  dino,
  lion,
  croc,
};

constexpr std::string_view getPetName(Pet pet){
  switch(pet){
    case dino : return "dinosaurs";
    case lion : return "lion"; 
    case croc : return "crocodile";
    default : return "???";
  }
}

std::ostream& operator<<(std::ostream& out,Pet pet){
  out<<getPetName(pet);
  return out;
}

int main(){
  Pet pet{dino};
  std::cout<<pet;
}