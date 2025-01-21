//same as set but it doesnt follow the unique rule
#include<bits/stdc++.h>

int main(void){
	std::multiset<int> ms;
	ms.insert(1);
	ms.insert(1);
	ms.insert(1);
	ms.insert(3); // 1,1,1,3
	//ms.erase(1); // will erase all the occurances on 1
	//but we can controll the number of erase by passing address to the element,
	//this will be helpful to delete one element
	//we can also delete range of element that means we can controll number of erases
	//ms.erase(ms.find(1)); //finds the first occurance of the 1 and passes the address to ms.erase,
			      //to erase from that address
	//we can also delete a range
	auto it1 = ms.find(1); //first find the first occurance
	auto it2 = it1; //create it2 and point to the same as it1
	std::advance(it2, 1); //move it2 by 2 steps, we cant do simple arithmetic because iterators are not random access iterator
	ms.erase(it1, it2);
	return 0;
}
