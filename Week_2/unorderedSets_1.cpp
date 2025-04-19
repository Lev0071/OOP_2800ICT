#include <iostream>
#include <vector>
#include <unordered_set> // NOTE: using unordered_set
using namespace std;

// Method to print numbers
template<typename T>
void printNumbers(const unordered_set<T>& elements, string command = "Not provided") {
    if (command != "Not provided") {
        cout << "After Command: " << command << endl;
    }
    cout << "Unordered Set Contents" << endl;
    for (T elems : elements) {
        cout << elems << " ";
    }
    cout << endl;
}

int main() {
    unordered_set<string> names = {"Joe", "Karen", "Lisa", "Jackie"};
    printNumbers(names);

    unordered_set<string>::iterator iter;

    // Find "Karen"
    iter = names.find("Karen");

    // Display the results
    if (iter != names.end()) {
        cout << *iter << " was found.\n";
    } else {
        cout << "Karen was NOT found.\n";
    }

    return 0;
}
