#include<iostream>
#include<thread>
#include<mutex>
#include<vector>

static int shared_value = 0;
std::mutex glock;

//function used by each individual thread.
void shared_value_increment(){
  std::lock_guard<std::mutex> lg(glock);
    std::cout<<"\nHello From: "<<std::this_thread::get_id();
    shared_value++;
}

int main(){

  std::vector<std::thread> threads;
  
  for(int i=0;i<1000;i++){
    threads.push_back(std::thread(shared_value_increment));
  }

  for(int i=0;i<threads.size();i++){
    threads[i].join();
  }

  std::cout<<"\nShared Value: "<<shared_value;

  return 0;
}
