#include<bits/stdc++.h>

void quick_sort(std::vector<int>&);
void qs(std::vector<int>&, int, int);
int partition(std::vector<int>& arr, int, int);

int  main(void){
	size_t size;
	std::cout<<"\nEnter the size of the array: ";
	std::cin>>size;
	std::vector<int> arr(size);
	std::cout<<"\nEnter "<<size<<" elements: ";
	for(size_t i = 0; i < size; i++){ std::cin>>arr[i]; }
	quick_sort(arr);
	for(const auto& element : arr) { std::cout<<element<<" "; }
	return 0;
}

void quick_sort(std::vector<int>& arr){
	qs(arr, 0, arr.size() - 1);
}

void qs(std::vector<int>& arr, int low, int high){
	if(low < high) {
		int partitionIndex = partition(arr, low, high);
		qs(arr, low, partitionIndex - 1);
		qs(arr, partitionIndex + 1, high);
	}
}

int partition(std::vector<int>& arr, int low, int high){
	int i = low;
	int j = high;
	int pivot = arr[low];
	while(i < j) {
		while(pivot >= arr[i] && i < high) i++;
		while(pivot < arr[j] && j > low) j--;
		if(i < j) std::swap(arr[i], arr[j]);

	}
	std::swap(arr[j], arr[low]);
	return j;
}
