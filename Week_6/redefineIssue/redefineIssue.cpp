#include <iostream>
using namespace std;

class BaseClass {
public:
    void X() {
        Y();  // Calls Y from within BaseClass
    }

    void Y() {
        cout << "BaseClass::Y()" << endl;
    }
};

class DerivedClass : public BaseClass {
public:
    void Y() {
        cout << "DerivedClass::Y()" << endl;
    }
};

int main() {
    DerivedClass D;
    D.X();  // Which Y() is called?
    return 0;
}
// g++ -std=c++2b redefineIssue.cpp -o mOverrideIssue