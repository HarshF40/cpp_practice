#include<iostream>
#include<vector>
#include <string>
std::vector<int> strstr(std::string str, std::string needle){
	std::vector<int> idx;
	if (needle.empty()) {
		for(size_t i = 0; i < str.size(); i++ ){
			idx.push_back(i);
		}
		return idx;
	}
	//Note: 0th postion will always have 0 matching prefix suffix as a single char canot have suffix or prefix
	std::vector<int> lps(needle.length(), 0); //lps holds the number of characters matching in the string, at each position on i in the pattern
	size_t prevLPS = 0; //index pointer
	size_t i = 1;
	//creating LPS array
	while(i < needle.size()){
		if(needle[i] == needle[prevLPS]){ //check if the character is same as the next character
			lps[i] = prevLPS + 1;
			prevLPS++;
			i++;
		} else if(prevLPS == 0){ //if character is not same as the character as next character and, prevLPS is 0, then lps[i] will also be zero as there are no matching charcters, and you **cant even move back** to see if there are any other matching characters as prevLPS is at the start of the string, 
				lps[i] = 0;
				i+=1;
	        } else { //!!!
				prevLPS = lps[prevLPS - 1];
			}
		}
	i = 0;
	int j = 0;
	while(i < str.length()){
		if(str[i] == needle[i]){
			i++;
			j++;
		} else {
			if(j == 0){
				i++;
			} else {
				j = lps[j - 1];
			}
		}
		if(j == needle.length()){
			idx.push_back(i - needle.length());
		}
	}
	return idx;
}

int main(){
	std::string str = "ABAXABCABC";
	std::string needle = "ABC";
	std::vector<int> idx = strstr(str, needle);
	for(auto const elem : idx)
		std::cout<<elem;
	return 0;
}
