#include<iostream>

template <typename T>
class Node{
public: 
	T data;
	Node<T> *next = nullptr;
	Node(T value) : data{value} {}
};

template <typename T>
class Queue{
public:
	Node<T> *head = nullptr;
	Node<T> *tail = nullptr;
	void add(T data){
		if(!head){
			head = new Node<T>(data);
			tail = head;
		} else {
			Node<T> *temp = new Node<T>(data);
			tail->next = temp;
			tail = temp;
			temp = nullptr;
		}
	}

	void leave(){
		if(!head){
			std::cout<<"Empty Queue\n";
		} else {
			Node<T> *temp = head;
			head = head->next;
			delete temp;
		}
	}

	void peep(){
		Node<T> *temp = head;
		while(temp){
			std::cout<<temp->data<<" ";
			temp = temp->next;
		}
		std::cout<<std::endl;
	}
};

int main(void){
	Queue<int> q;
	q.add(1);
	q.add(2);
	q.add(3);
	q.peep();
	q.add(4);
	q.peep();
	q.leave();
	q.peep();
	q.leave();
	q.leave();
	q.peep();
	return 0;
}
