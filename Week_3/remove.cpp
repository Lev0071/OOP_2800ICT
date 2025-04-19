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

// Use remove together with erase
int main(){
    vector<int> vec = {15, 5, 7, 9, 10, 13, 9, 4, 2, 8, 9, 11, 9, 9, 9, 12, 14};
    cout << "Initail vector" << endl;
    myPrint(vec);
    auto newEnd = remove(vec.begin(),vec.end(),9);
    cout << "After calling: remove(vec.begin(),vec.end(),9)" << endl;
    myPrint(vec);
    vec.erase(newEnd,vec.end()); // Erase the "removed elements"
    cout << "After calling: vec.erase(newEnd,vec.end())" << endl;
    myPrint(vec);

    
    return 0;
}