#include<bits/stdc++.h>
int main(void){
	std::stack<int> s1;
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.push(6);
	s1.emplace(7);
	std::cout<<s1.top();
	s1.pop();
	std::cout<<s1.top()<<s1.size()<<s1.empty(); //.empty() return a bool, checks if stack is empty or not
	std::stack<int> s2;
	s1.swap(s2); //swaps the stacks
	std::cout<<s2.top();
	return 0;
}
