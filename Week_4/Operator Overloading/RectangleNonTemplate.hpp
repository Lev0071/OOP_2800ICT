// BoxHeaderOnly.hpp

#ifndef RECTANGLENONTEMPLATE_HPP
#define RECTANGLENONTEMPLATE_HPP

#include <iostream>
using namespace std;

class Rectangle{
    private:
        double length{},width{};
    public:
        Rectangle();
        Rectangle(double length,double width);

        ~Rectangle();

        double getLength() const;
        double getWidth() const;
        double getArea() const;

        void setLength(double length);
        void setWidth(double width);

        bool operator==(const Rectangle &other)const;
        bool operator>(const Rectangle &other)const;
        bool operator<(const Rectangle &other)const;


        double operator+(const Rectangle &other) const;
        double operator-(const Rectangle &other) const;
        double operator/(const Rectangle &other) const;
        double operator*(const Rectangle &other) const;

        friend ostream &operator<<(ostream &out,const Rectangle &r);
};
#endif // RECTANGLENONTEMPLATE_HPP