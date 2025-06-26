#include <iostream>
using namespace std;

int number = 10; // Global Variable

class MyClass{
    public:
        static int number; // Class variable with the same name

        void showNumbers(){
            int number = 30; // Local variable
            cout << "Local number: " << number << endl;           // Prints 30
            cout << "Class number: " << MyClass::number << endl;  // Prints 20
            cout << "Global number: " << ::number << endl;        // Prints 10
        }
};

// Define the class variable outside the class
int MyClass::number = 20;

int main(){
    MyClass obj;
    obj.showNumbers();
    return 0;
}

// g++ -std=c++2b scope.cpp -o scope