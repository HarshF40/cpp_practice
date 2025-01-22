//key value pair
//unique and sorted
#include<bits/stdc++.h>
//if you try to insert a value with same key with .emplace or .insert then it will not overwrite
//the value but if you try it with [] it will overwrite/update the value
int main(void){
	std::map<int, int> mp;
	mp[1] = 2;
	mp.emplace(3, 1); //to insert the element in the map
	mp.insert({7, 4}); //to insert the element in the map, always pass it as a pair
	for(const auto& [key, val] : mp)
		std::cout<<key<<" "<<val<<'\n';
	auto ptr = mp.find(4); //if the key exist it will point to it or else end of the map
	std::cout<<ptr->first<<" "<<ptr->second;
}
