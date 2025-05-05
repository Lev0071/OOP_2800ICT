#include <iostream>
#include <memory>
using namespace std;

class Mover {
private:
    shared_ptr<int> ptr;
public:
    // Normal constructor
    Mover(int val) : ptr(make_shared<int>(val)) {}

    // Move constructor: accepts an rvalue reference and transfers ownership
    Mover(Mover&& other) noexcept {
        ptr = move(other.ptr); // Transfers ownership of shared_ptr from 'other' to 'this'
        cout << "Move constructor called.\n";
    }

    // Move assignment operator: handles ownership transfer during assignment
    Mover& operator=(Mover&& other) noexcept {
        if (this != &other) {
            ptr = move(other.ptr); // Transfers ownership again
            cout << "Move assignment called.\n";
        }
        return *this;
    }

    void set(int val) { *ptr = val; }

    int get() const { return ptr ? *ptr : -1; }

    void show() const {
        cout << "Value: ";
        if (ptr)
            cout << *ptr;
        else
            cout << "[null]";
        cout << ", use_count: " << ptr.use_count() << endl;
    }
};

int main() {

    Mover a(42);               // a owns a shared_ptr<int> with value 42
    cout << "a created using 'Mover a(42);'\n";
    cout << "a: "; a.show();   // prints: null

    Mover b = move(a);         // move constructor is called here
    // === Q1 ===
    // What does move(a) do to a and b?
    // ✅ Answer:
    // 'a' transfers ownership of its shared_ptr to 'b'. After the move,
    // a.ptr becomes null (i.e., reset internally by shared_ptr), and b.ptr now owns the int.
    // This is a clean ownership transfer — no undefined behavior or garbage memory.

    cout << "a moved to b using 'Mover b = move(a);'\n";
    cout << "After move constructor:\n";
    cout << "a: "; a.show();   // prints: null
    cout << "b: "; b.show();   // prints: 42, use_count: 1

    Mover c(99);               // c owns its own shared_ptr<int> with value 99

    c = move(b);               // move assignment operator is called here
    // === Q2 ===
    // After c = move(b);, who owns the memory?
    // ✅ Answer:
    // 'c' now owns the memory that was previously held by 'b'.
    // 'b' is left in a null state. So by the end, only 'c' owns the original int (42),
    // and both 'a' and 'b' have been reset to null.

    cout << "\nAfter move assignment:\n";
    cout << "a: "; a.show();   // prints: null
    cout << "b: "; b.show();   // prints: null
    cout << "c: "; c.show();   // prints: 42, use_count: 1

    // === Q3 ===
    // What does this prove about how shared_ptr behaves when moved?
    // ✅ Answer:
    // It proves that shared_ptr supports clean ownership transfer through move semantics.
    // When moved, the internal pointer is safely transferred, and the source shared_ptr is reset to null.
    // This allows safe and efficient resource management without duplication or leaks.
}
