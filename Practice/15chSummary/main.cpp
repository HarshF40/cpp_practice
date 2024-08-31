#include<iostream>
#include<string>
#include<string_view>
#include<utility>
#include"Random.h"

class Monster{

  public:

 enum Type {
      Dragon,
      Goblin,
      Ogre,
      Orc,
      Skeleton,
      Troll,
      Vampire,
      Zombie,
      maxMonsterTypes,
    };


  private:
    Type type{};
    std::string name{"???"};
    std::string roar{"???"};
    int hitPoints{};

  public:

    Monster(Type itype,std::string_view iname,std::string_view iroar,int ihp) : type{itype},name{iname},roar{iroar},hitPoints{ihp}{}

   constexpr std::string_view getTypeString() const {
      switch(std::__to_underlying(type)){
        case 0 : return "Dragon"; 
        case 1 : return "Goblin"; 
        case 2 : return "Ogre";
        case 3 : return "Orc";
        case 4 : return "Skeleton";
        case 5 : return "Troll";
        case 6 : return "Vampire";
        case 7 : return "Zombie";
        default : return "???";
      }
    }

    void print() const {
      if(hitPoints>0)
      std::cout<<name<<" the "<<getTypeString()<<" has "<<hitPoints<<" hit points and says "<<roar<<".\n";
      else
        std::cout<<name<<" the "<<getTypeString()<<" is dead.\n";
    }

};

namespace MonsterGenerator{

  std::string_view getName(int val);
  std::string_view getRoar(int val);

  Monster generate() {
    return Monster{static_cast<Monster::Type>(Random::get(0,Monster::maxMonsterTypes-1)), getName(Random::get(0,5)), getRoar(Random::get(0,5)), Random::get(0,100)};
  }
  
   std::string_view getName(int val){
    switch(val){
      case 0 : return "Aaandu";
      case 1 : return "Baandu";
      case 2 : return "Caandu";
      case 3 : return "Daandu";
      case 4 : return "Eaandu";
      case 5 : return "Faandu";
      default : return "Gaandu";
    }
  }

   std::string_view getRoar(int val){
    switch(val){
      case 0 : return "*Aaaor*";
      case 1 : return "*Baaor*";
      case 2 : return "*Caaor*";
      case 3 : return "*Daaor*";
      case 4 : return "*Eaaor*";
      case 5 : return "*Faaor*";
      default : return "*Gaaor*";
    }
  }
};

int main(){

  Monster m{ MonsterGenerator::generate() };
	m.print();


	return 0;
}
