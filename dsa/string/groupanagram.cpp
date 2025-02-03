#include<iostream>
#include<string>
#include<vector>

template <typename T>
void qs(T&, int, int);

template <typename T>
int partition(T&, int, int);

void quickSort(std::vector<std::string>&);
std::vector<std::vector<std::string>> sep(std::vector<std::string>);
std::vector<std::vector<std::string>> quickSortM_(std::vector<std::string>&);

int main(){
	std::vector<std::string> words = {"cat", "act", "dog", "god", "tac", "bat"};
	std::vector<std::vector<std::string>> solution;
	
	quickSort(words); //sorts each string in the array
	solution = quickSortM_(words); //sorts the the whole array

	//display the array
	for(const auto& row : solution){
		for(const auto& element : row){ std::cout<<element<<" "; }
		std::cout<<std::endl;
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////
//Quick Sort algorithm
void quickSort(std::vector<std::string>& words){ 
	for(size_t i = 0; i < words.size(); i++) qs(words[i], 0, words[i].size() - 1); 
}

std::vector<std::vector<std::string>> quickSortM_(std::vector<std::string>& words){
	qs(words, 0, words.size() - 1);
	return sep(words);
}

template <typename T>
void qs(T& word, int low, int high){
	if(low < high){
		int partitionIndex = partition(word, low, high);
		qs(word, low, partitionIndex - 1);
		qs(word, partitionIndex + 1, high);
	}
}

template <typename T>
int partition(T& word, int low, int high){
	int i = low;
	int j = high;
	auto pivot = word[low];
	while(i < j){
		while(pivot >= word[i] && i < high) i++;
		while(pivot < word[j] && j > low) j--;
		if(i < j) std::swap(word[i], word[j]);
	}
	std::swap(word[j], word[low]);
	return j;
}
/////////////////////////////////////////////////////////////////////////////////////
//seggregate the arrays
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
