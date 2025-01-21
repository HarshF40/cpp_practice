#include<cstddef>
#include <cstdlib>
#include<optional>
#include<iostream>
#include<initializer_list>
#include <csignal>

#define THRESHOLD 0.75
#define INITIAL_SIZE 0 

template <typename T>
class Node{
	public:
		std::optional<T> data = std::nullopt;
		Node<T>* next = nullptr;
};

template <typename T>
class Base{
	private:
		std::size_t size; 
	public:
		Node<T>* base;
		Base() : base{nullptr}, size{INITIAL_SIZE} {}

		Base(std::initializer_list<T> list){
			size = list.size();
			base = new Node<T>{*list.begin()};
			Node<T> *temp = base;
			for(T i = 1; i < size; i++){
				temp->next = new Node<T>{*(list.begin() + i)};
				temp = temp->next;
			}
		}

		Base(std::size_t new_size) : size{new_size} {
			if(new_size == 0){ return; }
			size = new_size;
			base = new Node<T>{};
			Node<T>* temp = base;
			for(std::size_t i = 1; i < size; i++){
				temp->next = new Node<T>{};
				temp = temp->next;
			}
		}

		std::size_t _length(){
			Node<T>* temp = base;
			std::size_t len = 0;
			while(temp != nullptr){
				temp = temp -> next;
				len++;
			}
			return len;
		}

		void operator()(std::size_t new_size = INITIAL_SIZE){
			if(new_size == 0){ return; }
			size = new_size;
			base = new Node<T>{};
			Node<T>* temp = base;
			for(std::size_t i = 1; i < size; i++){
				temp->next = new Node<T>{};
				temp = temp->next;
			}
		}

		T& operator[](std::size_t index){
			if(index >= size || base == nullptr){
				std::cerr<<"Out of bound!\n";
				std::abort();
			} else {
				Node<T> *temp = base;
				for(std::size_t i = 0; i < index; i++){
					temp = temp->next;
				}
				return *temp->data;
			}
		}

		void list(){
			for(Node<T> *temp = base; temp!=nullptr; temp=temp->next){
				if(temp)
				std::cout<<*temp->data<<" ";
				else
				std::cout<<"?";
			}
			std::cout<<std::endl;
		}

		const T _front(){
			return *base->data;
		}

		const T _back(){
			Node<T> *temp = base;
			while(temp->next){}
			return *temp->data;
		}

};

int main(){
	Base<int> base(3);
	base[0] = 5;
	std::cout<<base._front()<<base._length();
	return 0;
}
