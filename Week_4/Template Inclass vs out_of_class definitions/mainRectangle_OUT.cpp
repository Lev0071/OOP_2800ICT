#include <iostream>
#include "Rectangle_OUT.hpp"
using namespace std;

// template<typename T1, typename T2, typename T3>
// void Rectangle<T1, T2, T3>::setWidth(T1 w){
//     width = w;
// }
// template<typename T1, typename T2, typename T3>
// void Rectangle<T1, T2, T3>::setLength(T2 w){
//     length = w;
// }

// template<typename T1, typename T2, typename T3>
// T1 Rectangle<T1, T2, T3>::getWidth()const{
//     return width;
// }

// template<typename T1, typename T2, typename T3>
// T2 Rectangle<T1, T2, T3>::getLength()const{
//     return length;
// }

// template<typename T1, typename T2, typename T3>
// T3 Rectangle<T1, T2, T3>::getArea()const{
//     return length * width;
// }

int main(){

    cout << "Running Rectangle_OUT \n\n";
    
    Rectangle<int, int, int> rec1;
    Rectangle<int, int, int> rec2;

    cout << "Reactangle 1" << "\n";
    cout << "Width: " << rec1.getWidth() << "\n";
    cout << "Length: " << rec1.getLength() << "\n";
    cout << "Area: " << rec1.getArea() << "\n";
    cout << "\n\n";
    cout << "Reactangle 2" << "\n";
    cout << "Width: " << rec2.getWidth() << "\n";
    cout << "Length: " << rec2.getLength() << "\n";
    cout << "Area: " << rec2.getArea() << "\n";
    cout << "\n\n";

    cout << "After setting Reactangle 1 and Reactangle 2" << "\n";
    rec1.setLength(5);
    rec1.setWidth(10);

    rec2.setLength(6);
    rec2.setWidth(10);

    cout << "Reactangle 1" << "\n";
    cout << "Width: " << rec1.getWidth() << "\n";
    cout << "Length: " << rec1.getLength() << "\n";
    cout << "Area: " << rec1.getArea() << "\n";
    cout << "\n\n";
    cout << "Reactangle 2" << "\n";
    cout << "Width: " << rec2.getWidth() << "\n";
    cout << "Length: " << rec2.getLength() << "\n";
    cout << "Area: " << rec2.getArea() << "\n";
    cout << "\n\n";

    return 0;
}