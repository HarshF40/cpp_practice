#include <bits/stdc++.h>

int main(){
	std::vector<int> arr = {2, 4, 6, 8, 10};
	std::vector<int> suffix;
	int suffix_sum = 0;
	for(int i = arr.size() - 1; i > -1; i--){
		suffix_sum += arr[i];
		suffix.insert(suffix.begin(), suffix_sum);
	}
	for(const auto& element : suffix)
		std::cout<<element<<" ";
	return 0;
}
