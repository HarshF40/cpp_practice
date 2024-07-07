#include <iostream>
#include <functional> //to use function pointer.

using funcptr = std::function<bool(int)>;

bool filtercallback(int num) {
    return num % 2 == 0; 
} //call back function which filters all the elements in the array.

void filter(const int* arr_ptr, int* result, int size, char ch, funcptr callb, int& result_size) {
    int k = 0;
    for (int i = 0; i < size; i++) {
        if (callb(arr_ptr[i]) && ch == 'a') {
            result[k++] = arr_ptr[i];
        } else if (!callb(arr_ptr[i]) && ch == 'd') {
            result[k++] = arr_ptr[i];
        }
    }
    result_size = k;
} // This functions takes the filter choice and filters the elements accordingly and then stores them in the new array which was passed by address.

int main() {
    int n;
    std::cout << "\nEnter number of elements: ";
    std::cin >> n;

    // Allocate memory dynamically in heap
    int* mainarr = new int[n];
    int* finalarr = new int[n];

    std::cout << std::endl << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> mainarr[i];
    }

    char ch;
    std::cout << "\nEnter 'a' for even or 'd' for odd: ";
    std::cin >> ch;

    int result_size = 0;
    filter(mainarr, finalarr, n, ch, filtercallback, result_size);

    std::cout << "\nFiltered elements: ";
    for (int i = 0; i < result_size; i++) {
        std::cout << finalarr[i] << " ";
    }
    std::cout << std::endl;

    // Free the allocated memory in heap
    delete[] mainarr;
    delete[] finalarr;

    return 0;
}