#include<bits/stdc++.h>

int main(void){
	std::string str;
	std::string pattern;
	std::vector<size_t> indexes;
	std::cout<<"\nEnter String: ";
	std::cin>>str;
	std::cout<<"\nEnter Pattern: ";
	std::cin>>pattern;

	for(size_t i = 0; i < str.length() - pattern.length() + 1;){
		std::cout<<i<<std::endl;
		if(pattern == str.substr(i, pattern.length())){
			indexes.push_back(i);
			i += pattern.length();
//		} else if(pattern[0] == str.substr(i + 1, str.length() - i)[str.substr(i + 1, str.length() - i).find(pattern[0]) + 1]){ //come back later
//			i = str.substr(i + 1, str.length() - i).find(pattern[0]);
		} else {
			i++;
		}
	}

	for(const auto& idx : indexes)
		std::cout<<idx<<" ";

	return 0;
}
