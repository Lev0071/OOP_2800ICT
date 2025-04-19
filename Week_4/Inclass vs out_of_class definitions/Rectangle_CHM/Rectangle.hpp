// Rectangle.hpp
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
using namespace std;

class Rectangle{
private:
    std::string name;
    double width;
    double length;

public:
    //Rectangle():width(0.0),length(0.0){}
    ~Rectangle(); // Destructor
    void setName(const std::string& s);
    void setWidth(double w);
    void setLength(double l);
    std::string getName() const;
    double getWidth() const;
    double getLength() const;
    double getArea() const;
};
#endif // RECTANGLE_H

    // ~Rectangle(); // Destructor
    // void setName(const std::string& s){name=s;}
    // void setWidth(double w){width=w;}
    // void setLength(double l){length=l;}
    // std::string getName() const {return name;}
    // double getWidth() const {return width;}
    // double getLength() const {return length;}
    // double getArea() const {return width * length;}