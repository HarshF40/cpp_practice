//1. Pick a pivot
//2. Place in its correct place
//3.Smaller on the left, larger go on the right
//--Divide and conquer algorithm
//size_t : unsigned; if size_t used it will cause underflow
#include<iostream>
#include<vector>

int partition(std::vector<int>& arr, int low, int high){
	int pivot = arr[low];
	int i = low;
	int j = high;
	while(i < j) {
		while(pivot >= arr[i] && i < high)
			i++;
		while(pivot < arr[j] && j > low)
			j--;
		if(i < j) std::swap(arr[i], arr[j]);
	}
	std::swap(arr[low], arr[j]);
	return j;

}

void qs(std::vector<int>& arr, int low, int high){
	if(low < high){
		int partition_index = partition(arr, low, high);
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

	std::cout<<"Array: ";
	for(const auto element : arr)
		std::cout<<element;
	std::cout<<std::endl;
	return 0;
}
