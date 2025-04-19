#include <iostream>
#include "Rectangle.hpp"
using namespace std;


int main(){
    cout << "Executing Rectangle with Templating + TPP" <<endl;
    Rectangle<int, int, int> rec1;
    Rectangle<int, int, int> rec2;

    rec1.setName("Rectangle 1");
    rec2.setName("Rectangle 2");

    cout << "Rectangle 1" << "\n";
    cout << "Width: " << rec1.getWidth() << "\n";
    cout << "Length: " << rec1.getLength() << "\n";
    cout << "Area: " << rec1.getArea() << "\n";
    cout << "\n\n";
    cout << "Rectangle 2" << "\n";
    cout << "Width: " << rec2.getWidth() << "\n";
    cout << "Length: " << rec2.getLength() << "\n";
    cout << "Area: " << rec2.getArea() << "\n";
    cout << "\n\n";

    cout << "After setting Rectangle 1 and Rectangle 2" << "\n";
    rec1.setLength(5);
    rec1.setWidth(10);

    rec2.setLength(6);
    rec2.setWidth(10);

    cout << "Rectangle 1" << "\n";
    cout << "Width: " << rec1.getWidth() << "\n";
    cout << "Length: " << rec1.getLength() << "\n";
    cout << "Area: " << rec1.getArea() << "\n";
    cout << "\n\n";
    cout << "Rectangle 2" << "\n";
    cout << "Width: " << rec2.getWidth() << "\n";
    cout << "Length: " << rec2.getLength() << "\n";
    cout << "Area: " << rec2.getArea() << "\n";
    cout << "\n\n";

    return 0;
}

// clang++ -c main.cpp -o build/Debug/main.o
// clang++ -c Rectangle.cpp -o build/Debug/Rectangle.o
// clang++ build/Debug/main.o build/Debug/Rectangle.o -o build/Debug/outDebug

// ./build/Debug/outDebug
