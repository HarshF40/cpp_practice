#include<iostream>
#include <string>
#include<unordered_map>

bool checkAnagram(const std::string& s1, const std::string& s2){
	if(s1.length() != s2.length()){
		return false;
	} else {
		std::unordered_map<char, int> mp;
		for(size_t i = 0; i < s1.length(); i++){
			mp[s1[i]]++;
			mp[s2[i]]--;
		}
		for(const auto& val : mp){
			if(val.second != 0) return false; 
		}
	}
	return true;
}

int main(){
	std::string s1;
	std::string s2;
	std::cout<<"\nEnter s1: ";
	std::cin>>s1;
	std::cout<<"\nEnter s2: ";
	std::cin>>s2;
	if(checkAnagram(s1, s2)){
		std::cout<<"\nAnagram!!!";
	} else {
		std::cout<<"\nNot an Anagram.";
	}
	return 0;
}
