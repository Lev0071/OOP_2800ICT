// 🧠 Exercise 1: Basic Try-Catch

// Write a program that:

//     Takes a number from the user.

//     If it’s negative, throw an exception.

//     If not, print its square root.

// #include <iostream>
// #include <stdexcept>
// using namespace std;

// int main(){
//     double x;
//     cout << "Enter a number  (Enter an exclamation mark (!) to quit: )>";
//     cin >> x;
    
//     try {
//         if(x<0){
//             throw runtime_error("Negative number entered");
//         }
//         cout << "Squar of input: " << x*x << endl;
//     }
//     catch (const runtime_error &e) {
//         cout << "Exception caught: " << e.what() << endl;
//     }
// }

#include <iostream>
#include <stdexcept>
#include <cmath> // for sqrt
using namespace std;

// Function that throws if input is negative
double safeSqrt(double x) {
    if (x < 0) {
        throw runtime_error("Cannot compute square root of a negative number!");
    }
    return sqrt(x);
}

int main() {
    double num;
    cout << "Enter a number to find its square root: ";
    cin >> num;

    try {
        double result = safeSqrt(num);
        cout << "Square root: " << result << endl;
    }
    catch (const runtime_error &e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    cout << "Program continues..." << endl;
    return 0;
}
// g++ -std=c++2b basic_try_catch.cpp -o basicTC