//Rectangle_IN.hpp 
#ifndef RECTANGLE_IN_H 
#define RECTANGLE_IN_H 
#include <string>
#include <iostream> 
using namespace std; 

class Rectangle{
	private:
		string name;
		double width;
		double length;

	public:
		~Rectangle(){cout << name << "object destroyed" << endl;} // Destructor
		//setters
		void setWidth(double w){width=w;}
		void setLength(double l){length = l;}
		void setName(const string &n){name = n;}
		//getters
		string getName() const {return name;}
		double getWidth() const {return width;}
		double getLength() const {return length;}
		double getArea() const {return length*width;}
};

#endif // RECTANGLE_IN_H 