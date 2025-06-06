// handling_multipleException2.cpp
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std; // <- Added for simplicity

void processInput(const string &input){
    int number = 0;
    try {
        number = stoi(input);
        if (number < 0 || number > 100){
            throw out_of_range("Number is out of acceptable range (0-100)");
        }
        cout << "Processed number: " << number << endl;
    }
    catch (const invalid_argument &e){
        cout << "invalid_argument";
        cerr << "Exception: Invalid argument. Please enter a valid number." << endl;
    }
    catch (const out_of_range &e){
        cout << "out_of_range";
        cerr << "Exception: " << e.what() << endl;
    }
    catch (const exception &e){
        cout << "exception";
        cerr << "Unexpected error: " << e.what() << endl;
    }
}

int main(){
    string userInput = "105"; // Can change to "abc", "50", etc. to test different cases
    cout << "Enter a number>";
    cin >> userInput;
    processInput(userInput);
    return 0;
}
// g++ -std=c++2b handling_multipleException2.cpp -o mException2

// "abc"

// "3.14"

// "!"

// "ten"

// "" (empty string)


// https://devdocs.io/cpp/header/stdexcept