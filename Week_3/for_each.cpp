#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;

void doubleNumber(int &n)
{
    n *= 2;
}

int main(){
    vector<int> numbers = {1,2,3,4,5,6,7,8,9,10};

    // use foreach to apply doubleNumber to each elemnt in the vector
    for_each(numbers.begin(),numbers.end(),doubleNumber);

    // Print the modified number
    for(int number:numbers){
        cout << number << " ";
    }
    cout << endl;

    return 0;
}