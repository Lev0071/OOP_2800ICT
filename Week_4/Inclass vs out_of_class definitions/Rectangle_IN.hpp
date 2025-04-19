// Rectangle.hpp
#ifndef RECTANGLE_IN_H
#define RECTANGLE_IN_H

class Rectangle{
private:
    double width;
    double length;

public:
    //Rectangle():width(0.0),length(0.0){}
    void setWidth(double w){width=w;}
    void setLength(double l){length=l;}
    double getWidth() const {return width;}
    double getLength() const {return length;}
    double getArea() const {return width * length;}
};
#endif // RECTANGLE_H