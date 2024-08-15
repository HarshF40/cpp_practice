#include<iostream>

class Fruit{

  public:
    enum Type {
      apple,
      banana,
      cherry,
    };

  private:
    Type m_type{};
    int percentageEaten{0};

  public:
    Fruit(Type type) : m_type{type} {}

    Type getType() const {return m_type;}

    int getPercenatgeEaten() const {return percentageEaten;}

    bool isCherry() const {
      return m_type==cherry ? true : false ;
    }
};

int main(){
  const Fruit apple{Fruit::apple};
  if(apple.getType() == Fruit::apple)
    std::cout<<"\nI am an Apple!";
  else
    std::cout<<"\nI am not an apple!";
return 0;
}
