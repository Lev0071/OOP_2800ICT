#include <iostream>
using namespace std;

class Base{
    private:
        int baseValue;
    protected:
        int x_p;
    public:
        Base(int x = 0,int x_p=0); // Constructor Declaration
        void display(); // Memeber function declaration
};

class Derived:public Base{
    private:
        int derivedValue;
    public:
        Derived(int x = 0,int y=0); // Constructor Declaration
        void display(); // Memeber function declaration
};

Base::Base(int x,int x_p): baseValue(x),x_p(x_p){
    cout << "Base constructor" << endl;
};

Derived::Derived(int x,int y):Base(x),derivedValue(y){
    // cout<<x_p;
    // cout<<Base::x_p;
    cout << "Derived constructor" << endl;
}; 

void Base::display(){
    cout << "Base value: " << baseValue << endl;
} 

void Derived::display(){
    Base::display(); // Call base class display function
    cout << "Derived value: " << derivedValue << endl;
} 


int main(){
    Derived derivedObj(10,20);
    derivedObj.display(); // Output: Base value: 10, Derivd value:20

    return 0;
}
// g++ -std=c++2b pass_argument_base_constructor.cpp -o derivedMain