// Member Selection with Pointers and References
// Problem: Define a Rectangle struct with members width and height. Write a function that takes a pointer to a Rectangle and returns the area of the rectangle.

#include<iostream>

template <typename T,typename U>
struct Rectangle{
  T width;
  U height;
};

template <typename T,typename U>
Rectangle(T,U) -> Rectangle<T,U>;

template <typename T,typename U>
void getVal(Rectangle<T,U> &Rect){
  std::cout<<"\nEnter Width: ";
  std::cin>>Rect.width;
  std::cout<<"\nEnter Height: ";
  std::cin>>Rect.height;
}

template <typename T,typename U>
auto area(Rectangle<T,U> *Rect){
  return ((Rect -> width)*(Rect -> height));
}

int main(){
 Rectangle Rect{0,0};
 getVal(Rect);
 std::cout<<"\nArea: "<<area(&Rect)<<" units \n";
  return 0;
}