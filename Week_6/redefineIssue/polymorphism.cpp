#include <iostream>
using namespace std;

class BaseClass {
public:
    void X() {
        Y();  // will call DerivedClass::Y() if overridden
    }

    virtual void Y() { // now virtual
        cout << "BaseClass::Y()" << endl;
    }
};

class DerivedClass : public BaseClass {
public:
    void Y() override {
        cout << "DerivedClass::Y()" << endl;
    }
};

int main() {
    DerivedClass d;
    cout << "Using Polymorphism" << endl;
    d.X();  // Which Y() is called?

    BaseClass b;
    BaseClass &b1 = d;
    DerivedClass &b2 = d;

    cout << "Reference class to base class (using BaseClass pointer object)" << endl;
    b1.Y();

    cout << "Reference class to base class (using DerivedClass pointer object)" << endl;
    b2.Y();
    return 0;
}
// g++ -std=c++2b polymorphism.cpp -o mOpolymorphism