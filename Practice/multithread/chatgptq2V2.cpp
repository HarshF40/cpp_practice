//better version than the other one
//ouputs the correct output

#include<iostream>
#include<thread>
#include<mutex>
#include<random>
#include<vector>

std::mutex mtx;
static int consumer_index = 0;
static int producer_index = 0;
static int buffer_elements = 0;
static int produced_item = 0;
static int consumed_item = 0;
static bool status = true;
std::vector<int> buffer(5);

bool isBufferOcc() {
    return buffer_elements > 0;
}

void produce() {

    std::random_device rd{};
    std::seed_seq ss{rd(),rd(),rd(),rd()};
    std::mt19937 mt{ss};
    std::uniform_int_distribution<int> item{1,100};
    std::uniform_int_distribution<int> slp{150,400};

    while(status) {
        while(buffer_elements<5 && producer_index<5) {
            std::this_thread::sleep_for(std::chrono::milliseconds(slp(mt)));
            std::unique_lock<std::mutex> lock(mtx);
            buffer[producer_index] = item(mt);
            buffer_elements++;
            lock.unlock();
            std::cout<<"\nProduced: "<<buffer[producer_index];
            produced_item++;
            producer_index++;
        }
        producer_index = 0;
    }
}

void consume() {

    std::random_device rd{};
    std::seed_seq ss{rd(),rd(),rd(),rd()};
    std::mt19937 mt{ss};
    std::uniform_int_distribution<int> slp{100,300};

    while(status) {
        while(isBufferOcc() && consumer_index<5) {
            std::this_thread::sleep_for(std::chrono::milliseconds(slp(mt)));
            std::unique_lock<std::mutex> lock(mtx);
            if(buffer[consumer_index] == 0) {
                lock.unlock();
                break;
            }
            std::cout<<"\nConsumed: "<<buffer[consumer_index];
            consumed_item++;
            buffer[consumer_index] = 0;
            buffer_elements--;
            lock.unlock();
            consumer_index++;
            if(consumer_index<4) {
                if(buffer[consumer_index+1]==0) {
                    consumer_index=0;
                    break;
                }
            } 
        }
        consumer_index=0;
    }
}

int main() {

    std::thread consumer(consume);
    std::thread producer(produce);

    std::this_thread::sleep_for(std::chrono::seconds(5));
    status = false;

    producer.join();
    consumer.join();

    if(produced_item!=consumed_item) {
        for(int i=0; i<buffer.size(); i++) {
            if(buffer[i]!=0) {
                std::cout<<"\nConsumed: "<<buffer[i];
                buffer[i]=0;
                consumed_item++;
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }
        }
    }

    return 0;
}
