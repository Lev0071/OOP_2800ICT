#include <iostream>
#include <limits>
using namespace std;

int main() {
    int age;
    bool cont=true;

    while(cont){
    cout << "Enter your age(enter 99999 to quit): ";
    cin >> age;

    if (cin.fail()) {
        cin.clear(); // ✅ Reset error flags so cin works again
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ✅ Discard invalid input from buffer
        cout << "❌ Invalid input. Please enter a valid number next time.\n";
    } else {
        cout << "✅ You entered age: " << age << endl;
        if(age==99999)cont=!cont;
    }
    }
    return 0;
}
// g++ -std=c++2b cinFail.cpp -o cinFail