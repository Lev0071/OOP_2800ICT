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

// Use unique together with erase
int main(){
    vector<int> vec = {1, 5, 3, 7, 5, 2, 8, 5, 9, 4, 6, 5, 10};
    vector<int> result(vec.size());

    // Replace all even numbers with 0
    cout << "Original vec vector" << endl;
    myPrint(vec);
    cout << "Original result vector" << endl;
    myPrint(result);
    // Copy vec to result replacing all '5's with '99's
    replace_copy_if(vec.begin(),vec.end(),result.begin(),is_Even,0);
    cout << "After copying from result vec to result vector, replacing even numbers with zeros" << endl;
    cout << "vec vector" << endl;
    myPrint(vec);
    cout << "result vector" << endl;
    myPrint(result);
    return 0;
}