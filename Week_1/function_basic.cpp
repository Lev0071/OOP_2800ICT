#include <iostream>
using namespace std;

// to multiply two numbers
double multiply(double a,double b){
    return a * b;
}

int main(){
    int x{},y{};
    cout << "Please enter two numbers: ";
    cin >> x >> y;
    int result = multiply(x,y);
    cout << "Product of " << x << " and " << y << " = " << result << endl;
    return 0;
}