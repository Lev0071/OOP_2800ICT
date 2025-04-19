#include <iostream>
#include "Rectangle_IN.hpp"
using namespace std;


int main(){
    cout<< "Executing mainRectangle_IN.cpp"<<endl;
    Rectangle rec1;
    Rectangle rec2;

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