#include <iostream>
using namespace std;

class Animal {
public:
    string name = "Animal";

    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal {
public:
    string breed = "Labrador";

    void speak() override {
        cout << "Dog barks" << endl;
    }
};

int main() {
    Dog d;
    d.name = "Rex";
    d.breed = "Golden Retriever";

    Animal a = d;  // ⚠️ Object slicing occurs here

    cout << "a.name: " << a.name << endl;
    cout << "❗ Calls Animal::speak() — not Dog::speak()" << endl;
    a.speak();     // ❗ Calls Animal::speak() — not Dog::speak()
    
    // cout << a.breed; // ❌ Error: Animal has no member 'breed'

    cout << "Attempt to call Dog class's speak method and breed member" << endl;
    Animal &b = d;

    cout << "b.name: " << b.name << endl;
    //cout << "❗ Calls Animal::speak() — not Dog::speak()" << endl;
    b.speak();     // ❗ Calls Animal::speak() — not Dog::speak()
    cout << "b.breed cannot print,b is Animal reference, breed is a Dog memember " << endl;
    //cout << b.breed; // ❌ Error: Animal has no member 'breed'
}
// g++ -std=c++2b objSlicing.cpp -o slicing