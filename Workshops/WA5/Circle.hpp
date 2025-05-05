// Circle.hpp
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.hpp"

// space(x,y)
#include <memory>
#include <iostream>
using namespace std;

class Circle{
	private:
		Point center;
		double radius;
	public:
		// Constructors
		Circle(double x = 0, double y = 0,double radius=0): center(x,y), radius(radius){} // default constructor 				→ Example: Point point1; or Point point1(3.0, 4.0);
		void setCenter(double x,double y){center.setX(x);center.setY(y);}
		void setCenter(const Point &newCenter){center = newCenter;}
		void setRadius(double rad){radius=rad;}
		Point getCenter() const {return center;}
		double getRadius() const {return radius;}
		bool hasX() const { return center.hasX(); }
		bool hasY() const { return center.hasY(); }
		
		friend ostream &operator<<(ostream &out,const Circle &cirleToPrint){
			out << "Circle[Point(x = ";
				if(cirleToPrint.hasX()){
					out << cirleToPrint.center.getX();
				} else {
					out << "NULL";
				}
				out << ",y = ";
				if(cirleToPrint.hasY()){
					out << cirleToPrint.center.getY();
				} else {
					out << "NULL";
				}
				out << "), radius= " << cirleToPrint.radius
					<< "]";

				return out;
		}
};
#endif // CIRCLE_H
// Point
// double raduis

// << Points details,idf the point object has moved and is empty, null istead of dereferencing a n invalid pointer