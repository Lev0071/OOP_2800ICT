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
        if (!year)   year = make_shared<int>(0);
        if (!month)  month = make_shared<int>(0);
        if (!day)    day = make_shared<int>(0);
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

    Timer(Timer&& other) noexcept { // Move constructor
        year = move(other.year);
        month = move(other.month);
        day = move(other.day);
    }

        
    Timer operator+(const Timer& other) const { // Addition operator with wraparound
        int total_days = *day + *other.day;
        int total_months = *month + *other.month;
        int total_years = *year + *other.year;

        
        if (total_days >= 48) { // Days overflow
            total_days -= 48;
            total_months += 1;
        }

        
        if (total_months >= 36) { // Months overflow
            total_months -= 36;
            total_years += 1;
        }

        
        if (total_years >= 24) { // Years wraparound
            total_years -= 24;
        }

        return Timer(total_years, total_months, total_days);
    }

    
    Timer& operator=(Timer&& other) noexcept { // Move assignment operator
        if (this != &other) {
            year = move(other.year);
            month = move(other.month);
            day = move(other.day);
        }
        return *this;
    }

    
    friend ostream& operator<<(ostream& os, const Timer& t) { // Friend function for output
        os << (t.year ? *t.year : 0) << ":"
        << (t.month ? *t.month : 0) << ":"
        << (t.day ? *t.day : 0);
        return os;
    }
};

// DO NOT MODIFY ANYTHING IN THE MAIN FUNCTION.
int main()
{
    // TESTING THE Timer CLASS

    Timer t1, t2, t3, t4, t5(6,6,6);
    t3(10, 20, 30);
    t4(13, 16, 19);
    Timer t6 = move(t5);
    t5(5, 5, 5);

    t6 = t3 + t4;
    std::cout << "Timer t3: " << t3 << std::endl; // Expected output: Timer t3: 10:20:30
    std::cout << "Timer t4: " << t4 << std::endl; // Expected output: Timer t4: 13:16:19
    std::cout << "Timer t5: " << t5 << std::endl; // Expected output: Timer t5: 5:5:5
    std::cout << "Timer t6: " << t6 << std::endl; // Expected output: Timer t6: 0:1:1

    return 0;
}


// g++ -std=c++17 q2.cpp -o q2