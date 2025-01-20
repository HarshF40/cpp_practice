#include<iostream>
#include<vector>
#include<optional>

template <typename T>
class Arr{
	private:
		std::vector<T> arr;
		T query;
	public:
		void getArr();
		void getQuery();
		void display();
		std::optional<size_t> binS();
};

template <typename T>
void Arr<T>::getArr(){
	size_t terms;
	T element;
	std::cout<<"Enter number of terms: ";
	std::cin>>terms;
	std::cout<<"Enter "<<terms<<" elements in DESCENDING order: ";
	for(auto i=0; i<terms; i++){
		std::cin>>element;
		arr.push_back(element);
	}
}

template <typename T>
void Arr<T>::display(){
	std::cout<<"Elements in the array: ";
	for(const auto element : arr){
		std::cout<<element<<" ";
	}
	std::cout<<std::endl;
}

template <typename T>
std::optional<size_t> Arr<T>::binS(){
	size_t low = 0;
	size_t high = arr.size() - 1;
	size_t position;
	while(low <= high){
		position = ((low + high) / 2);
		if(position < 0 || position > arr.size() - 1)
			return std::nullopt;
		if(arr[position] == query)
			return position;
		else if(arr[position] < query)
			high = position - 1;
		else if(arr[position] > query)
			low = position + 1;
	}
	return std::nullopt;
}

template <typename T>
void Arr<T>::getQuery(){
	std::cout<<"Enter the value to search: ";
	std::cin>>query;
}

int main(){
	Arr<int> arr;
	arr.getArr();
	arr.display();
	arr.getQuery();
	std::optional<size_t> result = arr.binS();
	if(result){
		std::cout<<"The position of the element is: "<<*result;
	} else {
		std::cout<<"Element Not Found!";
	}
	return 0;
}
