#include <iostream>
using namespace std;

// Base Class
class Shape{
    protected:
        int width,height;

    public:
    // Base class constructor
    Shape(int w,int h){
        width = w;
        height = h;
    }

    void displayArea(){
        cout << "Area: " << width * height << endl;
    }
};

// Derived Class
class Rectangle:public Shape{
    public:
        // Derived class constructor that passes arguments to base class constructor
        Rectangle(int side1,int side2):Shape(side1,side2){ // // passes side and side to Shape(int, int)
            cout << "Rectangle constructor called with sides: " << side1 << ", " << side2 << endl;
        }
};

int main(){
    Rectangle r(5,10); // This will call Rectangle's constructor → which calls Shape's constructor
    r.displayArea(); // Output: Area: 25
    
    return 0;
}