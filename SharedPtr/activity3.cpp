#include <iostream>
#include <memory>
using namespace std;

class DeepCopy {
private:
    shared_ptr<int> ptr;
public:
    DeepCopy(int val) : ptr(make_shared<int>(val)) {}

    // Deep copy constructor
    DeepCopy(const DeepCopy& other) {
        ptr = make_shared<int>(*other.ptr); // This creates a NEW int in memory with the same value as other.ptr
    }

    void set(int val) { *ptr = val; }
    int get() const { return *ptr; }
};

int main() {
    DeepCopy a(5);                      // a.ptr points to int with value 5
    DeepCopy b = a; // deep DeepCopy    // b.ptr is a deep copy — (invokes DeepCopy(const DeepCopy& other), points to a new int with value 5
    b.set(99);

    cout << "a: " << a.get() << endl;
    cout << "b: " << b.get() << endl;

    /*
    === Question 1 ===
    What will a.get() and b.get() output — and why?

    === Answer 1 ===
    a.get() will return 5
    b.get() will return 99
    Because b was deep-copied from a, it points to its own memory.
    Changing b does not affect a.

    === Question 2 ===
    If you change this line: b.set(99); to: a.set(12);
    What will a.get() and b.get() output — and why?

    === Answer 2 ===
    a.get() would return 12
    b.get() would return 5
    Again, each object manages its own memory independently.

    === Question 3 ===
    What does this behavior tell you about how memory is handled between a and b?
    Specifically, what does it prove about how the DeepCopy constructor works?

    === Answer 3 ===
    This behavior proves that the DeepCopy constructor:
        DeepCopy(const DeepCopy& other) {
            ptr = make_shared<int>(*other.ptr);
        }
    performs a **deep copy**. It allocates new memory for each object.
    Therefore, a and b do NOT share the same int, and changing one doesn't affect the other.
    */
}

// g++ -std=c++2b activity3.cpp -o spA3
