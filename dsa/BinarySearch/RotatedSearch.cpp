#include<iostream>
#include<vector>
#include<cmath>
#include<optional>

std::optional<int> rpos(const std::vector<int>& arr, int element){
        int low = 0;
        int high = arr.size() - 1;
        int mid;
	int start;
	int end;
        while(low<=high){
                mid = ((low+high)/2);
                if(mid > 0 && arr[mid - 1] == arr[mid]){ //To handle the repeating number case
                        mid = mid - 1;
                }
                if(mid > 0 && ((arr[mid-1] > arr[mid]) || (low == high && high == mid))){
                        start = mid;
			break;
                }
                else if( std::abs(arr[low] - arr[mid])  <  std::abs(arr[high] - arr[mid])  &&  (arr[low-1] < arr[low]) ){
                        low = mid + 1;
                } else {
                        high = mid - 1;
                }
        }

	if(start == 0){
		end = arr.size() - 1;
	} else {
		end = start - 1;
	}


	low = 0;
	high = arr.size() - 1;

	if(element >= arr[start] && element<=arr[high] ) {
		low = start;
	} else {
		high = start - 1;
	}

	while(low <= high){
		mid = (low+high)/2;
		if(element == arr[mid]){
			return mid;
		}
		if(arr[mid] > element)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return std::nullopt;


}

int main(){
        std::vector<int> arr = {1,2,3,4,5};
	int element;
	std::cout<<"\nEnter an element: ";
	std::cin>>element;
	std::optional<int> result = rpos(arr,element);
	if(result){
		std::cout<<"\nFound at: "<<*result;
	} else {
		std::cout<<"\nElement Not found!";
	}
        return 0;
}
