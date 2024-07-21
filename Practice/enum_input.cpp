#include<iostream>
#include<string_view>
#include<string>
#include<optional>



enum Pet{
  cat,
  dog,
  pig,
  whale,
};

constexpr std::optional<Pet> getPetFromString(std::string_view sv){
  if(sv=="cat")
  return cat;
  else if(sv=="dog")
  return dog;
  else if(sv=="pig")
  return pig;
  else if(sv=="whale")
  return whale;
  else
  return{};
}

constexpr std::string_view displayPetName(Pet pet){
  switch(pet){
    case cat : return "cat";
    case dog : return "dog";
    case pig : return "pig";
    case whale : return "whale";
    default : return "???";
  }
}

int main(){
  std::cout<<"Enter a pet name(cat,dog,pig,whale): ";
  std::string s{};
  std::cin>>s;
  
  std::optional<Pet> pet{getPetFromString(s)};
  if(!pet)
  std::cout<<"\nInvalid Input.";
  else
  std::cout<<"Your Pet is: "<<displayPetName(*pet);
  return 0;
}