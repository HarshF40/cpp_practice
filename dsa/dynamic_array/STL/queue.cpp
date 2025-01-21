#include<bits/stdc++.h>
#include <queue>

int main(void){
	std::queue<int> q;
	q.push(1);
	q.push(2);
	q.emplace(3); //all this methods add the element at the back;
	q.back() += 5;//q.back gives the access to the last element;
	q.front() += 5; //q.front gives the access to the first element;
	q.pop();  //removes the first element
	//rest all functionalities same as stack
	return 0;
}
