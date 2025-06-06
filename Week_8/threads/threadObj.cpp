// threadObj.cpp
#include <iostream>
#include <thread>

// Function to be executed by the thread
void say_hello(const std::string& name) {
    std::cout << "Hello, " << name << " from thread!\n";
}

int main() {
    // Create a thread and run say_hello with argument "Yasin"
    std::thread threadObj(say_hello, "Yasin");

    // Wait for the thread to finish
    threadObj.join();

    std::cout << "Back in main thread.\n";

    return 0;
}
// g++ -std=c++14  threadObj.cpp -o threadObj