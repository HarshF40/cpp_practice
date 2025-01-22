//same as map but this can store duplicate/multiple value
//map[key] cannot be used here
//sorted order
#include<bits/stdc++.h>

int main(void){
	std::multimap<int, int> mm;
	mm.insert({1,2});
	mm.emplace(1,3); //we cant do this in normal map
	for(const auto& pair : mm)
		std::cout<<pair.first<<' '<<pair.second<<'\n';
	return 0;
}
