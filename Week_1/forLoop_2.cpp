#include <iostream>
using namespace std;

int main()
{
    int numbers[] = {1,2,3,4,5,6,7,8,9,10,11};

    for(auto val: numbers)
    {
        cout << val << endl;
    }
    cout << "For loop using array";
    cout << endl;
    return 0;
}  