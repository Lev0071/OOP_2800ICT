// Rectangle.hpp
#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <string>
using namespace std;

template<typename T1,typename T2,typename T3>
class Rectangle{
private:
    T1 width;
    T2 length;
    string name;

public:
    //Rectangle():width(0.0),length(0.0){}
    ~Rectangle(); // Destructor
    void setName(const string& s);
    void setWidth(T2 w);
    void setLength(T3 l);
    string getName() const;
    T1 getWidth() const;
    T2 getLength() const;
    T3 getArea() const;
};
#include "Rectangle.tpp"
#endif // RECTANGLE_HPP

    // ~Rectangle(); // Destructor
    // void setName(const std::string& s){name=s;}
    // void setWidth(double w){width=w;}
    // void setLength(double l){length=l;}
    // std::string getName() const {return name;}
    // double getWidth() const {return width;}
    // double getLength() const {return length;}
    // double getArea() const {return width * length;}