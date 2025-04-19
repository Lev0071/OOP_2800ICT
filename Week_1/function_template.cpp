#include <iostream>
using namespace std;

// Overloaded functions for addition

template <typename X>
X add(X a, X b) {
    return a + b;
}

template <typename X,typename Z>
auto add(X a, Z b) {
    return a + b;
}

// int add(int a, int b) {
//     return a + b;
// }

// float add(float a, float b) {
//     return a + b;
// }

// double add(double a, double b) {
//     return a + b;
// }

int main() {
    // Testing overloaded functions
    cout << "Int addition: " << add(3, 5) << endl;       // Calls int version
    cout << "Float addition: " << add(3.5f, 2.2f) << endl;  // Calls float version
    cout << "Float addition: " << add(3.5f, 9) << endl;  // Calls float version
    cout << "Float addition: " << add(7, 3.5f) << endl;  // Calls float version
    cout << "Double addition: " << add(4.7, 1.3) << endl;  // Calls double version
    
    return 0;
}