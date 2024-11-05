//when ownership the data is 'transferred' from
//one object to another we say that data has been
//"moved"

//when move semantics is invoked any data member
//that can be moved is moved and any data member
//that cant be moved is copied

//move semantics are invoked when:
//1.the object supports move semnatics
//2.the object is being initialized with a
//"rvalue"
//of the same data type
//3.move isnt elided
//std::vector and std::string supports move 
//semantics

#include<iostream>
#include<vector>
#include<utility>

std::vector<int> doSomething(const std::vector<int>& v2);

int main(){
  std::vector<int> v1{5};
  std::cout<<doSomething(v1)[0];
  return 0;
}

std::vector<int> doSomething(const std::vector<int>& v2){
  std::vector<int> vec3 {v2[0]+v2[0]};
  return std::move(vec3);
}