#include <iostream>
using namespace std;

int main(){

    int sz{};
    cout << "Enter the array size: ";
    cin >> sz;

    int numbers[sz];

    //Get values for the array
    for(int &val:numbers){
        cout << "Enter an integer value: ";
        cin >> val;
    }

    // Diplay the values in the array 
    cout << "Here are the values you entered:\n";
    for(int val:numbers){
        cout << val << endl;
    }
    return 0;
}