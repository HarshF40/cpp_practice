#include<iostream>

template <typename T>
class Node{
public:
        T data;
        Node<T> *next;
        Node(T value, Node<T>* nxt = nullptr) : data{value}, next{nxt} {}
};

template <typename T>
class Stack{
        Node<T> *top = nullptr;
public:
        void push(T value){
                if(!top){ top = new Node<T>(value);} else {
                        Node<T> *new_node = new Node<T>(value,top);
                        top = new_node;
                }
        }

        void pop(){
                if(!top){ std::cout<<"\nStack UnderFlow"; } else {
                        Node<T> *temp = top;
                        top = top->next;
                        delete temp;
                }
        }

        void peep(){
                Node<T> *temp = top;
                while(temp){
                        std::cout<<temp->data<<" ";
                        temp = temp->next;
                }
                std::cout<<std::endl;
        }

        T getTop(){
                return top->data;
        }
};

int main(void) {
        Stack<int> stack;
        stack.push(1);
        stack.peep();
        stack.push(2);
        stack.push(3);
        stack.peep();
        //std::cout<<stack.getTop();
        stack.pop();
        stack.peep();
        stack.pop();
        stack.peep();
        //std::cout<<stack.getTop();
        return 0;
}
