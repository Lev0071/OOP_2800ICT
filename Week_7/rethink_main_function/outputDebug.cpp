#include <iostream>
#include <cstdlib> // for std::atoi
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " <a> <b>" << endl;
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int sum = a + b;

    cout << "Sum: " << sum << endl;
    return 0;
}
//g++ -std=c++2b outputDebug.cpp -o outputDebug
// string input = argv[1];
// double d = stod(input);   // convert to double
// float f = stof(input);    // convert to float
