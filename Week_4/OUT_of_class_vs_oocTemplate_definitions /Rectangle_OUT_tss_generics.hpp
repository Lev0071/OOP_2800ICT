//Rectangle_OUT_tss_generics.hpp 
#ifndef RECTANGLE_OUT_TSS_GENERICS 
#define RECTANGLE_OUT_TSS_GENERICS 
#include <string>
#include <iostream> 


template<typename T1,typename T2,typename T3>
class Rectangle{
	private:
		std::string name;
		T1 width;
		T2 length;

	public:
		~Rectangle(); // Destructor
		//setters
		void setWidth(double w);
		void setLength(double l);
		void setName(const string &n);
		//getters
		string getName() const;
		T1 getWidth() const;
		T2 getLength() const;
		T3 getArea() const;
};
#include "Rectangle_OUT_generics.tpp"
#endif // RECTANGLE_OUT_TSS_GENERICS 