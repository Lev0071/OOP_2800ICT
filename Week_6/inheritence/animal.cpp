#include <iostream>
using namespace std;

// Base class 
class Animal{
    public:
        void eat(){
            cout << "This animal eats food." << endl;
        }
    
    };

// Derived class (inherits from Animal)
class Bird:public Animal{
    public:
        void fly(){
            cout << "This bird can fly." << endl;
        }
};

// Further derived class (inherits from Bird)
class Parrot:public Bird{
    public:
        void speak(){
            cout << "The parrot can mimic sounds." << endl;
        }
};

int main(){
    Parrot myParrot;
    
    myParrot.eat();     // From Animal
    myParrot.fly();     // From Bird
    myParrot.speak();   // From Parrot

    return 0;
}
// Do overde for eat that bounds a food member

// g++ -std=c++2b animal.cpp -o inheritence