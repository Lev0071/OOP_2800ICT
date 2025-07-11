#include <iostream>
#include <memory>
using namespace std;

// your code here
class Timer {
private:
    shared_ptr<int> year;
    shared_ptr<int> month;
    shared_ptr<int> day;

public:
    
    Timer() { // Default constructor
        year = make_shared<int>(0);
        month = make_shared<int>(0);
        day = make_shared<int>(0);
    }

    
    Timer(int y, int m, int d) { // Parameterized constructor
        year = make_shared<int>(y);
        month = make_shared<int>(m);
        day = make_shared<int>(d);
    }

    
    Timer(const Timer& other) { // Deep copy constructor
        year = make_shared<int>(*other.year);
        month = make_shared<int>(*other.month);
        day = make_shared<int>(*other.day);
    }

    void operator()(int y, int m, int d) {
        *year = y;
        *month = m;
        *day = d;
    }

    Timer& operator=(const Timer& other) { // Deep copy assignment operator
        if (this != &other) {
            year = make_shared<int>(*other.year);
            month = make_shared<int>(*other.month);
            day = make_shared<int>(*other.day);
        }
        return *this;
    }

    
    friend ostream& operator<<(std::ostream& os, const Timer& t){ // Friend function for output
        os << *t.year << ":" << *t.month << ":" << *t.day;
        return os;
    }
};

// ostream& operator<<(ostream& os, const Timer& t) {
//     os << *t.year << ":" << *t.month << ":" << *t.day;
//     return os;
// }

// DO NOT MODIFY ANYTHING IN THE MAIN FUNCTION.
int main()
{
    // test the Timer class

    Timer t1(1,1,1), t2;
    std::cout << "Timer t1: " << t1 << std::endl; // Expected output: Timer t1: 1:1:1
    std::cout << "Timer t2: " << t2 << std::endl; // Expected output: Timer t2: 0:0:0

    Timer t3 = t1;
    t3(3, 3, 3);
    std::cout << "Timer t1: " << t1 << std::endl; // Expected output: Timer t1: 1:1:1
    std::cout << "Timer t3: " << t3 << std::endl; // Expected output: Timer t3: 3:3:3

    t3 = t2;
    t3(4,4,4);
    std::cout << "Timer t2: " << t2 << std::endl; // Expected output: Timer t2: 0:0:0
    std::cout << "Timer t3: " << t3 << std::endl; // Expected output: Timer t3: 4:4:4

    return 0;
}
// g++ -std=c++17 q1.cpp -o q1