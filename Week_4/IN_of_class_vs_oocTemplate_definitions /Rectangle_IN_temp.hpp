// Rectangle_IN_temp.hpp
//Rectangle_IN_temp.hpp 
#ifndef RECTANGLE_IN_TEMP_H 
#define RECTANGLE_IN_TEMP_H 

#include <string>
#include <iostream> 
using namespace std; 


template<typename T1,typename T2,typename T3>
class Rectangle{
	private:
		string name;
		T1 width;
		T2 length;

	public:
		//setters
		~Rectangle(){cout << name << "object destroyed" << endl;} // Destructor
		void setWidth(double w){width=w;}
		void setLength(double l){length = l;}
		void setName(const string &n){name = n;}
		//getters
		T1 getWidth() const {return width;}
		T2 getLength() const {return length;}
		T3 getArea() const {return length*width;}
		string getName() const {return name;}
};

#endif // RECTANGLE_IN_TEMP_H 