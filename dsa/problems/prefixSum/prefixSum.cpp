//prefix sum is used here:
//sum(l, r) = prefix_sum[r] - prefix_sum[l-1]

#include<bits/stdc++.h>

int main(){
	std::vector<int> arr = {2, 4, 6, 8, 10};
	std::vector<int> prefix;
	int prefix_sum = 0;
	for(int i = 0; i < arr.size(); i++){
		prefix_sum += arr[i];
		prefix.push_back(prefix_sum);
	}
	for(const auto& element : prefix)
		std::cout<<element<<" ";
	std::cout<<std::endl;
	std::cout<<prefix[-1];
	return 0;
}
