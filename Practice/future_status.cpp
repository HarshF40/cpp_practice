#include<iostream>
#include<future>
#include<chrono>
#include<thread>
int longTask() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 42; }
int main() {
    std::future<int> result = std::async(std::launch::async,longTask);
    auto start = std::chrono::steady_clock::now();
    auto timeout = start + std::chrono::seconds(3);
    std::future_status status = result.wait_until(timeout);
    if(status == std::future_status::ready)
    std::cout<<"Task Completed "<<result.get();
    else if(status == std::future_status::timeout)
    std::cout<<"Task is still runinng";
    else if(status == std::future_status::deferred)
    std::cout<<"Task is deferred";
    return 0; }
