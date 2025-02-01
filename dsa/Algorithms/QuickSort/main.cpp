//1. Pick a pivot
//2. Place in its correct place
//3.Smaller on the left, larger go on the right
//--Divide and conquer algorithm
#include<iostream>
#include<vector>

int partition(std::vector<int>& arr, size_t low, size_t high){
	size_t i = low;
	size_t j = high;
//	while(i < j){
		while(arr[i] <= arr[low] && i < high) { i++; }
		while(arr[j] > arr[low] && j > low) { j--; }
		if(i < j) std::swap(arr[i], arr[j]);
//	}
	std::swap(arr[low], arr[j]);
	return j;
}

void qs(std::vector<int>& arr, size_t low, size_t high){
	if(low < high) {
		size_t partition_index = partition(arr, low, high);
		qs(arr, low, partition_index - 1);
		qs(arr, partition_index + 1, high);
	}
}

void quick_sort(std::vector<int>& arr){
	qs(arr, 0, arr.size()-1);
}

int main(){
	std::vector<int> arr = {7,2,4,1,9,8,3};
	quick_sort(arr);

	for(const auto element : arr)
		std::cout<<element;
	return 0;
}
