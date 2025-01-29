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
		} else {
			prevLSP = lsp[prevLSP - 1];
		}
	}
	return lsp;
}

std::vector<int> kmp(const std::vector<int>& lsp, std::string_view str, std::string_view pattern){
	std::vector<int> idx(str.length(), -1);
	int i = 0;
	int j = 0;
	while(i < str.length()){
		if(str[i] == pattern[j]){
			i++;
			j++;
		} else {

		}
	}
}

int main(){
	std::string str = "ABABAC";
	std::vector<int> lsp = getLSP(str);
	for(auto const element : lsp)
		std::cout<<element;
	return 0;
}
