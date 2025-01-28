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
		if(pattern == str.substr(i, pattern.length())){
			indexes.push_back(i);
			i += pattern.length();
		} else {
			i++;
		}
	}

	for(const auto& idx : indexes)
		std::cout<<idx<<" ";

	return 0;
}
