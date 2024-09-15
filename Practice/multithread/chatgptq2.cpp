//works but it waits for other thread complete its work then it does it own... 
//which was not intended because its produces output in
//produce - consume - produce - consume manner
//and what i wanted was it to be random and it should execute independently
//here this doesnt work because i used condition_variable
//in the other version i didnt use condition variables.... 
//so it works as i wanted

#include<iostream>
#include<vector>
#include<thread>
#include<mutex>
#include<random>
#include<chrono>
#include<functional>
#include<condition_variable>  

static bool val = false;
std::mutex mtx;
std::condition_variable cv;
static int index_ptr = -1;

bool isBufferFull(const std::vector<int>& Buffer){
  for(int i=0;i<5;i++){
    if(Buffer[i]!=0)
      return true;
  }
  return false;
}

void produce(std::vector<int>& buffer){
  std::random_device rd;
  std::seed_seq ss{rd(),rd(),rd(),rd()};
  std::mt19937 mt{ss};
  std::uniform_int_distribution dist{1,100};

  while(!val){
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock,[&buffer]{return (index_ptr<5) ? true : false;});
    if(index_ptr<5){
    index_ptr++;
    buffer[index_ptr] = dist(mt);
    std::cout<<"\nProduced: "<< buffer[index_ptr];
    }
    lock.unlock();
    cv.notify_all();
  }

}

void consume(std::vector<int>& buffer){
  while(!val){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock,[&buffer]{return (index_ptr >= 0) ? true : false;});
    std::cout<<"\nConsumed: "<<buffer[index_ptr];
    buffer[index_ptr] = 0;
    index_ptr--;
    lock.unlock();
    cv.notify_all();
  }
}

int main(){

  std::vector<int> buffer(5);

  std::thread producer(produce,std::ref(buffer));
  std::thread consumer(consume,std::ref(buffer));


  std::this_thread::sleep_for(std::chrono::seconds(5));
  val = true;

  cv.notify_all();
  producer.join();
  consumer.join();

  std::cout<<"\nProgram Complete!"<<std::endl;

  return 0;
}
