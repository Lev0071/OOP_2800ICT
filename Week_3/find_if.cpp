#include <iostream>
#include <vector>
#include <array>
#include <algorithm> // for std::find
using namespace std;

void myPrint(int n){
    cout << n << " ";
}

bool is_Even(int &n)
{
    return n%2 == 0;
}

bool is_Odd(int &n)
{
    return n%2 != 0;
}


int main(){
    char find_value{};
    vector<int> vec = {15,5,7,10,13,4,2,8,11,9,12,14};
    //array<int,16> vec{15,5,7,10,13,4,2,8,11,6,1,9,12,0,3,14};
    cout << "sorted with the default operator <: std::less\n";
    sort(vec.begin(),vec.end());
    for_each(vec.begin(),vec.end(),myPrint);cout << endl;
    cout << "Find the first even or odd value ? (e/o): " << endl;
    cin >> find_value;
    int state = 1;

    while(state==1){
        if(find_value == 'e'){
        //auto it = find_if(vec.begin(),vec.end(),is_Even);
        auto it = find_if(vec.begin(),vec.end(),[](int n){return n%2 == 0;});
        if(it != vec.end()){
            cout << "Found even value " << *it << " at position " << (it-vec.begin()) << endl;
        }else{
            cout << "No even values found " << endl;
        }
    }else if(find_value == 'o'){
        //auto it = find_if(vec.begin(),vec.end(),is_Odd);
        auto it = find_if(vec.begin(),vec.end(),[](int n){return n%2 != 0;});
        if(it != vec.end()){
            cout << "Found odd value " << *it << " at position " << (it-vec.begin()) << endl;
        }else{
            cout << "No odd values found " << endl;
        }
    }
    cout << "Continue ? (y/n): " << endl;
    cin >> find_value;
    if(find_value == 'y'){
        int state = 1;
        cout << "Find the first even or odd value ? (e/o): " << endl;
        cin >> find_value;
    }else{
        state = 0;
    }
    
    }
    
    return 0;
}