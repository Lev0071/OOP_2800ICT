// Rectangle.cpp
#include "RectangleNonTemplate.hpp"

Rectangle::Rectangle():length(0),width(0){}

Rectangle::Rectangle(double length,double width):length(length),width(width){
    cout << "parametised constructor called!" << endl;
}

Rectangle::~Rectangle(){
    cout<<"Destructor called!" <<endl;
}

double Rectangle::getLength() const {return length;}
double Rectangle::getWidth() const {return width;}
double Rectangle::getArea() const {return length*width;}

void Rectangle::setLength(double length){this->length=length;}
void Rectangle::setWidth(double width){this->width=width;}

bool Rectangle::operator==(const Rectangle &other)const{return getArea() == other.getArea();}
bool Rectangle::operator>(const Rectangle &other)const{return getArea() > other.getArea();}
bool Rectangle::operator<(const Rectangle &other)const{return getArea() < other.getArea();}

double Rectangle::operator+(const Rectangle &other) const{return getArea() + other.getArea();}
double Rectangle::operator-(const Rectangle &other) const{return getArea() - other.getArea();}
double Rectangle::operator/(const Rectangle &other) const{return getArea() / other.getArea();}
double Rectangle::operator*(const Rectangle &other) const{return getArea() * other.getArea();}

ostream &operator<<(ostream &out,const Rectangle &r){
    out << "Rectangle(length= " << r.getLength()
                << ",width= " << r.getWidth()
                << ",area= " << r.getArea()
                << ")";
            return out;
}