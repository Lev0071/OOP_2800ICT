#include <iostream>
#include <memory>
using namespace std;

int main() {
    shared_ptr<int> a = make_shared<int>(42);
    cout << "Use count: " << a.use_count() << endl;
    shared_ptr<int> b = a;

    cout << "Value: " << *a << endl;
    cout << "Use count: " << a.use_count() << endl;
    b.reset();
    cout << "After 'b.reset();' \n";
    cout << "Use count: 'a.use_count()': "<< a.use_count() << endl;
    cout << "Use count: 'b.use_count()': "<< b.use_count() << endl;
    b = a;
    cout << "After 'b = a;': "<< endl;
    cout << "Use count: 'b.use_count()': "<< b.use_count() << endl;
    return 0;
}
    // 1. What value does *a print?
    // ✔️ *a prints 42 — it owns a dynamically allocated int with value 42.

    // 2. What is use_count() after assigning b = a?
    // ✔️ use_count() becomes 2 when b = a — both a and b share ownership.

    // 3. What happens after calling b.reset()?
    // ⚠️ After b.reset():
    //     b.use_count() → 0 (b no longer points to the memory)
    //     a.use_count() → 1 (a is now the sole owner again)

// #include <iostream>
// #include <memory>
// using namespace std;

// int main() {
//     shared_ptr<int> a = make_shared<int>(42);
//     shared_ptr<int> b = a;

//     cout << "Value: " << *a << endl;
//     cout << "Use count: " << a.use_count() << endl;
//     return 0;
// }


// g++ -std=c++2b activity1.cpp -o spA1
