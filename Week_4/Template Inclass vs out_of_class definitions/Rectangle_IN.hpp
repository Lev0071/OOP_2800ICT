// Rectangle.hpp
#ifndef RECTANGLE_IN_H
#define RECTANGLE_IN_H

template<typename T1=int,typename T2=int>
class Rectangle{
private:
    T1 width;
    T2 length;

public:
    //Rectangle():width(0.0),length(0.0){}
    void setWidth(T1 w){width=w;}
    void setLength(T2 l){length=l;}
    double getWidth() const {return width;}
    double getLength() const {return length;}
    double getArea() const {return width * length;}
};
#endif // RECTANGLE_H