#include<iostream>
#include<map>

int main(){
	std::string s1;
	std::string s2;
	std::map<char, int> s1m;
	std::map<char, int> s2m;
	std::cout<<"\nEnter String1: ";
	std::cin>>s1;
	std::cout<<"\nEnter String2: ";
	std::cin>>s2;
	
	if(s1.length() != s2.length()){
		std::cout<<"\nNot a Anagram.";
		return -1;
	} else {
		for(const auto chr : s1){ s1m[chr]++; }
		for(const auto chr : s2){ s2m[chr]++; }
		for(size_t i = 0; i < s1m.size(); i++) { 
			if(s1m[i] != s2m[i]) {
				std::cout<<"\nNot an anagram";
				return -1;
			}
		}
	}
	std::cout<<"\nAnagram!!!";
	return 0;
}
