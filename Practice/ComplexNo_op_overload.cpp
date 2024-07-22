//Overloading I/O Operators
//Problem: Define a Complex struct for complex numbers with real and imag members. Overload the << and >> operators for input and output of Complex numbers. Bonus: Overload the + operator to add two Complex numbers.

#include<iostream>
template <typename T>
struct ComplexNo{
  T real;
  T imaginary;
  char op;
  char iota;
  ComplexNo(T r=0,T im=0,char o='+',char io='i') : real(r),imaginary(im),op(o),iota(io) { }
};
template <typename T>
std::istream& operator>>(std::istream& in,ComplexNo<T>& temp){
  return in>>temp.real>>temp.op>>temp.imaginary>>temp.iota;
}
template <typename T>
ComplexNo<T> operator+(const ComplexNo<T> &one,const ComplexNo<T> &two){
  return ComplexNo<T>(one.real+two.real,one.imaginary+two.imaginary,'+','i');
}
template <typename T>
std::ostream& operator<<(std::ostream& os,const ComplexNo<T> &ans){
  return (os<<ans.real<<" "<<ans.op<<" "<<ans.imaginary<<" "<<ans.iota);
}
int main(){
  ComplexNo first{0,0,'+','i'};
  ComplexNo second{0,0,'+','i'};
  std::cin>>first;
  std::cin>>second;
  ComplexNo ans{first+second};
  std::cout<<ans;
}