#include<bits/stdc++.h>
std::vector<int> strtstr(std::string str, std::string needle){
	std::vector<int> idx;
	if (needle.empty()) {
		for(size_t i = 0; i < str.size(); i++ ){
			idx.push_back(i);
		}
		return idx;
	}
	std::vector<int> lps(needle.length(), 0);
	size_t prevLPS = 1; //index pointer
	size_t i = 1;
	//creating LPS array
	while(i < needle.size()){
		if(needle[i] == needle[prevLPS]){
			lps[i] = prevLPS + 1;
			prevLPS++;
			i++;
		} else if(prevLPS == 0){
				lps[i] = 0;
				i+=1;
	        } else {
				prevLPS = lps[prevLPS - 1];
			}
		}

	i = 0;
	int j = 0;
	//actual pattern matching
	while(i < str.size()){
		if(str[i] == needle[j]){
			i++;
			j++;
		} else {
			if(j == 0){
				i++;
			} else {
			j = lps[j - 1];
		}
	}

	}
	if(j == needle.length()){
			idx.push_back();

}
