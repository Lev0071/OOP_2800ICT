#include <iostream>
#include <vector>
using namespace std;

// Method to print numbers
void printNumbers(const vector<int>& numbers, string command = "Not provided") {
    if (command != "Not provided") {
        cout << "After Command: " << command << endl;
    }
    cout << "Vector Contents" << endl;
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Create an empty vector: []
    vector<int> vec;
    printNumbers(vec, "vector<int> vec");

    // ➕ Add 10: [10]
    vec.push_back(10);
    printNumbers(vec, "vec.push_back(10)");

    // ➕ Add 30: [10, 30]
    vec.push_back(30);
    printNumbers(vec, "vec.push_back(30)");

    // ➖ Remove last element (30): [10]
    vec.pop_back();
    printNumbers(vec, "vec.pop_back()");

    // 📏 Check size and capacity
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;
    printNumbers(vec, "vec.capacity()");

    // ➕ Add 90: [10, 90]
    vec.push_back(90);
    printNumbers(vec, "vec.push_back(90)");

    // ➕ Add 100: [10, 90, 100]
    vec.push_back(100);
    printNumbers(vec, "vec.push_back(100)");

    // ➖ Remove 100: [10, 90]
    vec.pop_back();
    printNumbers(vec, "vec.pop_back()");

    // 📏 Check size and capacity
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;
    printNumbers(vec);

    // ➖ Remove 90: [10]
    vec.pop_back();
    printNumbers(vec, "vec.pop_back()");

    // 📏 Check again
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;
    printNumbers(vec); // "vec.size() and vec.capacity()" was in wrong place

    // ❓ Check if empty: No
    cout << "Is empty?: " << (vec.empty() ? "Yes" : "No") << endl;
    printNumbers(vec, "vec.empty() ? 'Yes':'No'");

    // ➖ Remove 10: []
    vec.pop_back();
    printNumbers(vec, "vec.pop_back()");

    // ❓ Check if empty: Yes
    cout << "Is empty?: " << (vec.empty() ? "Yes" : "No") << endl;
    printNumbers(vec, "vec.empty() ? 'Yes':'No'");

    // 🧹 Clear vector (already empty): []
    vec.clear();
    printNumbers(vec);
    printNumbers(vec, "vec.clear()");
    cout << "Size after clear: " << vec.size() << endl;

    // ➕ Add 10: [10]
    vec.push_back(10);
    printNumbers(vec, "vec.push_back(10)");

    // ➕ Add 30: [10, 30]
    vec.push_back(30);
    printNumbers(vec, "vec.push_back(30)");

    // ➕ Insert 20 at index 1: [10, 20, 30]
    vec.insert(vec.begin() + 1, 20);
    printNumbers(vec, "vec.insert(vec.begin()+1,20)");

    // ➖ Remove first element (10): [20, 30]
    vec.erase(vec.begin());
    printNumbers(vec, "vec.erase(vec.begin())");

    // ➕ Add 40: [20, 30, 40]
    vec.push_back(40);
    printNumbers(vec, "vec.push_back(40)");

    // ➕ Add 50: [20, 30, 40, 50]
    vec.push_back(50);
    printNumbers(vec, "vec.push_back(50)");

    // ➖ Remove first two elements (20, 30): [40, 50]
    vec.erase(vec.begin(), vec.begin() + 2);
    printNumbers(vec, "vec.erase(vec.begin(),vec.begin()+2)");

    // 📦 Reserve capacity for 10 elements
    vec.reserve(10);
    cout << "Size: " << vec.size() << endl;      // [40, 50]
    cout << "Capacity: " << vec.capacity() << endl;

    // 🧽 Shrink capacity to fit size
    vec.shrink_to_fit();
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;

    // ➕ Insert 10 at beginning: [10, 40, 50]
    vec.insert(vec.begin(), 10);
    printNumbers(vec, "vec.insert(vec.begin(),10)");

    // ➕ Insert 90 before last element: [10, 40, 90, 50]
    vec.insert(vec.end() - 1, 90);
    printNumbers(vec, "vec.insert(vec.end()-1,90)");

    return 0;
}
