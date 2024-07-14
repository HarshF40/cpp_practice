#include<iostream>
#include<limits>
#include<optional>
#include<string_view>
#include<string>

enum Pet{
  dog,
  cat,
  komodo,
};

constexpr std::optional<Pet> getPetFromString(std::string_view sv){
  if(sv=="dog")
  return dog;
  else if(sv=="cat")
  return cat;
  else if(sv=="komodo")
  return komodo;
  else
  return {};
}

std::istream& operator>>(std::istream& in,Pet& pet){ // Modifying(Teaching) input stream to read enumerators of type Pet.
  std::string s{};
  in>>s;
  
  std::optional<Pet> match{getPetFromString(s)};
  if(match){
    pet = *match;
    return in;
  }
  
  in.setstate(std::ios_base::failbit); // Sets input stream to fail state.
  return in; // Returns input stream in failed state.
  
}

constexpr std::string_view getPetName(Pet pet){
  switch(pet){
    case dog : return "dog";
    case cat : return "cat";
    case komodo : return "komodo";
    default : return "???";
  }
}

std::ostream& operator<<(std::ostream& out,Pet pet){ // Modifying(Teaching) output stream to write enumerator of type Pet.
  return out<<getPetName(pet);
}

int main(){
  std::cout<<"Enter Your Pet(cat,dog,komodo): ";
  Pet pet{};
  std::cin>>pet;
  if(std::cin){
    std::cout<<"Your pet is "<<pet<<std::endl;
  } else {
    std::cin.clear(); // Resets Streams State.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // Ignores the character in input buffer.
    std::cout<<"Your pet is invalid!\n";
}
return 0;
}