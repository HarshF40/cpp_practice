#include<bits/stdc++.h>

int main(void){
	size_t range;
	std::cout<<"\nEnter the range of number to check prime numbers in: ";
	std::cin>>range;
	std::vector<int> arr(range+1, 1); //create a array of 1's with the number of elements as range+1
	arr[0] = 0; //0 is not prime
	arr[1] = 0; //1 is not prime
	for(size_t i = 0; i*i <= range+1; i++){ //loop will go till i*i as that will cover the whole array, no nedd to check elements till end
		if(arr[i]){ //if you find a prime mark all its factor 0 as they are not prime
			for(size_t j = i*i; j <= range+1; j+=i)
				arr[j] = 0;
		}
	}
	for(size_t i = 0; i<range+1; i++){
		if(arr[i])
			std::cout<<i<<" ";
	}
	return 0;
}
