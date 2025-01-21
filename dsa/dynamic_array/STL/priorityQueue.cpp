//in priority queue the element at front has the largest value
//based on tree structure
#include<bits/stdc++.h>
#include <functional>
#include <vector>

int main(void){
	std::priority_queue<int> pq;
	pq.push(5); //element in front 5
	pq.push(8); // 8, 5
	pq.push(7); // 8,7,5
	pq.push(3); //8,7,5,3
	pq.push(10); //10, 8, 7, 5, 3
	std::cout<<pq.top(); //return a const value from the front
	//the above implementation is know as max heap
	
	std::priority_queue<int, std::vector<int>, std::greater<int>> _pq; //this is the reverse of the above implmentation known as min heap
	pq.push(5); //5
	pq.push(2); //2, 5
	pq.push(3); //2,3,5
	pq.push(10); //2,3,5,10
	return 0;
}
