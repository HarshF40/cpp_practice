//decltype(arg) --> returns the data type of the
//object passed

#include<iostream>
#include<vector>

template <typename T>
void printRev(const std::vector<T>& vec) {
    for(typename std::remove_reference_t<decltype(vec)>::size_type index{0}; index>=0; index--){
        std::cout<<vec[(index)]<<" ";
    }
}

int main(){
    std::vector<int> arr{1,2,3,4,5,6,7,8,9};
    printRev<int>(arr);
    return 0;
}