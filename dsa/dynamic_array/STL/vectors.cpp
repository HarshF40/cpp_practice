#include<bits/stdc++.h>

int main(){
	std::vector<int> arr(5, 100);
	arr.emplace_back(77); //same like push_back and better than push_back
	for(const auto& element : arr){
		//std::cout<<element<<" ";
	}
	std::vector arr2(arr); //copying arr into arr2
	for(const auto& element : arr2){
		//std::cout<<element<<" ";
	}

	//iterator
	for(std::vector<int>::iterator it = arr.begin(); it != arr.end() ; it++){
		//std::cout<<*it<<" ";
	}
	std::cout<<std::endl;
	arr2.erase(arr2.begin()+3);
	for(const auto& element : arr2)
		std::cout<<element<<" ";
	arr2.erase(arr2.begin(), arr2.begin()+2);
	std::cout<<std::endl;
	for(const auto& element : arr2)
		std::cout<<element<<" ";
	return 0;
}
