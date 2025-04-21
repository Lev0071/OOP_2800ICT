#include <iostream>
#include <vector>
using namespace std;

// Method to print numbers
void printNumbers(const vector<int>& numbers,string command="Not provided") {
    if (command !=  "Not provided"){
        cout << "After Command: " << command << endl;
    }
    cout << "Vector Contents" << endl;
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    vector<int> vec;printNumbers(vec,"vector<int> vec");
    vec.push_back(10);printNumbers(vec,"vec.push_back(10)");
    vec.push_back(30);printNumbers(vec,"vec.push_back(30)");
    vec.pop_back();printNumbers(vec,"vec.pop_back()");
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;printNumbers(vec,"vec.capacity()");
    vec.push_back(90);printNumbers(vec,"vec.push_back(90)");
    vec.push_back(100);printNumbers(vec,"vec.push_back(100)");
    vec.pop_back();printNumbers(vec,"vec.pop_back()");
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;printNumbers(vec);
    vec.pop_back();printNumbers(vec,"vec.pop_back()");
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;printNumbers(vec),"vec.size() and vec.capacity()";
    cout << "Is empty?: " << (vec.empty() ? "Yes":"No") << endl;printNumbers(vec,"vec.empty() ? 'Yes':'No'");
    vec.pop_back();printNumbers(vec,"vec.pop_back()");
    cout << "Is empty?: " << (vec.empty() ? "Yes":"No") << endl;printNumbers(vec,"vec.empty() ? 'Yes':'No'");
    vec.clear();printNumbers(vec);printNumbers(vec,"vec.clear()");
    cout << "Size after clear: " << vec.size() << endl;
    vec.push_back(10);printNumbers(vec,"vec.push_back(10)");
    vec.push_back(30);printNumbers(vec,"vec.push_back(30)");
    vec.insert(vec.begin()+1,20);printNumbers(vec,"vec.insert(vec.begin()+1,20)"); // Insert 20 at index 1
    vec.erase(vec.begin());printNumbers(vec,"vec.erase(vec.begin())"); // Removes the first element
    vec.push_back(40);printNumbers(vec,"vec.push_back(40)");
    vec.push_back(50);printNumbers(vec,"vec.push_back(50)");
    vec.erase(vec.begin(),vec.begin()+2);printNumbers(vec,"vec.erase(vec.begin(),vec.begin()+2)"); // Removes first two element
    vec.reserve(10);// Reserves capacity for 10 elements (does not change size)
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;
    vec.shrink_to_fit();
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;
    vec.insert(vec.begin(),10);printNumbers(vec,"vec.insert(vec.begin(),10)");
    vec.insert(vec.end()-1,90);printNumbers(vec,"vec.insert(vec.end()-1,90)");
    return 0;
} 