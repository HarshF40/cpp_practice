#include<iostream>
#include<thread>
#include<random>
#include<chrono>
#include<mutex>

#define green "\033[32m"
#define yellow "\x1b[33m"
#define cyan "\033[36m"
#define reset "\x1b[0m"

std::mutex dlock,slock;

std::random_device rd{};
std::seed_seq ss{rd(),rd(),rd(),rd()};
std::mt19937 mt{ss};
std::uniform_int_distribution downTime{1,10};
std::uniform_int_distribution prosTime{1,5};

void process_file(int file_id){
  std::unique_lock<std::mutex> lock(dlock);
    int ptime = prosTime(mt);
    std::cout<<cyan<<"Processing File "<<file_id<<"... : ("<<ptime<<" seconds)"<<reset<<std::endl;
  lock.unlock();

    std::this_thread::sleep_for(std::chrono::seconds(ptime));

 std::unique_lock<std::mutex> lock2(slock);
    std::cout<<green<<"File "<<file_id<<" processed successfully!"<<reset<<std::endl;
  lock2.unlock();
}

void download_file(int file_id) {
  std::unique_lock<std::mutex> lock(dlock);
    int dtime = downTime(mt);  
    std::cout<<yellow<<"Downloading File "<<file_id<<"... : ("<<dtime<<" seconds)"<<reset<<std::endl;
  lock.unlock();

    std::this_thread::sleep_for(std::chrono::seconds(dtime));

      
  std::unique_lock<std::mutex> lock2(slock);
    std::cout<<green<<"File "<<file_id<<" downloaded successfully!"<<reset<<std::endl;
  lock2.unlock();

  process_file(file_id);
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
