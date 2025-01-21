//almost same as vectors but wuth push_front feature
//list is based on doubly linked list where as vector is on singly linked list
//list is better in time complexity than vectors in most of the operations
#include<bits/stdc++.h>

int main(void){
	std::list<int> ls;
	ls.push_front(7);
	ls.emplace_front(9);
	//rest all same as the vector
	for(const auto& element : ls){
		std::cout<<element<<" ";
	}
	return 0;
}
