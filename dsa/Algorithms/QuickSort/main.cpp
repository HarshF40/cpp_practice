//1. Pick a pivot
//2. Place in its correct place
//3.Smaller on the left, larger go on the right
//--Divide and conquer algorithm
#include<bits/stdc++.h>

int partition(std::vector<int>& arr, int low, int high){
	int i = low;
	int j = high;
	while(i < j){
		std::cout<<"Hi";
		while(arr[i] <= arr[low] && i < high) i++;
		while(arr[j] >= arr[low] && j > low) j++;
		if(i < j) std::swap(arr[i], arr[j]);
	}
	std::swap(arr[low], arr[j]);
	return j;
}

void qs(std::vector<int>& arr, int low, int high){
	if(low < high) {
		int partition_index = partition(arr, low, high);
		qs(arr, low, partition_index - 1);
		qs(arr, partition_index + 1, high);
	}
}

void quick_sort(std::vector<int>& arr){
	qs(arr, 0, arr.size()-1);
}

int main(){
	std::vector<int> arr = {4,1,1,7,3,8,2,565,6,3,43,446};
	quick_sort(arr);
	for(const auto element : arr)
		std::cout<<element;
	return 0;
}
