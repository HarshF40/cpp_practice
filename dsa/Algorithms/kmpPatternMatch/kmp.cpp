#include<iostream>
#include<string>
#include <string_view>
#include<vector>

std::vector<int> getLSP(std::string_view str){
	int i = 1;
	int prevLSP = 0;
	std::vector<int> lsp(str.length(), 0);
	while(i < str.length()){
		if(str[prevLSP] == str[i]){
			lsp[i] = prevLSP + 1;
			i++;
			prevLSP++;
		} else if (prevLSP == 0){
			lsp[i] = 0;
			i++;
		} else { prevLSP = lsp[prevLSP - 1]; }
	}
	return lsp;
}

std::vector<int> kmp(const std::vector<int>& lsp, std::string_view str, std::string_view pattern){
	std::vector<int> idx;
	int i = 0;
	int j = 0;
	while(i < str.length()){
		if(str[i] == pattern[j]){
			i++;
			j++;
		} else if(j == 0) { i++; } else { j = lsp[j - 1]; }
		if(j == pattern.length()){
			idx.push_back(i - pattern.length());
			i++;
			j = 0;
		}
	}
	return idx;
}

int main(){
	std::string pattern = "ABABAC";
	std::string str = "ABABABACABABABAC";
	std::vector<int> lsp = getLSP(pattern);
	for(auto const element : lsp)
		std::cout<<element;
	std::vector<int> indexes = kmp(lsp, str, pattern);
	std::cout<<std::endl;
	for(const auto index : indexes)
		std::cout<<index<<" ";
	return 0;
}
