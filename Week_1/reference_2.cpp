#include <iostream>
using namespace std;

template <typename X>
void square(X &input) {
    input = input * input;
}
void flipCase(char &c) {
    if (isupper(c)) {
        c = tolower(c);  // Convert to lowercase
    } else if (islower(c)) {
        c = toupper(c);  // Convert to uppercase
    }
}

int main(){

    char letter{'a'};
    int num_1{0};
    int num_2{0};
    double num_3{0};

    cout << "Enter an integer: ";
    cin >> num_1;
    cout << "Enter another integer: ";
    cin >> num_2;
    cout << "Enter an double: ";
    cin >> num_3;
    cout << "Enter an Character: ";
    cin >> letter;

    int &w = num_1;
    int &x = num_2;
    double &y = num_3;
    char &z = letter;

    cout << "Value of num_1: " << num_1 << endl;
    cout << "Value of num_1 reference: " << w << endl;
    square(num_1);
    cout << "Value of num_1 after function call: " << num_1 << endl;

    cout << "Value of num_2: " << num_2 << endl; 
    cout << "Value of num_2 reference: " << x << endl;
    square(num_2);
    cout << "Value of num_2 after function call: " << num_2 << endl; 

    cout << "Value of num_3: " << num_3 << endl; 
    cout << "Value of num_3 reference: " << y << endl;
    square(num_3);
    cout << "Value of num_3 after function call: " << num_3 << endl; 

    cout << "Value of letter: " << letter << endl; 
    cout << "Value of letter reference: " << z << endl;
    flipCase(letter);
    cout << "Value of letter after function call: " << letter << endl; 
}