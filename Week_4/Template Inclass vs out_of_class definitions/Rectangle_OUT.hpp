// Rectangle.hpp
#ifndef RECTANGLE_OUT_HPP
#define RECTANGLE_OUT_HPP

template<typename T1,typename T2,typename T3>
class Rectangle{
private:
    T1 width;
    T2 length;

public:
    //Rectangle():width(0.0),length(0.0){}
    void setWidth(T1 w){ width = w; };
    void setLength(T2 l){ length = l; }
    T1 getWidth() const { return width; }
    T2 getLength() const { return length; }
    T3 getArea() const { return static_cast<T3>(width) * static_cast<T3>(length); }
};
#endif // RECTANGLE_OUT_HPP