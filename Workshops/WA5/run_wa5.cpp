#include <iostream>
#include <memory>
#include <iomanip> 
using namespace std;
#include "Circle.hpp"

// g++ -std=c++2b run_wa5.cpp -o WA5


// =============Don't modify the code below==============
int main()
{
    cout << setfill('=') << setw(50) << "" << endl;
    cout << "Output 1: " << endl;
    Point p1(1.0, 1.0);
    Point p2(p1);
    p2.setX(2);
    p2.setY(2);
    cout << "p1 " << p1 << endl;
    cout << "p2 " << p2 << endl;
    cout << setfill('-') << setw(50) << "" << endl;

    p2 = p1;
    p2.setX(3);
    p2.setY(3);
    cout << "p1 " << p1 << endl;
    cout << "p2 " << p2 << endl;
    cout << setfill('=') << setw(50) << "" << endl<<endl;

    cout << "Output 2: " << endl;
    Point p3 = move(p2);
    cout << "p2 " << p2 << endl;
    cout << "p3 " << p3 << endl;
    cout << setfill('-') << setw(50) << "" << endl;

    p3 = move(p1);
    cout << "p1 " << p1 << endl;
    cout << "p3 " << p3 << endl;
    cout << setfill('=') << setw(50) << "" << endl<<endl;


    cout << "Output 3: " << endl;
    Circle c1;
    c1.setCenter(p3);
    c1.setCenter(10,10);
    cout << "p3 " << p3 << endl;
    cout << "c1 " << c1 << endl;
    cout << setfill('-') << setw(50) << "" << endl;

    Circle c2(c1);
    c2.setCenter(20,20);
    cout << "c1 " << c1 << endl;
    cout << "c2 " << c2 << endl;
    cout << setfill('=') << setw(50) << "" << endl<<endl;

    cout << "Output 4: " << endl;
    Circle c3;
    c3 = c2;
    c3.setCenter(30,30);
    cout << "c2 " << c2 << endl;
    cout << "c3 " << c3 << endl;
    cout << setfill('-') << setw(50) << "" << endl;

    c3 = move(c2);
    cout << "c2 " << c2 << endl;
    cout << "c3 " << c3 << endl;
    cout << setfill('=') << setw(50) << "" << endl<<endl;

    return 0;
}
// =============Don't modify the code above==============
