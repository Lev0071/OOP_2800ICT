#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class IsEven {
    public:
        void operator()(int &x) const{
            x = x%2;
        }
};

int main() {
    vector<int> vint{1, 2, 3, 4, 5};

    cout << "Using class as a lambda"<<endl;
    for_each(vint.begin(), vint.end(), IsEven());
    // Optional: print results
    for (int val : vint) {
        cout << val << " ";
    }
    cout << "\nUsing a literal lambda"<<endl;
    for_each(vint.begin(), vint.end(), [](int &x) {x = x * 9;});

    // Optional: print results
    for (int val : vint) {
        cout << val << " ";
    }

    return 0;
}
// g++ -std=c++2b isEvenLambda.cpp -o isEvenLambda