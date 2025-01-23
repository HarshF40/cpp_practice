#include <algorithm>
#include<bits/stdc++.h>

int main(void){
	std::vector<int> arr;
	size_t size;
	unsigned int k;
	std::cout<<"\nEnter number of elements in the arr: ";
	std::cin>>size;
	arr.resize(size); //resize the array, because if not then assignment wont work, because the vector will not be initialised
	std::cout<<"\nEnter Elements: ";
	for(size_t i = 0; i < size; i++) std::cin>>arr[i];

	std::cout<<"\nEnter the size of sliding window: ";
	std::cin>>k;

	int maxSum = 0;
	for(size_t i = 0; i < k; i++){
		maxSum += arr[i];
	}
	int currentSum = maxSum;
	for(size_t i = 1; i <= size - k; i++){
		currentSum = currentSum - arr[i - 1] + arr[k + i - 1];
		maxSum = std::max(maxSum, currentSum);
	}
	std::cout<<std::endl<<maxSum;
}
