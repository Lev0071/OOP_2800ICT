// 🧠 Exercise 2: Catch All Exceptions

// Modify your code to catch std::exception instead of just runtime_error, and test it with different throws like:

// throw logic_error("Bad logic!");

#include <iostream>
#include <stdexcept>
using namespace std;

// A function that may thro an exception
double divide(int a,int b);

int main(){
    int x,y;
    cout << "Enter two numners  (Enter two exclamation marks (!) to quit: )>";
    cin >> x >> y;

    try{
        double result = divide(x,y); // Call the function
        cout << "Result: " << result << endl;
    }
    catch(const exception &e){
        cout << "Exception caught: " << e.what() << endl;
        //cerr << "Exception caught: " << e.what() << endl;
    }

    cout << "Program continues..." << endl;
    return 0;
}

double divide(int a,int b){
    if(b==0){
        throw logic_error("Denominator should not be zero.");
    }
    return static_cast<double>(a)/b;
}

// 🧪 Suggested Follow-up Tests

// Try replacing the throw line in divide() with one of the following, one at a time:

// throw invalid_argument("Invalid argument passed.");

// throw out_of_range("Value is out of expected range.");

// You’ll see that your generic catch(const exception &e) still works fine.

// g++ -std=c++2b basic_try_catch_2.cpp -o basicTC2
