// RectangleNonTemplate.cpp
#include "RectangleNonTemplate.hpp"

Rectangle::Rectangle():length{0},width{0},name{""}{}
Rectangle::Rectangle(double len,double wid,string nm):length(len),width(wid),name(nm){
	cout << "Parameter Constructor called for "<< name << " object!" << endl;
}

Rectangle::~Rectangle(){ cout << "Destructor called for "<< name << " object!" << endl;}

string Rectangle::getName() const {return name;}
double Rectangle::getLength() const {return length;}
double Rectangle::getWidth() const {return width;}
double Rectangle::getArea() const {return length*width;}

void Rectangle::setLength(double length){this->length=length;}
void Rectangle::setWidth(double width){this->width=width;}
void Rectangle::setName(const string& name){this->name=name;}

bool Rectangle::operator==(const Rectangle &other) const {return getArea()==other.getArea();}
bool Rectangle::operator>(const Rectangle &other) const {return getArea()>other.getArea();}
bool Rectangle::operator<(const Rectangle &other) const {return getArea()<other.getArea();}

double Rectangle::operator+(const Rectangle &other) const {return getArea()+other.getArea();}
double Rectangle::operator-(const Rectangle &other) const {return getArea()-other.getArea();}
double Rectangle::operator*(const Rectangle &other) const {return getArea()*other.getArea();}
double Rectangle::operator/(const Rectangle &other) const {return getArea()/other.getArea();}

ostream &operator<<(ostream &out,const Rectangle &r){
	out << "Rectangle(length = " << r.getLength()
		<< ",width = " << r.getWidth()
		<< ",area = " << r.getArea()
		<< ")";

	return out;
}
