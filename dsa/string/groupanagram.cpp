#include<iostream>
#include<string>
#include<vector>

std::vector<std::vector<std::string>> quickSort(std::vector<std::string>&);
void qs(std::string&, int, int);
int partition(std::string&, int, int);
std::vector<std::vector<std::string>> sep(std::vector<std::string>);

int main(){
	std::vector<std::string> words = {"cat", "act", "dog", "god", "tac", "bat"};
	std::vector<std::vector<std::string>> solution;
	solution = quickSort(words);
	for(const auto& element: words)
		std::cout<<element<<" ";
	std::cout<<std::endl;
	for(const auto& row : solution){
		for(const auto& element : row)
			std::cout<<element;
		std::cout<<"\n";
	}
	std::cout<<std::endl;
	return 0;
}

std::vector<std::vector<std::string>> quickSort(std::vector<std::string>& words){
	for(size_t i = 0; i < words.size(); i++){
		qs(words[i], 0, words[i].size() - 1);
	}
	return sep(words);
}

void qs(std::string& word, int low, int high){
	if(low < high){
		int partitionIndex = partition(word, low, high);
		qs(word, low, partitionIndex - 1);
		qs(word, partitionIndex + 1, high);
	}
}

int partition(std::string& word, int low, int high){
	int i = low;
	int j = high;
	char pivot = word[low];
	while(i < j){
		while(pivot >= word[i] && i < high) i++;
		while(pivot < word[j] && j > low) j--;
		if(i < j) std::swap<char>(word[i], word[j]);
	}
	std::swap<char>(word[j], word[low]);
	return j;
}

std::vector<std::vector<std::string>> sep(std::vector<std::string> words){
	std::vector<std::vector<std::string>> solution;
	size_t prev = 0;
	size_t curr = 0;
	while(curr < words.size()){
		std::vector<std::string> temp;
		if(prev == curr){
			temp.push_back(words[curr]);
			curr++;
		} else if(words[prev] == words[curr]){
			temp.push_back(words[curr]);
			curr++;
			prev++;
		} else {
			prev = curr;
		}
		solution.push_back(temp);
	}
	return solution;
}
