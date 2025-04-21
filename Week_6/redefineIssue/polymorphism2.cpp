#include <iostream>
using namespace std;

class Base {
    public:
        virtual void speak() {
            cout << "Base speaking" << endl;
        }
    };
    
    class Derived : public Base {
    public:
        void speak() override {
            cout << "Derived speaking" << endl;
        }
    };
    
    int main() {
        Derived d;
        Base& ref = d;     // ← using & enables polymorphism
        ref.speak();       // ← calls Derived::speak() thanks to virtual + override
    }
    
// g++ -std=c++2b polymorphism2.cpp -o polymorphism2