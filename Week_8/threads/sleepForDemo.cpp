// sleepForDemo.cpp
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void task() {
    cout << "Sleeping for 2 seconds...\n";
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Woke up!\n";
}

int main() {
    thread t(task);
    t.join();
    return 0;
}
// Compile: g++ -std=c++14 sleepForDemo.cpp -o sleepForDemo
// Run:     ./sleepForDemo
