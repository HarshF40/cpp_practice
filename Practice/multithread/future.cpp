#include<iostream>
#include<future>
#include<chrono>
#include<thread>

bool loader() {
  int size_loaded = 0;
  while(size_loaded<100) {
    std::cout<<"\nLoading...";
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    size_loaded++;
  }
  return true;
}

int main() {
  std::future<bool> process = std::async(std::launch::async,loader);
  std::future_status status;
  while(true){
    std::cout<<"\nMain Thread...";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    status = process.wait_for(std::chrono::milliseconds(1));
    if(status == std::future_status::ready) {
      std::cout<<"\nData is ready";
      break;
    }
  }
  std::cout<<"\nProgram Complete";
  return 0;
}
