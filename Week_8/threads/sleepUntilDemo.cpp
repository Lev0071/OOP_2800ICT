// sleepUntilDemo.cpp
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    auto wakeTime = chrono::steady_clock::now() + chrono::seconds(3);
    cout << "Waiting until 3 seconds have passed...\n";
    this_thread::sleep_until(wakeTime);
    cout << "Reached the target time!\n";
    return 0;
}
// Compile: g++ -std=c++14 sleepUntilDemo.cpp -o sleepUntilDemo
// Run:     ./sleepUntilDemo
