#include <iostream>
using namespace std;

class Base {
    public:
        virtual void walk() final { cout << "Base walk\n"; } // ✅ virtual + final
    };
    
    class Derived : public Base {
        // void walk() override { cout << "Derived walk\n"; } ❌ Error: walk is final in Base
    };
    
    class Base2 {
    public:
        void walk() { cout << "Base2 walk\n"; }  // not virtual
    };
    
    class Derived2 : public Base2 {
    public:
        void walk() { cout << "Derived2 walk\n"; }  // this HIDES Base2::walk(), not override
    };
    