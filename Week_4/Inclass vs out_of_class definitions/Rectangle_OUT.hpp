// Rectangle.hpp
#ifndef RECTANGLE_OUT_H
#define RECTANGLE_OUT_H

class Rectangle{
private:
    double width;
    double length;

public:
    //Rectangle():width(0.0),length(0.0){}
    void setWidth(double w);
    void setLength(double l);
    double getWidth() const;
    double getLength() const;
    double getArea() const;
};
#endif // RECTANGLE_OUT_H