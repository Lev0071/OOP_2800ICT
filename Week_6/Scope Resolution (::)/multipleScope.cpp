#include <iostream>
using namespace std;

// Base class 1
class Base1 {
public:
    void display() {
        std::cout << "Base1 display" << std::endl;
    }
};

// Base class 2
class Base2 {
public:
    void display() {
        std::cout << "Base2 display" << std::endl;
    }
};

// Derived class inherits from both Base1 and Base2
class Derived : public Base1, public Base2 {
public:
    // You can use scope resolution to specify which display() function to call
    void displayDerived() {
        Base1::display();  // Call display() from Base1
        Base2::display();  // Call display() from Base2
    }
};

int main() {
    Derived obj;
    obj.displayDerived(); // Call displayDerived() function of Derived class
    return 0;
}
// g++ -std=c++2b multipleScope.cpp -o multipleScope