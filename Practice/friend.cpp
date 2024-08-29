#include<iostream>

class Storage;

class Display{

  private:
    bool displayIntFirst;

  public:
    Display(bool val) : displayIntFirst{val} {}
    void displayStorage(const Storage& str);
};

class Storage{

  private:
    int iVal;
    double dVal;

  public:
    Storage(int ival,double dval) : iVal{ival} ,dVal{dval} {}

    friend void Display::displayStorage(const Storage& str);
};

void Display::displayStorage(const Storage& str){
  if(displayIntFirst)
    std::cout<<str.iVal<<' '<<str.dVal;
  else
    std::cout<<str.dVal<<' '<<str.iVal;
}

int main(){

  Display d{false};
  Storage str{2,7.9};

  d.displayStorage(str);

  return 0;
}
