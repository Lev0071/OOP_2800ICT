// thread5.cpp
#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <sstream>  // <= include this

void task(int num) {
    std::ostringstream oss;
    oss << "thread id: " << std::this_thread::get_id()
        << " | task number: " << num << "\n";
    std::string str = oss.str();
    std::cout << str;
}

int main() {
    std::vector<std::thread> threads;

    for (int i = 0; i < 5; ++i) {
        std::thread t(task, i);
        threads.push_back(std::move(t)); // must move, thread is non-copyable
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}

// Compile: g++ -std=c++14 thread5.cpp -o thread5 -pthread
// Run:     ./thread5
