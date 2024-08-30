#include<iostream>

class Cuboid;

class Box{

  private:
    double length{};
    double width{};
    double height{};

  public:
   explicit Box(double x,double y,double z) : length{x},width{y},height{z} {}

   double boxVolume(){ return length*width*height; }

   void boxCompare(const Cuboid& C) const ;

};



class Cuboid{

  private:
    double length{};
    double width{};
    double height{};

     public:
   explicit Cuboid(double x,double y,double z) : length{x},width{y},height{z} {}

   double cuboidVolume(){ return length*width*height; }

   friend void Box::boxCompare(const Cuboid& C) const;

};

/*class Box{

  private:
    double length{};
    double width{};
    double height{};

  public:
   explicit Box(double x,double y,double z) : length{x},width{y},height{z} {}

   double boxVolume(){ return length*width*height; }

   void boxCompare(const Cuboid& C) const ;

};*/

void Box::boxCompare(const Cuboid& C) const {
  double bV = length*width*height;
  double cV = C.length*C.width*C.height;
  if(bV > cV)
    std::cout<<"\nBox is greater!";
  else if(bV == cV)
    std::cout<<"\n--";
  else
    std::cout<<"\nCuboid is greater!";
}

int main(){

  Cuboid C{1.0,2.0,3.0};
  Box B{4.0,5.0,6.0};

  std::cout<<C.cuboidVolume()<<' '<<B.boxVolume();

return 0;
}

