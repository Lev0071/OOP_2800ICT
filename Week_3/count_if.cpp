#include <iostream>
#include <vector>
//#include <algorithm>
using namespace std;

bool is_Odd(int &n)
{
    return n%2 != 0;
}

int main(){
    vector<int> numbers = {1,2,3,4,5,6,7,8,9,10,11};

    // use foreach to apply doubleNumber to each elemnt in the vector
    int oddCount = count_if(numbers.begin(),numbers.end(),is_Odd);

    // Print the count of odd number
    cout << "There are " << oddCount << " odd numbers in the vector";
    cout << endl;
    
    int evenCount = count_if(numbers.begin(),numbers.end(),[](int n){
        return n % 2 == 0;
    });
    
    // Print the count of even number
    cout << "There are " << evenCount << " even numbers in the vector";
    cout << endl;

    return 0;
}