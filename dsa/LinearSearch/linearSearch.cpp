#include<iostream>
#include<vector>
#include<optional>

std::optional<size_t> search(const std::vector<int>&, int);

int main(){
	std::vector<int> arr = {13, 11, 10, 7, 4, 3, 1, 0};
	int query = 99;
	std::optional<size_t> result = search(arr, query);
	if(result){
		std::cout<<"\nThe Position is: "<<*result<<"\n";
	} else {
		std::cout<<"Element not found!\n";
	}
	return 0;
}

std::optional<size_t> search(const std::vector<int>& arr, int query){
	for(size_t i=0; i<arr.size(); i++){
		if(arr[i] == query)
			return i;
	}
	return std::nullopt;
}
