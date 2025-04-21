#include <iostream>
using namespace std;

// This class can be inherited from
class Base{
    public:
        virtual void speak(){
            cout << "Base speaking" << endl;
        }

        virtual void walk() final{ // ❌ Can't be overridden further This is virtual, so it can be inherited, and called polymorphically.But the final keyword means it cannot be overridden in derived classes.
            cout << "Base walking" << endl;
        }
};

// This class can be inherited from, and overrides speak()
class Derived: public Base{
    public:
        void speak() override{
            cout << "Derived speaking" << endl;
        }

        // void walk() override { } ❌ Error: walk() is final in Base
};

// This class cannot be inherited from
class FinalClass final{
    public:
        void hello(){
            cout << "Hello form FinalClass" << endl;
        }
};

// class SubFinal : public FinalClass {}; ❌ Error: cannot inherit from a class marked final

int main(){
    Derived d;
    d.speak(); // Output: Derived speaking
    d.walk(); // Output: Base walking

    FinalClass f;
    f.hello(); // Output: Hello from FinalClass
    return 0;
}

// g++ -std=c++2b final1.cpp -o final1