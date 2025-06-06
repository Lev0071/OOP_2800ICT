// push_emplace.cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string n, int a) : name(n), age(a) {
        cout << "Constructor called for " << name << endl;
    }

    Person(const Person& other) {
        name = other.name;
        age = other.age;
        cout << "Copy constructor called for " << name << endl;
    }

    Person(Person&& other) noexcept {
        name = move(other.name);
        age = other.age;
        cout << "Move constructor called for " << name << endl;
    }
};

// Helper function to print vector contents
void printPeople(const vector<Person>& people) {
    cout << "Current vector contents:\n";
    if (people.empty()) {
        cout << "[empty]\n";
    } else {
        for (const auto& person : people) {
            cout << "- " << person.name << ", " << person.age << endl;
        }
    }
    cout << "---------------------------\n";
}

int main() {
    vector<Person> people;

    cout << "\nInitial state:\n";
    printPeople(people);

    cout << "\n--- push_back with copy ---\n";
    Person p("Alice", 30);
    people.push_back(p); // Calls copy constructor
    printPeople(people);

    cout << "\n--- push_back with move ---\n";
    Person m("Micheal", 33);
    people.push_back(move(m)); // Calls move constructor
    printPeople(people);

    cout << "\n--- emplace_back ---\n";
    people.emplace_back("Bob", 25); // Constructs in-place, no copy/move
    printPeople(people);

    return 0;
}

// Compile: g++ -std=c++14 push_emplace.cpp -o push_emplace
// Run:     ./push_emplace
