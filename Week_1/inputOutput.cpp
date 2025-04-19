#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    int x{},y{99};
    cout << "Please enter two numbers: ";
    cin >> x >> y;
    auto sum = x + y;
    cout<< x <<" + "<< y << " = " << sum << endl;
    cout<< " Of data type: "<< typeid(sum).name() << endl;
    return 0;
}
 
// #include <iostream>
// using namespace std;

// int main()99 1

// { 
//     int x{},y{99};
//     int sum{};
//     cout << "Please enter two numbers: ";
//     cin >> x >> y;
//     //int sum = x + y;
//     sum = x + y;  
//     cout<< x <<" + "<< y << " = " << sum << std::endl;
//     return 0;
// }

// #include <iostream>

// int main()
// {
//     int x{},y{99};
//     int sum{};
//     std::cout << "Please enter two numbers: ";
//     std::cin >> x >> y;
//     //int sum = x + y;
//     sum = x + y;  
//     std::cout<< x <<" + "<< y << " = " << sum << std::endl;
//     return 0;
// }