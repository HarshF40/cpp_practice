#include<iostream>

template <typename T,size_t N>
T sumarr(const T (&arr)[N]){
  T sum=0;
  for(size_t i{};i<N;i++){
    sum+=arr[i];
  }
  return sum;
}

int main(){
  int arrint[]{1,2,3,4};
  std::cout<<sumarr(arrint);
  float arrfloat[]{2.4,7.9,9.9,5.7};
   std::cout<<sumarr(arrfloat);
}