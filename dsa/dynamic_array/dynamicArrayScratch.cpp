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
		std::optional<T> data = static_cast<T>(0);
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
				std::cout<<*temp->data<<" ";
			}
			std::cout<<std::endl;
		}

		const T _front(){
			if(!base) {std::cout<<"Empty Array."; return;}
			return *base->data;
		}

		const T _back(){
			if(!base) {std::cout<<"Empty Array."; return;}
			Node<T> *temp = base;
			while(temp->next){ temp = temp->next; }
			return *temp->data;
		}

		Node<T>* _data(){
			return base;
		}
		
		void _push_back(T element){
			if(!base) {std::cout<<"Empty Array."; return;}
			Node<T>* temp = base;
			while(temp->next) { temp = temp->next; }
			temp->next = new Node<T>{element};
			size++;
		}

		void _pop_back(){
			if(!base) {std::cout<<"Empty Array."; return;}
			if(!base->next){
				Node<T> *temp = base;
				base = nullptr;
				delete temp;
			} else {
				Node<T> *temp = base;
				while(temp->next->next){ temp = temp->next; }
				Node<T> *another_temp = temp->next;
				temp->next = nullptr;
				delete another_temp;
				size--;
			}
		}

		void _insert(std::size_t index, T value){
			if (index > size + 1){
				_push_back(value);
			}else if(!base) {
				base = new Node<T>{value};
			} else {
				Node<T> *temp = base;
				for(std::size_t i = 0; i < index - 2; i++, temp = temp->next){}
				Node<T> *new_node = new Node<T>{value};
				new_node->next = temp->next;
				temp->next = new_node;
				size++;
			}
		}

};

int main(){
	Base<int> base(3);
	base[0] = 1;
	base[1] = 2;
	base[2] = 3;
	base.list();
	base._insert(5, 99);
	base.list();
	return 0;
}
