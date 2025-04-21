#include <iostream>
using namespace std;

// Base class 1
class Base1 {
public:
    void display1() {
        std::cout << "Base1 display" << std::endl;
    }
};

// Base class 2
class Base2 {
public:
    void display2() {
        std::cout << "Base2 display" << std::endl;
    }
};

// Derived class inherits from both Base1 and Base2
class Derived : public Base1, public Base2 {
public:
    // You can use scope resolution to specify which display() function to call
    void displayDerived() {
        std::cout << "Derived display" << std::endl;
    }
};

int main() {
    Derived obj;
    obj.display1();         // Accessing member function from Base1
    obj.display2();         // Accessing member function from Base2
    obj.displayDerived();   // Accessing member function from Derived
    return 0;
}
// g++ -std=c++2b multipleScope.cpp -o multipleScope