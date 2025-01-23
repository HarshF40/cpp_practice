#include<bits/stdc++.h>
#include <string>
#include <string_view>
#include <unordered_set>

bool helper(std::string_view, int&);
static unsigned int k;
static int max_len = 0;

int main(){
	std::string str;
	std::cout<<"\nEnter String: ";
	std::cin>>str;
	std::cout<<"\nEnter distinct factor: ";
	std::cin>>k;
	int i = 0;
	int j = k;
	while(i < str.length() - k + 1){
		std::cout<<std::endl;
		if(helper(str.substr(i, j), max_len) && j < str.length()){
			j++;
		} else {
			i++;
		}
	}
	std::cout<<max_len;
	return 0;
}

bool helper(std::string_view str, int& max_len){
	std::unordered_set<char> set;
	for(size_t i = 0; i < str.length(); i++){ 
		set.emplace(str[i]); 
	}
	if(set.size() <= k){ 
		if(max_len < str.size())
			max_len = str.size();
		return true;
	}
	return false;
}
