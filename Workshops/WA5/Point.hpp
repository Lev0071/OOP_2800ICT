// Point.hpp
#ifndef POINT_H
#define POINT_H

// space(x,y)
#include <memory>
#include <iostream>
using namespace std;

class Point{
	private:
		shared_ptr<double> x;
		shared_ptr<double> y;
	public:
		// Constructors
		//Point():x(make_shared<double>(0)),y(make_shared<double>(0)){} // default constructor 				→ Example: Point point1;
		Point(double xVal = 0, double yVal = 0):x(make_shared<double>(xVal)), y(make_shared<double>(yVal)) {} // default constructor 				→ Example: Point point1; or Point point1(3.0, 4.0);
		Point(const Point &Other):x(make_shared<double>(*Other.x)),y(make_shared<double>(*Other.y)) {} // copy constructor 							→ Point point2(point1)
		//Point(const Point &Other){x=make_shared<double>(*Other.x);y=make_shared<double>(*Other.y);} // copy constructor 							→ Point point2(point1)
		Point(Point &&other) noexcept {x=move(other.x);y=move(other.y);} // Move Constructor								→ Point point3 = move(point2)
		Point &operator=(const Point &other){if (this != &other){*x=*other.x;*y=*other.y;}return *this;} // copy assignment 				→ Example: point2 = point1;
		
		// setters
		void setX(double x){*this->x = x;}
		void setY(double y){*this->y = y;}
		//getters
		double getX() const {return *x;}
		double getY() const {return *y;}

		bool hasX() const { return static_cast<bool>(x); }
		bool hasY() const { return static_cast<bool>(y); }

		friend ostream &operator<<(ostream &out,const Point &PointToPrint){
			out << "Point(x = ";
				if(PointToPrint.hasX()){
					cout<< PointToPrint.getX();
				}else{
					cout<< "NULL";
				}
				cout << ",y = ";
				if(PointToPrint.hasY()){
					cout<< PointToPrint.getY();
				}else{
					cout<< "NULL";
				}
				cout<< ")";

				return out;
		}
};
#endif // POINT_H


// Next as practice make a Point.hpp + Point.cpp version

// Point.hpp
// #ifndef POINT_H
// #define POINT_H

// // space(x,y)
// #include <memory>
// #include <iostream>
// using namespace std;

// class Point{
// 	private:
// 		shared_ptr<double> x;
// 		shared_ptr<double> y;
// 	public:
// 		// Constructors
// 		Point(double x = 0, double y = 0); // default constructor 				→ Example: Point point1; or Point point1(3.0, 4.0);
// 		Point(const Point &Other); // copy constructor 							→ Point point2(point1)
// 		Point(Point &&other); // Move Constructor								→ Point point3 = move(point2)
// 		Point &operator=(const Point &other); // copy assignment 				→ Example: point2 = point1;
// 		Point &operator=(Point &&other); // move assignment 					→ Example: point3 = move(point2);
// 		// setters
// 		void setX(double x);
// 		void setY(double y);
// 		//getters
// 		double getX() const;
// 		double getY() const;
// 		friend ostream &operator<<(ostream &out,const Point &PointToPrint);
// };
// #endif