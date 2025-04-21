#include <iostream>
using namespace std;

// Base class 1
class Base1{
    public:
        void greet(){
            cout << "Hello from Base1" << endl;
        }
};

// Base class 2
class Base2 {
    public:
        void farewell() {
            cout << "Goodbye from Base2" << endl;
        }
};

// Derived class inherits from both Base1 and Base2
class Derived:public Base1,public Base2{
    public:
        void displayDerived(){
            cout << "Derived display" << endl;
        }
};

int main(){
    Derived obj;

    obj.greet();            // Inherited from Base1
    obj.farewell();         // inherited from Base2
    obj.displayDerived();   // Defined in Derived

    return 0;
};

// g++ -std=c++2b multipleInheritence.cpp -o multipleInheritence