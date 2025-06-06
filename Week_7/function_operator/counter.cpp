#include <iostream>
using namespace std;

class Counter {
private:
    int count;

public:
    Counter() : count(0) {}

    int operator()(int step = 1) {
        count += step;
        return count;
    }
};

int main() {
    Counter c;

    cout << "Called: " << c() << " times.\n";
    cout << "Called: " << c() << " times.\n";
    cout << "Called: " << c(5) << " times.\n";

    return 0;
}

//g++ -std=c++2b counter.cpp -o counter