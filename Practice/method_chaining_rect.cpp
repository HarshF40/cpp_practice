//Design a class called Rectangle that represents a rectangle in a 2D space. The class should have the following requirements:
//
//Attributes:
//
//length: The length of the rectangle.
//
//width: The width of the rectangle.
//
//Constructor:A constructor that takes the length and width as arguments and initializes the object.
//
//Methods:
//
//setLength(double length): A method to set the length of the rectangle. Ensure that the method can be chained with the setWidth(double width) method by returning the object itself.
//
//setWidth(double width): A method to set the width of the rectangle. Ensure that the method can be chained with the setLength(double length) method by returning the object itself.
//
//calculateArea() const: A constant member function that calculates and returns the area of the rectangle.
//
//compareArea(const Rectangle& other) const: A constant member function that compares the area of the current rectangle with another rectangle passed as an argument. The function should return true if the current rectangle has a larger area, otherwise false.
//
//Use the this pointer explicitly in the setLength, setWidth, and compareArea methods.
//
//Display: Implement a display() method that prints the length, width, and area of the rectangle.
//
//
#include<iostream>

class Rectangle{

  private:
    double length{};
    double width{};

  public:
    Rectangle(double l=0,double w=0) : length{l},width{w} {}

    Rectangle& setLength(double len){
      length = len;
      return *this;
    }

    Rectangle& setWidth(double wid){
      width = wid;
      return *this;
    }

    double calculateArea() const {
      return length*width;
    }

    bool compareArea(const Rectangle& other) const {
      return calculateArea() > other.calculateArea() ? true : false ;
    }

    void Display() {
      std::cout<<"\n\nLength: "<<length<<"\n\nWidth: "<<width<<"\n\nArea of the Rectangle: "<<calculateArea()<<'\n';
    }

};

int main(){
  Rectangle R1{};
  Rectangle R2{7.0,9.8};
  double length,width;
  std::cout<<"\nEnter Length: ";
  std::cin>>length;
  std::cout<<"\nEnter Width: ";
  std::cin>>width;
  R1.setLength(length).setWidth(width);
    std::cout<<"\n\nRectangle 1: ";
    R1.Display();
    std::cout<<"\n\nRectangle 2: ";
    R2.Display();
  std::cout<<"\n\nRectangle 1 is "<< (R1.compareArea(R2) ? "greater" : "smaller") <<" than Rectangle 2!";
  return 0;
}
