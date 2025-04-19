// RectangleWithTpp.hpp

#ifndef RECTANGLEWITHTPP_HPP
#define RECTANGLEWITHTPP_HPP

#include <iostream>
using namespace std;

template<typename T>
class Rectangle{
    private:
        T length{},width{};
    public:
        Rectangle();
        Rectangle(T length,T width);

        ~Rectangle();

        auto getLength() const;
        auto getWidth() const;
        auto getArea() const;

        void setLength(T length);
        void setWidth(T width);

        bool operator==(const Rectangle<T> &other)const;
        bool operator>(const Rectangle<T> &other)const;
        bool operator<(const Rectangle<T> &other)const;


        auto operator+(const Rectangle<T> &other) const;
        auto operator-(const Rectangle<T> &other) const;
        auto operator/(const Rectangle<T> &other) const;
        auto operator*(const Rectangle<T> &other) const;

        template<typename W>
        friend ostream &operator<<(ostream &out,const Rectangle<W> &r);
};
#include "Rectangle.tpp" 
#endif // RECTANGLEWITHTPP_HPP