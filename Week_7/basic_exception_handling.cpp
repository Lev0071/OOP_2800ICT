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
    catch(const runtime_error &e){
        cout << "Exception caught: " << e.what() << endl;
    }

    cout << "Program continues..." << endl;
    return;
}

double divide(int a,int b){
    if(b==0){
        throw runtime_error("Division by zero!");
    }
    return static_cast<double>(a)/b;
}

