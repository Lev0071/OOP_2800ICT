// thread3.cpp
#include <iostream>
#include <thread>
using namespace std;

void foo(string flag, int n) {
    for (int i = 0; i < n; i++) {
        cout << flag;
    }
}

int main() {
    thread first(foo, "thread 1\n", 5);
    thread second(foo, "thread 2\n", 5);

    // Pauses until first finishes.
    // This operation must complete before it can be destroyed.
    first.join();

    // Pauses until second finishes.
    // The program can only continue after join is complete.
    second.join();

    cout << "Main thread\n";
    return 0;
}
