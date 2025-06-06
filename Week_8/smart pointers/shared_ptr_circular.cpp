// shared_ptr1.cpp
#include <iostream>
#include <memory>  // for shared_ptr
#include <string>

using namespace std;

class Person {
private:
    string m_name;
    shared_ptr<Person> m_partner;  // initially created empty

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
// g++ -std=c++14  shared_ptr_circular.cpp -o shared_ptr_circular