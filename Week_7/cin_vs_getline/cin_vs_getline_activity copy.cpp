// cin_vs_getline_activity.cpp
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    string name;
    int age;
    string favoriteQuote;

    // STEP 1: Basic cin
    cout << "Enter your name (one word only): ";
    cin >> name; // Will stop at space
    cout << "Captured name using cin: [" << name << "]" << endl;

    // STEP 2: Buffer demonstration
    cout << "Enter your age: ";
    cin >> age;
    cout << "Captured age using cin: " << age << endl;

    // STEP 3: Try getline without clearing buffer
    cout << "Enter your favorite quote (may include spaces): ";
    getline(cin, favoriteQuote); // This may fail due to leftover '\n' in buffer
    cout << "Captured quote using getline (without clearing): [" << favoriteQuote << "]" << endl;

    // STEP 4: Clear the buffer and retry
    cin.clear(); // clear error flags (if any)
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush leftover newline
    cout << "Now enter your favorite quote again (with buffer cleared): ";
    getline(cin, favoriteQuote); // Now it should work correctly
    cout << "Captured quote using getline (after clearing): [" << favoriteQuote << "]" << endl;

    return 0;
}

//g++ -std=c++2b cin_vs_getline_activity.cpp -o cin_vs_getline