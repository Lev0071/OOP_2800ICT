// cin_vs_getline_activity.cpp
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main() {
    string str1,str2,str3,str4,message;
    int age,value{1};
    string favoriteQuote;

    // STEP 1: Basic cin
    cout << "Enter a string of four words: ";
    cin >> str1; // Will stop at space
    cin >> str2; // Will stop at space
    cin >> str3; // Will stop at space
    cin >> str4; // Will stop at space/newline
    cout << "first word: [" << str1 << "]" << endl;
    cout << "second word: [" << str2 << "]" << endl;
    cout << "third word: [" << str3 << "]" << endl;
    cout << "fourth word: [" << str4 << "]" << endl;

    cout << "Enter a string of two words: ";
    
    // "123 word dee"
    cin >> value; // value = 123
        
    cin >> message;
    
    cout << value << endl;
    cout << message << endl;

    return 0;
}

//g++ -std=c++2b cin_test.cpp -o cin_test