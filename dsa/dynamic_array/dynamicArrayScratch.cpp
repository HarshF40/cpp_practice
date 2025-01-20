#include<cstddef>
#include<optional>
#include<iostream>
#include<initializer_list>

#define THRESHOLD 0.75
#define INITIAL_SIZE 0 

template <typename T>
class Node{
	public:
		std::optional<T> data = std::nullopt;
		Node* next = nullptr;
};

template <typename T>
class Base{
	private:
		std::size_t size; 
	public:
		Node<T>* base = nullptr;
		Base(std::size_t sze = INITIAL_SIZE) : size{sze} {
			if(size == 0){return;}
			base = new Node<T>{};
			Node<T>* temp = base;
			for(std::size_t i = 1; i < size; i++){
				temp->next = new Node<T>{};
				temp = temp->next;
			}
		}
		Base(std::initializer_list<T> list){ //to initialise the list using {}
			size = list.size();
			base = new Node<T>{*list.begin()};
			Node<T> *temp = base;
			for(T i = 1; i < size; i++){
				temp->next = new Node<T>{*(list.begin() + i)};
				temp = temp->next;
			}
		}
		std::size_t _length(){
			Node<T>* temp = base;
			std::size_t len = 0;
			while(temp != nullptr){
				if(temp->data){
					std::cout<<*temp->data;
				} else {
					continue;
				} //remove this line laterf
				temp = temp -> next;
				len++;
			}
			return len;
		}

};

int main(){
	Base<int> base{1,2,3,4,5};
	std::cout<<base._length();
	return 0;
}
