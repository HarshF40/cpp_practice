/*Create a class named Car that represents a car.
Inside this class,
       define a nested enum type Color that represents different colors a car can have, such as red, blue, and green.
       Also, define a nested class Engine inside the Car class. 
       The Engine class should have a function to print the engine details, 
       including the type of engine and the horsepower.
       Your program should create a Car object, set its color and engine properties, and then print out the car's color and engine details using the nested types.*/

#include<iostream>
#include<string>
#include<string_view>

class Car{

  public:

    enum Color{
      red,
      blue,
      green,
    };

    class Engine{

      public:
        using Hp = int;

      private:
        Hp HorsePower{};
        std::string engine_type{};

      public:
        Engine(Hp HP,std::string_view et) : HorsePower{HP},engine_type{et} {}
        void printEngine() const {
          std::cout<<"\nEngine Type: "<<engine_type<<"\nHorse Power: "<<HorsePower;
        }

    };

  private:
    Color color{};
    Engine m_engine;

  public:
    Car(Color C,std::string_view eng,int hp) :   color{C},m_engine{hp,eng} {}

    void PrintDetails() const {
      std::cout<<"\nColor : "<<color;
      m_engine.printEngine();
    }

};


std::ostream& operator<<(std::ostream& ou,Car::Color C){
switch(C) {
  case Car::Color::red : return ou<<"red";
  case Car::Color::blue : return ou<<"blue";
  case Car::Color::green : return ou<<"green";
  default: return ou<<"Invalid";
 }
}


int main(){
  const Car C{Car::Color::blue,"V16",1600};
  C.PrintDetails();
  return 0;
}
