#include <iostream>
using namespace std;

class RunningTotal {
    int total = 0;
public:
    int operator()(int val) {
        total += val;
        return total;
    }
};

class Greeter {
    public:
        void operator()(const char* str = "") {
            cout << "Hello! <<< " << str << " >>>\n";
        }
    };

int main() {
    RunningTotal rt;
    cout << rt(5) << endl;  // 5
    cout << rt(3) << endl;  // 8
    cout << rt(10) << endl; // 18

    Greeter g;
    g("Leo");  // ✅ This calls g.operator()("Leo")
    g();       // ✅ This calls g.operator()("") — default value
    return 0;
}
    