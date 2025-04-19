#include <iostream>
#include <vector>
#include <array>
#include <algorithm> // for std::for_each
using namespace std;

void myPrint(int n){
    cout << n << " ";
}

// Custom comparator function (Descending Order)
bool customCompare(int a,int b){
    return a>b;
}

int main(){
    array<int,16> s{15,5,7,10,13,4,2,8,11,6,1,9,12,0,3,14};
    cout << "sorted with the default operator <: std::less\n";
    sort(s.begin(),s.end());
    for_each(s.begin(),s.end(),myPrint);cout << endl;
    cout << "sorted with the standard library compare function: std::greater\n";
    sort(s.begin(),s.end(),std::greater<int>());
    for_each(s.begin(),s.end(),myPrint);cout << endl;
    s = {15,5,7,10,13,4,2,8,11,6,1,9,12,0,3,14};
    cout << "Reset the array with default initial sort state\n";
    for_each(s.begin(),s.end(),myPrint);cout << endl;
    cout << "sorted with the custom function that emulates the standard library compare function: std::greater\n";
    sort(s.begin(),s.end(),std::greater<int>());
    for_each(s.begin(),s.end(),myPrint);cout << endl;
}