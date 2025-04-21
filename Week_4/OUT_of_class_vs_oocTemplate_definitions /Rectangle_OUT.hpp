//Rectangle_OUT.hpp 
#ifndef RECTANGLE_OUT_H 
#define RECTANGLE_OUT_H 
#include <string>
#include <iostream> 
using namespace std; 

class Rectangle{
	private:
		string name;
		double width;
		double length;

	public:
		~Rectangle(); // Destructor
		//setters
		void setWidth(double w);
		void setLength(double l);
		void setName(const string &n);
		//getters
		string getName() const;
		double getWidth() const;
		double getLength() const;
		double getArea() const;
};

#endif // RECTANGLE_OUT_H 