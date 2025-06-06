// weak_to_share.cpp
#include <iostream>
#include <memory>     // for shared_ptr and weak_ptr
#include <string>
using namespace std;

class Person {
private:
    string m_name;
    weak_ptr<Person> m_partner;  // note: This is now a weak_ptr

public:
    Person(const string &name) : m_name(name) {
        cout << m_name << " created\n";
    }

    ~Person() {
        cout << m_name << " destroyed\n";
    }

    friend bool partnerUp(shared_ptr<Person> &p1, shared_ptr<Person> &p2) {
        if (!p1 || !p2)
            return false;

        p1->m_partner = p2;
        p2->m_partner = p1;

        cout << p1->m_name << " is now partnered with " << p2->m_name << '\n';
        return true;
    }

    // use lock() to convert weak_ptr to shared_ptr
    const shared_ptr<Person> getPartner() const {
        return m_partner.lock();
    }

    const string &getName() const {
        return m_name;
    }
};

int main() {
    auto lucy{make_shared<Person>("Lucy")};
    auto ricky{make_shared<Person>("Ricky")};

    partnerUp(lucy, ricky);

    auto partner = ricky->getPartner();  // get shared_ptr to Ricky's partner
    cout << ricky->getName() << "'s partner is: " << partner->getName() << '\n';

    return 0;
}
// g++ -std=c++14  weak_to_share.cpp -o weak_to_share