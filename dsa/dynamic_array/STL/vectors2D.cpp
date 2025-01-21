#include<bits/stdc++.h>
#include <cmath>
#include <cstddef>

int main(){
	std::size_t rows = 4;
	std::size_t cols = 4;
	std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));
	for(const auto& row : matrix){
		for(const auto& element : row){
			std::cout<<element<<" ";
		}
		std::cout<<"\n";
	}

	//dynamic resizing of matrices
	std::vector<std::vector<int>> matrix2;
	matrix2.resize(rows); //first resize the rows
	for(auto& row : matrix2){
		row.resize(cols); //now resize the coloumn located at each row
	}
	std::cout<<"\n";
	matrix2[2][2] = 69; 
	for(const auto& row : matrix2){
		for(const auto& element : row){
			std::cout<<element<<" ";
		}
		std::cout<<"\n";
	}
}
