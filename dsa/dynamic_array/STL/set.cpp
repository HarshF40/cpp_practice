//keeps the data in sorted manner
//keeps only unique value
#include<bits/stdc++.h>

int main(void){
	std::set<int> s;
	s.insert(5); //5
	s.insert(2); //2,5
	s.insert(2); //2,5
	s.insert(1); //1,2,5
	s.insert(7); //1,2,5,7
	auto it = s.find(2); //returns an iterator from postion of element 2
	it = s.find(69); //it will still return an iterator pointing ta the end of the set
	s.erase(3); //erase the passed element
	int count = s.count(2); //will return either 1 or 0
	//range erasing also supported same as from vectors, we need to pass the iterators of the start point and end point
	//also learn about lower_bound and upper_bound
	return 0;
}
