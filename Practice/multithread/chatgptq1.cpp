//Input some number from user and no of threads to calculate the sum of it.
//Divide the array in eqaul parts and then calculate the partial sum with
//multithreading and display the final output.

#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
#include<functional>

std::mutex gLock;

void partial_sum(unsigned int& ival,const std::vector<int>& arr,int& sum,unsigned int thread_num){

  int temp;

  {
  std::lock_guard<std::mutex> lock_guard(gLock);
  temp = ival;
  ival += arr.size()/thread_num;
  }

  int local_sum = 0;
  for(int i=temp ; i<ival ; i++){
    local_sum+=arr[i];
  }

  {
    std::lock_guard<std::mutex> lock_guard(gLock);
    sum+=local_sum;
  }

}

int main(){
  std::vector<std::thread> threads;
  std::vector<int> arr;
  unsigned int num;
  int pb_value; //push back value
  unsigned int index_val = 0;
  int sum = 0;
  unsigned int thread_num;

  std::cout<<"\nEnter No. of Numbers: ";
  std::cin>>num;

  std::cout<<"\nEnter "<<num<<" number(s): ";
  for(int i=0;i<num;i++){
    std::cin>>pb_value;
    arr.push_back(pb_value);
  }

  do{
  std::cout<<"\nEnter Number Of Threads to Create: ";
  std::cin>>thread_num;
  }while(arr.size()%thread_num != 0 || arr.size()<thread_num || thread_num ==  0);

  for(int i=0;i<thread_num;i++){
    threads.push_back(std::thread(partial_sum,std::ref(index_val),std::cref(arr),std::ref(sum),thread_num));
  }
  
  for(int i=0;i<threads.size();i++){
    threads[i].join();
  }

  std::cout<<"\nThe sum is : "<<sum<<std::endl;

  return 0;
}
