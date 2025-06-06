// string2.cpp
#include <iostream>
#include <string>
#include <limits>
#include <sstream>
using namespace std;

int main() {
    int value;
    string message;

    cout << "Enter text: ";
    cin >> value;

    cin >> message;
    // cin.clear();
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "The text entered is: " << message << endl;

    cout << "Enter a number: ";
    cin >> value;
    // cin.clear();
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "The number entered is: " << value << endl;

    cout << "Enter text: ";
    getline(cin, message);

    cout << "The text entered is: " << message << endl;
    cout << int(message.length()) << endl;

    return 0;
}
//g++ -std=c++2b string2.cpp -o string2