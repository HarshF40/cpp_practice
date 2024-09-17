#include<iostream>
#include<thread>
#include<random>
#include<chrono>
#include<mutex>

std::mutex dlock,slock;

std::random_device rd{};
std::seed_seq ss{rd(),rd(),rd(),rd()};
std::mt19937 mt{ss};
std::uniform_int_distribution downTime{1,10};
std::uniform_int_distribution prosTims{1,3};

void download_file(int file_id) {
  std::unique_lock<std::mutex> lock(dlock);
    int dtime = downTime(mt);  
    std::cout<<"Downloading File "<<file_id<<"... : ("<<dtime<<" seconds)"<<std::endl;
  lock.unlock();

    //std::cout<<"\n";
    std::this_thread::sleep_for(std::chrono::seconds(dtime));

      
  std::unique_lock<std::mutex> lock2(slock);
    std::cout<<"File "<<file_id<<" downloaded successfully!"<<std::endl;
  lock2.unlock();
  //std::cout<<"\n";
}


int main(){

  std::thread file1(download_file,1);
  std::thread file2(download_file,2);
  std::thread file3(download_file,3);

  file1.join();
  file2.join();
  file3.join();

  return 0;
}
