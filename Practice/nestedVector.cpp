#include<vector>
#include<iostream>

int main(){

    std::vector<std::vector<int>> arr;
    int row;
    int colm;

    std::cout<<"\nEnter the number of rows: ";
    std::cin>>row;
    std::cout<<"\nEnter the number of columns: ";
    std::cin>>colm;

    //the main main part of the vector 2d matrix is the first column... everthing we do is by referring to that only***

    //number of columns = number of elements in a row
    //number of rows = number of elements in a column
    
    std::cout<<"\nEnter The Elements: ";
    for(int i = 0; i < row; i++){
        std::vector<int> row; //creating an empty row to then push to the column in the main vector.
        row.resize(colm); //resizes (creates) the space for the colm number of elements in a row
        for(int j = 0; j < colm; j++){
            std::cin>>row[j];
        }
        arr.push_back(row);
    }

//const because teh matrix should be read only beacuse we are referring the row
//auto because it will deduce the type automatically 
//&(reference) because its more efficient to refer than to copy the whole vector row
    for(const auto& row : arr){ //row will have each row from the 2d matrix (arr) each time it iterates
        for(const auto& elements : row){ //elements will have each element from the row we took from the main 2d matrix (arr) 
            std::cout<<elements<<" ";
        }
        std::cout<<"\n";
    }

    return 0;
}