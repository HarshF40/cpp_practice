//kadanes Algorithm to find maximum sum in sub array
#include<bits/stdc++.h>
int main(void){
	std::vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
	int max_sum = INT_MIN;
	int sum = 0;
	//algorithm :
	//compare sum with max sum and make chnages accordingly
	//if sum < 0 then sum = 0
	//as it will make no sense carrying the negative element forward as it will always decrease the sum of sub array
	//time complexity: O(n)
	//space complexity: O(1)
	for(size_t i = 0; i < arr.size(); i++){
		sum += arr[i];
		max_sum = std::max(sum, max_sum);
		if(sum < 0) sum = 0;
	}
	std::cout<<max_sum;
	return 0;
}

/*
 * if to dispplay the subarray
 *#######################################
 * for(size_t i = 0; i < arr.size(); i++){
 * 	if(sum == 0) start = i; //because everytime we start gaining the sum, the start is always 0
 * 	sum += arr[i];
 * 	if(sum > max_sum) {
 * 		max_sum = sum;
 * 		ansStart = start;
 * 		ansEnd = i; //because the sum increases at i, if at all it increases greater than max_sum then end point = i
 * 	}
 * 	if(sum < 0) sum =  0;
 * }
 *########################################
 */
