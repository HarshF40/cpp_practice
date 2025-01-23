#include <algorithm>
#include <set>
#include <unordered_map>
#include <vector>
#include <iostream>
int main(void){

	std::vector<int> arr = {3, -1, -7, 2, 5, -4, -6, 8, 1};
	std::unordered_map<int, int> set;
	std::set<std::vector<int>> solution;

	int i = 0;
	for(const auto& element : arr) {
		set.emplace(element, i);
		i++;
	}

	for(int i = 0; i < arr.size(); i++){
		for(int j =  i + 1 ; j < arr.size(); j++){
			int target = -(arr[i] + arr[j]);
			auto it = set.find(target);
			if(it != set.end() && ( i != it->second && j != it->second)){
				std::vector<int> temp = {arr[i], arr[j], -(arr[i]+arr[j])};
				std::sort(temp.begin(), temp.end());
				solution.emplace(temp);
			}
		}
	}

	for(const auto& vec : solution){
		std::cout<<std::endl;
		for(const auto& elem : vec){
			std::cout<<elem;
		}
	}

	return 0;
}
