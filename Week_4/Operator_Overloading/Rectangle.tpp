// Rectangle.tpp
#include <string>

template<typename T>
Rectangle<T>::Rectangle():length{0},width{0},name{""}{}

template<typename T>
Rectangle<T>::Rectangle(T length,T width,string name):length(length),width(width),name(name){
	cout << "Parametised constructor called!" << endl;
}

template<typename T>
Rectangle<T>::~Rectangle(){
	cout << "Destructor called!" << endl;
}

template<typename T>
string Rectangle<T>::getName() const { return name; }

template<typename T>
T Rectangle<T>::getLength() const { return length; }

template<typename T>
T Rectangle<T>::getWidth() const { return width; }

template<typename T>
T Rectangle<T>::getArea() const { return length * width; }

template<typename T>
void Rectangle<T>::setLength(T length) { this->length = length; }
template<typename T>
void Rectangle<T>::setWidth(T width)   { this->width = width; }
template<typename T>
void Rectangle<T>::setName(const string& name) { this->name = name; }

template<typename T>
template<typename U>
bool Rectangle<T>::operator==(const Rectangle<U> &other) const {return getArea()==other.getArea();}

template<typename T>
template<typename U>
bool Rectangle<T>::operator>(const Rectangle<U> &other) const {return getArea()>other.getArea();}

template<typename T>
template<typename U>
bool Rectangle<T>::operator<(const Rectangle<U> &other) const {return getArea()<other.getArea();}

template<typename T>
template<typename U>
auto Rectangle<T>::operator+(const Rectangle<U> &other) const {return getArea()+other.getArea();}

template<typename T>
template<typename U>
auto Rectangle<T>::operator-(const Rectangle<U> &other) const {return getArea()-other.getArea();}

template<typename T>
template<typename U>
auto Rectangle<T>::operator*(const Rectangle<U> &other) const {return getArea()*other.getArea();}

template<typename T>
template<typename U>
auto Rectangle<T>::operator/(const Rectangle<U> &other) const {return getArea()/other.getArea();}

template<typename T>
ostream &operator<<(ostream &out,const Rectangle<T> &r){
	out << "Rectangle(length = " << r.getLength()
		<< ",width = " << r.getWidth()
		<< ",area = " << r.getArea()
		<< ")";

	return out;
}
