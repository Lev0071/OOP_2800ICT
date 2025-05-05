#include <iostream>
#include <memory>
using namespace std;

class DataHolder {
private:
    shared_ptr<int> data;
public:
    DataHolder(int value) {
        data = make_shared<int>(value);
    }

    void show() const {
        cout << "Value: " << *data << ", Use count: " << data.use_count() << endl;
    }

    shared_ptr<int> getData() const {
        return data;
    }
};

int main() {
    DataHolder d1(10); // d1 is the first owner

    auto ref = d1.getData(); // ref is the second owner (shared_ptr copy of d1's data)

    DataHolder d2(20);
    d2 = d1; // d2 now also holds a copy of the same shared_ptr (shallow copy) i.e: d2.data now points to the same memory as d1.data

    // 1. What does d2 = d1 do?
    //    ✔️ d2 now holds the same shared_ptr as d1 — both point to the same memory.
    //    So d1, d2, and ref all share the same int in memory.

    // 2. How many shared owners?
    //    ✔️ Three: d1, d2, and ref. Each holds a shared_ptr to the same int object.

    // Modify value through one pointer
    *ref = 99;

    d1.show(); // should show 99
    d2.show(); // should also show 99

    // 3. What does *ref = 99 do?
    //    ✔️ It changes the shared value in memory to 99.
    //    Since all three shared_ptrs point to the same memory,
    //    d1 and d2 both reflect this change.

    return 0;
}

// g++ -std=c++2b activity2.cpp -o spA2