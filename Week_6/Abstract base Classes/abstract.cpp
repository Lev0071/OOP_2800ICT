// In C++, just one pure virtual function is enough to make the entire class abstract.
#include <iostream>
using namespace std;

// Abstract Base Class
class Animal{
    public:
        // Pure virtual function
        virtual void speak() = 0;        // Pure virtual → must override

        void breathe(){                 // Concrete → optional override
            cout << "Animal is breathing..." << endl;
        }
};

// Derived class must implement speak()
class Dog:public Animal{
    public:
        void speak() override{
            cout << "Dog says: Woof!" << endl;
        }
};

// // Another derived class
class Cat:public Animal{
    public:
        void speak() override{
            cout << "Cat says: Meow!" << endl;
        }
};

int main(){
    // Animal a; // ❌ Error: cannot instantiate abstract class

    Dog d;
    Cat c;

    d.breathe(); // Inherited concrete method
    d.speak(); // Dog's speak

    c.breathe(); // Inherited concrete method
    c.speak(); // Cat's speak

    // Polymorphic use
    Animal* a = &d;
    a->speak(); // Calls Dog::speak()

    return 0;
}


// g++ -std=c++2b abstract.cpp -o abstract