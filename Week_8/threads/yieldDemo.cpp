// yieldDemo.cpp
#include <iostream>
#include <thread>

using namespace std;

void task() {
    for (int i = 0; i < 5; ++i) {
        cout << "Task iteration " << i << endl;
        this_thread::yield(); // Suggest giving CPU time to other threads
    }
}

int main() {
    thread t(task);
    t.join();
    return 0;
}
// Compile: g++ -std=c++14 yieldDemo.cpp -o yieldDemo
// Run:     ./yieldDemo
