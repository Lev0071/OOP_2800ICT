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
    ~Rectangle(){cout << "deleting "<< name << " ...." << endl;}; // Destructor
    void setName(const string& s){name = s;}
    void setWidth(T2 w){width =w;}
    void setLength(T3 l){length =l;}
    string getName() const {return name;}
    T1 getWidth() const {return width;}
    T2 getLength() const{return length;}
    T3 getArea() const{ return static_cast<T3>(width) * static_cast<T3>(length); };
};
#endif // RECTANGLE_HPP

    // ~Rectangle(); // Destructor
    // void setName(const std::string& s){name=s;}
    // void setWidth(double w){width=w;}
    // void setLength(double l){length=l;}
    // std::string getName() const {return name;}
    // double getWidth() const {return width;}
    // double getLength() const {return length;}
    // double getArea() const {return width * length;}