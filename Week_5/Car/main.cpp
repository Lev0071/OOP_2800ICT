#include <iostream>
using namespace std;

//#include "car.hpp"
#include "carPtr.hpp"

int main(){
    Car toyota("Toyota",2007);                 // original holds value 42
    Car toyota_2 = toyota;                     // deep copy of original

    cout << "Original car:\n";
    toyota.showInfo();

    cout << "Original car modified:\n";
    toyota.setBrand("Holden");
    toyota.setYear(2019);
    toyota.showInfo();

    cout<<"\n";
    cout << "Copied car:\n";
    toyota.showInfo();
    return 0;
}