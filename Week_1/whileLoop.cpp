#include <iostream>
using namespace std;

int main()
{
    char c{'y'};
    while(c == 'y')
    {
        cout << "Loop again (y/n)";
        cin >> c;
    }
    cout << "last insput was not 'y'"<< endl;
    return 0;
}