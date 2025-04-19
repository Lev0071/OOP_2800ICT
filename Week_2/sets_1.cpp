#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Method to print numbers
template<typename T>
void printNumbers(const set<T>& elements,string command="Not provided") {
    if (command !=  "Not provided"){
        cout << "After Command: " << command << endl;
    }
    cout << "Set Contents" << endl;
    for (T elems : elements) {
        cout << elems << " ";
    }
    cout << endl;
}

int main(){
    set<int> numbers = {1,1,2,2,3,4,5,5,5};printNumbers(numbers);
    set<string> names = {"Joe","Karen","Lisa","Jackie"};printNumbers(names);

    return 0;
} 