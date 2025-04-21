#include <iostream>
using namespace std;

class Base {
    public:
        void show() {
            cout << "Base show" << endl;
        }

        void show(int x) {
            cout << "Base show(int): " << x << endl;
        }
    };
    
    class Derived : public Base {
    public:
        void show() {
            cout << "Derived show" << endl;
        }
    };
    
int main(){
    Base b;
    Derived d;

    cout << "Overloading" << endl;
    b.show();
    d.show();
    cout << "Overridding" << endl;
    b.show(10);
    // d.show(20);  // Error
}
    // Method_Overriding 
    // g++ -std=c++2b Method_Overriding .cpp -o mOveride