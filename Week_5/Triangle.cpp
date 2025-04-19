#include "Triangle.h"


Triangle::Triangle()
{
    x = make_shared<double>(0.0); // x points to a memory location containing 0.0, behind the scenes x = shared_ptr<double>(new double(0.0));
    y = make_shared<double>(0.0);
    z = make_shared<double>(0.0);
    side1 = 0;
    side2 = 0;
    side3 = 0;
    //*x = 1; // The double that x points to is updated from 0.0 to 1.0
}

Triangle::Triangle(double x,double y,double z,double s1,double s2,double s3)
{
    // *x = 0.0 // dereference not allowed since memory space dne before the constructor 
    this->x = make_shared<double>(x);
    this->y = make_shared<double>(y);
    this->z = make_shared<double>(z);
    side1 = s1;
    side2 = s2;
    side3 = s3;
}

// Triangle newTriangle = existingTriangle
// copy constructor
Triangle::Triangle(const Triangle &existingTriangle){
    x = make_shared<double>(*existingTriangle.x);
    y = make_shared<double>(*existingTriangle.y);
    z = make_shared<double>(*existingTriangle.z);
    side1 = existingTriangle.side1;
    side2 = existingTriangle.side2;
    side3 = existingTriangle.side3;
}

// move constructor
Triangle::Triangle(Triangle &&other){
    x = move(other.x); // compiler will remove the unsued space  
    y = move(other.y);
    z = move(other.z);
    side1 = other.side1;
    side2 = other.side2;
    side3 = other.side3;
}

// copy assignemnt // obj2 = obj1 
Triangle &Triangle::operator=(const Triangle &other){
    if (&other != this){
        *x = *other.x;  // Deep copy, this is a shallow copy -> x = other.x
        *y = *other.y;
        *z = *other.z;
        side1 = other.side1;
        side2 = other.side2;
        side3 = other.side3;
    }
    return *this;
}


// move assignmant // obj2 = move(obj1) 
Triangle &Triangle::operator=(Triangle &&other){
    if(this != &other)
    {
        x = move(other.x);
        y = move(other.y);
        z = move(other.z);
        side1 = other.side1;
        side2 = other.side2;
        side3 = other.side3;
    }
    return *this;
}

void Triangle::setx(double x){*this->x = x;}
void Triangle::sety(double y){*this->y = y;}
void Triangle::setz(double z){*this->z = z;}

void Triangle::setside1(double s1){side1 = s1;}
    
void Triangle::setside2(double s2){side2 = s2;}
    
void Triangle::setside3(double s3){side3 = s3;}
    
void Triangle::setsides(double s1,double s2,double s3){
    side1 = s1;
    side2 = s2;
    side3 = s3;
}

ostream &operator<<(ostream &out,const Triangle &InputObj){
    out<< "Triangle(x= ";
    if(InputObj.x)out<<*InputObj.x<<", ";else out<< "null, ";
    out<< ",y= ";
    if(InputObj.y)out<<*InputObj.y<<", ";else out<< "null, ";
        out<< ",z= ";
    if(InputObj.z)out<<*InputObj.z<<", ";else out<< "null, ";
    out<< "side1= " << InputObj.side1 << ", ";
    out<< "side2= " << InputObj.side2 << ", ";
    out<< "side3= " << InputObj.side3 << ")";

    return out;
}
