// thread_mutex.cpp
#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;  // create a mutex
int counter = 0;

void safeIncrement() {
    std::lock_guard<std::mutex> lock(mtx);  // locks and unlocks automatically // 🔒 LOCKED here
    ++counter;
    std::cout << std::this_thread::get_id() << ": " << counter << '\n';
}// 🔓 UNLOCKED here (when `lock` goes out of scope and is destroyed)

int main() {
    std::thread t1(safeIncrement);
    std::thread t2(safeIncrement);

    t1.join();
    t2.join();

    std::cout << "Counter: " << counter << std::endl;
}

// Compile: g++ -std=c++14 thread_mutex.cpp -o thread_mutex -pthread
// Run:     ./thread_mutex
