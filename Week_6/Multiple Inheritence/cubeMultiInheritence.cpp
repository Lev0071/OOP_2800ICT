#include <iostream>
using namespace std;

// Base class 1
class Square {
    protected:
        int sideLength;
    public:
        Square(int s) {
            sideLength = s;
            cout << "Square constructor called with side = " << s << endl;
        }
};

// Base class 2
class RectSolid {
    protected:
        int length, width, height;
    public:
        RectSolid(int l, int w, int h) {
            length = l;
            width = w;
            height = h;
            cout << "RectSolid constructor called with dimensions = " 
                 << l << " x " << w << " x " << h << endl;
        }
};

// Derived class
class Cube : public Square, public RectSolid {
    public:
        // Constructor delegates to both base classes
        Cube(int side) : Square(side), RectSolid(side, side, side) {
            cout << "Cube constructor called" << endl;
        }
};

int main() {
    Cube c(5);
    return 0;
}

// Outptut:
// Square constructor called with side = 5
// RectSolid constructor called with dimensions = 5 x 5 x 5
// Cube constructor called

// g++ -std=c++2b cubeMultiInheritence.cpp -o cubeMultiInheritence