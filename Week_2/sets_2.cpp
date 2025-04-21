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
    set<string> names = {"Joe","Karen","Lisa","Jackie"};printNumbers(names);

    set<string>::iterator iter;

    // Find "Karen"
    iter = names.find("Karen");

    // Display the results
    if (iter != names.end()){
        cout << *iter << " was found.\n";
    }else{
        cout << "Karen was NOT found.\n";
    }

    return 0;
} 