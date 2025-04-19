#include "Triangle.h"

Triangle::Triangle()
    : side1(0), side2(0), side3(0)
{
    // shared_ptrs already initialized via in-class initializers
}

Triangle::Triangle(double xVal, double yVal, double zVal, double s1, double s2, double s3)
    : side1(s1), side2(s2), side3(s3)
{
    *x = xVal;
    *y = yVal;
    *z = zVal;
}

// Copy constructor
Triangle::Triangle(const Triangle &other)
{
    x = make_shared<double>(*other.x);
    y = make_shared<double>(*other.y);
    z = make_shared<double>(*other.z);
    side1 = other.side1;
    side2 = other.side2;
    side3 = other.side3;
}

// Move constructor
Triangle::Triangle(Triangle &&other)
{
    x = move(other.x);
    y = move(other.y);
    z = move(other.z);
    side1 = other.side1;
    side2 = other.side2;
    side3 = other.side3;
}

// Copy assignment
Triangle &Triangle::operator=(const Triangle &other)
{
    if (this != &other)
    {
        *x = *other.x;
        *y = *other.y;
        *z = *other.z;
        side1 = other.side1;
        side2 = other.side2;
        side3 = other.side3;
    }
    return *this;
}

// Move assignment
Triangle &Triangle::operator=(Triangle &&other)
{
    if (this != &other)
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

// Setters
void Triangle::setx(double xVal) { *x = xVal; }
void Triangle::sety(double yVal) { *y = yVal; }
void Triangle::setz(double zVal) { *z = zVal; }

void Triangle::setside1(double s1) { side1 = s1; }
void Triangle::setside2(double s2) { side2 = s2; }
void Triangle::setside3(double s3) { side3 = s3; }

void Triangle::setsides(double s1, double s2, double s3)
{
    side1 = s1;
    side2 = s2;
    side3 = s3;
}

// Overloaded << operator
ostream &operator<<(ostream &out, const Triangle &InputObj)
{
    out << "Triangle(x= ";
    if (InputObj.x) out << *InputObj.x << ", "; else out << "null, ";
    out << "y= ";
    if (InputObj.y) out << *InputObj.y << ", "; else out << "null, ";
    out << "z= ";
    if (InputObj.z) out << *InputObj.z << ", "; else out << "null, ";
    out << "side1= " << InputObj.side1 << ", ";
    out << "side2= " << InputObj.side2 << ", ";
    out << "side3= " << InputObj.side3 << ")";

    return out;
}
