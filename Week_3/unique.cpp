// iterator unique(iterator1, iterator2)
// Removing adjacent duplicates? → No sort needed
// Removing all duplicates?     → Yes, sort first

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
    vector<int> vec = 
       {1, 
        2, 2, 
        3, 3, 3, 
        4, 4, 4, 4, 
        5, 5, 5, 5, 5, 
        6, 6, 6, 6, 6, 6, 
        7, 7, 7, 7, 7, 7, 7, 
        8, 8, 8, 8, 8, 8, 8, 8, 
        9, 9, 9, 9, 9, 9, 9, 9, 9, 
       10,10,10,10,10,10,10,10,10,10,
       11,11,11,11,11,11,11,11,11,11,11};
    cout << "Initail vector" << endl;
    myPrint(vec);
    auto newEnd = unique(vec.begin(),vec.end());
    vec.erase(newEnd,vec.end()); // Erase the "removed elements"
    cout << "After calling: unique(vec.begin(),vec.end())" << endl;
    cout << "After calling: vec.erase(newEnd,vec.end())" << endl;
    myPrint(vec);

    
    return 0;
}