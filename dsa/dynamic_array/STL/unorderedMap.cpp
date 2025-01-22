//same difference between map, as difference betweem set and unordered set
//works in O(1), worst case scenario O(N)
//unordered but unique
//rest all functionalities same as maps
#include<bits/stdc++.h>

int main(void){
	std::unordered_map<int, int> ump;
	ump.insert({1,2});
	ump.insert({1,3});
	ump.emplace(3,4);
	for(auto const& pair : ump){
		std::cout<<pair.first<<" "<<pair.second<<'\n';
	}
	return 0;
}
