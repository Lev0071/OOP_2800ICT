#include <iostream>
#include <vector>
using namespace std;

// Method to print numbers
void printNumbers(const vector<int>& numbers) {
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    vector<int> numbers = {10,20,30};

    // Add elements
    numbers.push_back(40);printNumbers(numbers);
    numbers.pop_back();printNumbers(numbers);

    // Access elemnts
    cout << numbers[1] << " ";
    cout << numbers.at(2) << " ";

    // Iterate using range-based loop
    for (int num: numbers){
        cout << num << " ";
    }
    cout << endl;

    numbers.reserve(100);  // Preallocate memory
    numbers.resize(5);printNumbers(numbers);

    return 0;
}