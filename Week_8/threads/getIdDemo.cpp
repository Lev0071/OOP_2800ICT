// getIdDemo.cpp
#include <iostream>
#include <thread>

using namespace std;

void printThreadID() {
    cout << "Thread ID: " << this_thread::get_id() << endl;
}

int main() {
    thread t1(printThreadID);
    cout << endl;
    thread t2(printThreadID);

    t1.join();
    t2.join();

    cout << "Main thread ID: " << this_thread::get_id() << endl;
    return 0;
}
// Compile: g++ -std=c++14 getIdDemo.cpp -o getIdDemo
// Run:     ./getIdDemo
