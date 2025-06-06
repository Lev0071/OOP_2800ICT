#include <iostream>
#include <memory>
using namespace std;

class Person {
private:
    string m_name;
    weak_ptr<Person> m_partner;  // initially created empty

public:
    Person(const string& name) : m_name(name) {
        cout << m_name << " created\n";
    }

    ~Person() {
        cout << m_name << " destroyed\n";
    }

    friend bool partnerUp(shared_ptr<Person>& p1, shared_ptr<Person>& p2) {
        if (!p1 || !p2)
            return false;

        p1->m_partner = p2;
        p2->m_partner = p1;

        cout << p1->m_name << " is now partnered with " << p2->m_name << '\n';
        return true;
    }
};
void testSharedPtrCouple()
{
    auto lucy = make_shared<Person>("Lucy");
    auto ricky = make_shared<Person>("Ricky");

    partnerUp(lucy, ricky);  // Mutual ownership

    cout << "Lucy use_count: " << lucy.use_count() << endl;   // Likely 2
    cout << "Ricky use_count: " << ricky.use_count() << endl; // Likely 2
}

int main()
{
    testSharedPtrCouple();
    cout << "End of main\n";
    return 0;
}
// g++ -std=c++14  shared_ptr_weak_circular.cpp -o shared_ptr_weak_circular

// ✅ If two objects mutually reference each other with a **weak_ptr**, here’s what happens:
// 📌 Key properties of std::weak_ptr:

//     It does not increase the reference count.

//     It’s a non-owning observer.

//     It becomes useful only if there's at least one std::shared_ptr keeping the object alive.


// ✅ Why this works:

//     The only owners are a and b — both are shared_ptrs in main.

//     a->bptr and b->aptr are weak_ptrs — they don’t increase use_count().

//     So when a and b go out of scope, both objects are properly destroyed — no circular dependency.

// ==============================================
// #include <iostream>
// #include <memory>
// using namespace std;

// class B; // Forward declaration

// class A {
// public:
//     weak_ptr<B> bptr;  // weak reference to B
//     ~A() { cout << "A destroyed\n"; }
// };

// class B {
// public:
//     weak_ptr<A> aptr;  // weak reference to A
//     ~B() { cout << "B destroyed\n"; }
// };

// int main() {
//     shared_ptr<A> a = make_shared<A>();
//     shared_ptr<B> b = make_shared<B>();

//     a->bptr = b;  // no ownership added
//     b->aptr = a;  // no ownership added

//     cout << "a use_count: " << a.use_count() << endl;  // 1
//     cout << "b use_count: " << b.use_count() << endl;  // 1
// }