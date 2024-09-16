#include<iostream>
#include<thread>
#include<chrono>
#include<vector>
#include<mutex>
#include<functional>

std::mutex g_lock;

void process1(std::vector<int>& arr,int& i){
  if(g_lock.try_lock()){
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<"\nProcessing 1";
    arr.push_back(1);
    i++;
    g_lock.unlock();
  }
  return;
}

void process2(std::vector<int>& arr,int& i){
 if(g_lock.try_lock()){
   std::this_thread::sleep_for(std::chrono::seconds(2));
   std::cout<<"\nProcessing 2";
   arr.push_back(2);
    i++;
    g_lock.unlock();
  }
  return;

}

void process3(std::vector<int>& arr,int& i){
 if(g_lock.try_lock()){
   std::this_thread::sleep_for(std::chrono::seconds(2));
   std::cout<<"\nProcessing 3";
    arr.push_back(3);
    i++;
    g_lock.unlock();
  }
  return;

}

int main(){

  std::vector<int> data;

  int i=0;
  while(i<10){

    std::cout<<"\nMain Thread";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::thread thread1(process1,std::ref(data),std::ref(i));
    std::thread thread2(process2,std::ref(data),std::ref(i));
    std::thread thread3(process3,std::ref(data),std::ref(i));

    thread1.join();
    thread2.join();
    thread3.join();

    std::this_thread::sleep_for(std::chrono::seconds(1));

  }

  std::cout<<"\n";
  for(int i=0;i<data.size();i++){
    std::cout<<data[i]<<' ';
  }

  return 0;
}
