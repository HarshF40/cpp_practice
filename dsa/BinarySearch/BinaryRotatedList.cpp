#include<iostream>
#include<vector>
#include<cmath>

std::size_t rpos(const std::vector<int>& arr){
	int low = 0;
	int high = arr.size() - 1;
	int mid;
	while(low<=high){
		mid = ((low+high)/2);
		if(mid > 0 && arr[mid - 1] == arr[mid]){ //To handle the repeating number case
			mid = mid - 1;
		}
		if(mid > 0 && ((arr[mid-1] > arr[mid]) || (low == high && high == mid))){
			return mid;
		}
		else if( std::abs(arr[low] - arr[mid])  <  std::abs(arr[high] - arr[mid])  &&  (arr[low-1] < arr[low]) ){
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	} 
	return 0;
}

int main(){
	std::vector<int> arr = {6,6,9,9,0,0,2,3,3,3,4,4};
	std::cout<<"Position: "<<rpos(arr);
	return 0;
}
