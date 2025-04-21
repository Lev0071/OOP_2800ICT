// RectangleHeaderOnly.hpp
#pragma once
#define USE_TEMPLATE

#ifndef RECTANGLEHEADERONLY_HPP
#define RECTANGLEHEADERONLY_HPP

#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Rectangle{
	private:
		T length{},width{};
		string name;
	public:
		Rectangle():length{0},width{0},name{}{}
		Rectangle(T len,T wid,string nm):length(len),width(wid),name(nm){
			cout << "Parameter Constructor called for "<< name << " object!" << endl;
		}

		~Rectangle(){ cout << "Destructor called for "<< name << " object!" << endl;}

		string getName() const {return name;}
		auto getLength() const {return length;}
		auto getWidth() const {return width;}
		auto getArea() const {return length*width;}

		void setLength(T length){this->length=length;}
		void setWidth(T width){this->width=width;}
		void setName(const string& name){this->name=name;}

		template<typename U>
		bool operator==(const Rectangle<U> &other) const {return getArea()==other.getArea();}

		template<typename U>
		bool operator>(const Rectangle<U> &other) const {return getArea()>other.getArea();}

		template<typename U>
		bool operator<(const Rectangle<U> &other) const {return getArea()<other.getArea();}


		template<typename U>
		auto operator+(const Rectangle<U> &other) const {return getArea()+other.getArea();}


		template<typename U>
		auto operator-(const Rectangle<U> &other) const {return getArea()-other.getArea();}


		template<typename U>
		auto operator*(const Rectangle<U> &other) const {return getArea()*other.getArea();}


		template<typename U>
		auto operator/(const Rectangle<U> &other) const {return getArea()/other.getArea();}

		friend ostream &operator<<(ostream &out,const Rectangle<T> &r){
			out << "Rectangle(length = " << r.getLength()
				<< ",width = " << r.getWidth()
				<< ",area = " << r.getArea()
				<< ")";

				return out;
		}


};

#endif //RECTANGLEHEADERONLY_HPP