#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> numbers = {42, 7, 18, 99, 23, 5, 66};
    vector<char> letters = {'d', 'a', 'z', 'm', 'b', 'e'};

    cout << "Numbers" << endl;
    for (auto& num : numbers){
        cout << num <<", ";
    }
    cout << endl;

    auto minIt = min_element(numbers.begin(),numbers.end());
    auto maxIt = max_element(numbers.begin(),numbers.end());

    cout << "Minimium element in vector: " << *minIt << endl;
    cout << "Maximum element in vector: " << *maxIt << endl;

    // for both min and max elements
    auto result = minmax_element(numbers.begin(),numbers.end());
    cout << "Min and Max elements are: " << *result.first << " and " << *result.second << endl;

    cout << "Letters" << endl;
    for (auto& num : letters){
        cout << num <<", ";
    }
    cout << endl;

    auto min_It = min_element(letters.begin(),letters.end());
    auto max_It = max_element(letters.begin(),letters.end());

    cout << "Minimium element in vector: " << *min_It << endl;
    cout << "Maximum element in vector: " << *max_It << endl;

    // for both min and max elements
    auto resultt = minmax_element(letters.begin(),letters.end());
    cout << "Min and Max elements are: " << *resultt.first << " and " << *resultt.second << endl;

    return 0;
}