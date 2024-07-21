#include<iostream>

template <typename T=int,typename U=int>
struct Pair{
T first{};
U second{};
};

template <typename T,typename U>
Pair(T,U) -> Pair<T,U>;

int main(){
Pair<int,double> p1{1,2.3};
Pair p2{1,2};
Pair p3;
}