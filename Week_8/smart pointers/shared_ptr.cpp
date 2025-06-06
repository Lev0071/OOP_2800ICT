// shared_ptr.cpp
#include <iostream>
#include <memory>

using namespace std;

class MyClass {
public:
    MyClass() { cout << "Constructor\n"; }
    ~MyClass() { cout << "Destructor\n"; }
};

int main() {
    shared_ptr<MyClass> p1 = make_shared<MyClass>();
    cout << "p1 use count: " << p1.use_count() << endl;

    shared_ptr<MyClass> p2 = p1;
    cout << "p2 use count: " << p2.use_count() << endl;

    {
        shared_ptr<MyClass> p3 = p2;
        cout << "p3 use count: " << p3.use_count() << endl;
    }

    cout << "After p3 scope, p1 use count: " << p1.use_count() << endl;

    p2.reset();
    cout << "After p2.reset(), p1 use count: " << p1.use_count() << endl;

    p1.reset();
    cout << "After p1.reset(), p1 use count: " << p1.use_count() << endl;

    cout << "End of main\n";
    return 0;
}
// g++ -std=c++11 -o shared_ptr shared_ptr.cpp
// ./shared_ptr