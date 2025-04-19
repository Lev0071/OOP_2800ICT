#include <iostream>
#include <vector>
#include <array>
#include <algorithm> // for std::find
using namespace std;

void myPrint(int n){
    cout << n << " ";
}

void myPrint(vector<int> v){
    for(int val:v){
        cout << val << " ";
    }
    cout << endl;
}

// Use unique together with erase
int main(){
    vector<int> vec = {1, 5, 3, 7, 5, 2, 8, 5, 9, 4, 6, 5, 10};

    // Replace all instances of 5s with 99
    cout << "Original vector" << endl;
    myPrint(vec);
    replace(vec.begin(),vec.end(),5,99);
    myPrint(vec);
    return 0;
}