#include <iostream>
using namespace std;

// Base class
class Shape{
    protected:
        int length,width,height;
    public:
        // Base class constructor
        Shape(int w,int h,int l){
            length = l;
            width = w;
            height = h;
        }
        Shape(int w,int l){
            length = l;
            width = w;
            height = 0;
        }

        void displayArea(){
            cout << "Area: " << width*length << endl;
        }

        void displayVolume(){
            if(height == 0){
                cout << "The shape is a 2D object" << endl;
            } else {
                cout << "Volume: "<< length*width*height<< endl;
            }
        }
};

// Derived class
class Square:public Shape{
    public:
    // Derived class constructor that passes arguments to base class constructor
    Square(int side):Shape(side,side){ // passes side and side to Shape(int, int)
        cout << "Rectangle constructor called with side: " << side << endl;
    }

};

class Cube:public Shape{
    public:
    // Derived class constructor that passes arguments to base class constructor
    Cube(int side):Shape(side,side,side){ // passes side and side to Shape(int, int)
        cout << "Rectangle constructor called with side: " << side << endl;
    }

};

int main() {
    Square s(5); // This will call Square's constructor → which calls Shape's constructor
    s.displayArea(); // Output: Area: 25
    s.displayVolume(); // message

    Cube c(5); // This will call Cube's constructor → which calls Shape's constructor
    c.displayVolume(); // Output: Volume: 125
}

// Develop this to make it generic to find any surface area or volume of any 2D or 3D shape

// g++ -std=c++2b shape.cpp -o constructor