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
bool is_Even(int &n)
{
    return n%2 == 0;
}
// Use remove_if together with erase
int main(){
    vector<int> vec = {15, 5, 7, 9, 10, 13, 9, 4, 2, 8, 9, 11, 9, 9, 9, 12, 14};
    cout << "Initail vector" << endl;
    myPrint(vec);
    auto newEnd = remove_if(vec.begin(),vec.end(),is_Even);
    vec.erase(newEnd,vec.end()); // Erase the "removed elements"
    cout << "After calling: remove(vec.begin(),vec.end(),is_Even)" << endl;
    cout << "After calling: vec.erase(newEnd,vec.end())" << endl;
    myPrint(vec);

    
    return 0;
}