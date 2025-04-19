#include <iostream>
#include <vector>
#include <array>
#include <algorithm> // for std::find
using namespace std;

void myPrint(int n){
    cout << n << " ";
}

int main(){
    int find_value{};
    vector<int> vec = {15,5,7,10,13,4,2,8,11,6,1,9,12,0,3,14};
    //array<int,16> vec{15,5,7,10,13,4,2,8,11,6,1,9,12,0,3,14};
    cout << "sorted with the default operator <: std::less\n";
    sort(vec.begin(),vec.end());
    for_each(vec.begin(),vec.end(),myPrint);cout << endl;
    cout << "Pick a value to perform a search on: " << endl;
    cin >> find_value;

    auto it = find(vec.begin(),vec.end(),find_value);

    if(it != vec.end()){
        cout << "Found value " << *it << " at position " << (it-vec.begin()) << endl;
    }
    else{
        cout << "Value not found." << endl;
    }
    return 0;
}