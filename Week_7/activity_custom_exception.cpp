#include <iostream>
#include <string>
#include <exception>
using namespace std;

/*
🛠️ ACTIVITY: Create a custom exception class called `NegativeAgeException`
   - Inherit from std::exception
   - Constructor should take a string message
   - Override what() method to return that message
*/

// TODO: Define class NegativeAgeException here
class NegativeAgeException:public exception{
    private:
        string message;
    public:
        NegativeAgeException(const string &msg):message(msg){}

        virtual const char* what() const _NOEXCEPT override { //virtual const char* what() const override noexcept {
            return message.c_str();
        }
};

void checkAge(int age) {
    if (age < 0) {
        throw NegativeAgeException("Cannot backwards in time from when you are born!");
    }
    cout << "You entered a valid age: " << age << endl;
}

int main() {
    int inputAge;
    cout << "Enter your age: ";
    cin >> inputAge;

    try {
        checkAge(inputAge);
    }
    catch (const NegativeAgeException &e) {
        cerr << "Custom Exception caught: " << e.what() << endl;
    }
    catch (const exception& e) {
        cerr << "Standard Exception: " << e.what() << endl;
    }

    return 0;
}

// g++ -std=c++2b activity_custom_exception.cpp -o ace


// Question:
// #include <iostream>
// #include <string>
// #include <exception>
// using namespace std;

// /*
// 🛠️ ACTIVITY: Create a custom exception class called `NegativeAgeException`
//    - Inherit from std::exception
//    - Constructor should take a string message
//    - Override what() method to return that message
// */

// // TODO: Define class NegativeAgeException here

// void checkAge(int age) {
//     if (age < 0) {
//         // TODO: Replace this line with: throw NegativeAgeException("Negative age not allowed.");
//         throw std::runtime_error("Negative age not allowed"); // temporary placeholder
//     }
//     cout << "You entered a valid age: " << age << endl;
// }

// int main() {
//     int inputAge;
//     cout << "Enter your age: ";
//     cin >> inputAge;

//     try {
//         checkAge(inputAge);
//     }
//     catch (/* TODO: Catch your custom NegativeAgeException by const reference */) {
//         // TODO: Print a message like: "Custom Exception Caught: " followed by the error using what()
//     }
//     catch (const exception& e) {
//         cerr << "Standard Exception: " << e.what() << endl;
//     }

//     return 0;
// }
