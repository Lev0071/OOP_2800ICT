// BoxHeaderOnly.hpp

#ifndef RECTANGLEHEADERONLY_HPP
#define RECTANGLEHEADERONLY_HPP

#include <iostream>
using namespace std;

template<typename T>
class Rectangle{
    private:
        T length{},width{};
    public:
        Rectangle():length{0},width{0} {}
        Rectangle(T length=1,T width=1):length(length),width(width){
            cout << "Parameter contructor called!" << endl;
        }

        ~Rectangle(){
            cout << "Destructor called for!" << endl;
        }

        auto getLength() const{return length;}
        auto getWidth() const{return width;}
        auto getArea() const{return length*width;}

        void setLength(T length){this->length=length;}
        void setWidth(T width){this->width=width;}

        template<typename U>
        bool operator==(const Rectangle<U> &other)const{return getArea() == other.getArea();}
        template<typename U>
        bool operator>(const Rectangle<U> &other)const{return getArea() > other.getArea();}
        template<typename U>
        bool operator<(const Rectangle<U> &other)const{return getArea() < other.getArea();}

        template<typename U>
        auto operator+(const Rectangle<U> &other) const{return getArea() + other.getArea();}
        template<typename U>
        auto operator-(const Rectangle<U> &other) const{return getArea() - other.getArea();}
        template<typename U>
        auto operator/(const Rectangle<U> &other) const{return getArea() / other.getArea();}
        template<typename U>
        auto operator*(const Rectangle<U> &other) const{return getArea() * other.getArea();}

        friend ostream &operator<<(ostream &out,const Rectangle<T> &r){
            out << "Rectangle(length= " << r.getLength()
                << ",width= " << r.getWidth()
                << ",area= " << r.getArea()
                << ")";
            return out;
        }
};
#endif // RECTANGLEHEADERONLY_HPP