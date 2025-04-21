// RectangleNonTemplate.hpp
#pragma once
#define USE_NON_TEMPLATE

#ifndef RECTANGLE_NON_TEMPLATE_HPP
#define RECTANGLE_NON_TEMPLATE_HPP

#include <iostream>
#include <string>
using namespace std;


class Rectangle{
	private:
		double length{},width{};
		string name;
	public:
		Rectangle();
		Rectangle(double len,double wid,string nm);

		~Rectangle();

		string getName() const;
		double getLength() const;
		double getWidth() const;
		double getArea() const;

		void setLength(double length);
		void setWidth(double width);
		void setName(const string& name);


		bool operator==(const Rectangle &other) const;
		bool operator>(const Rectangle &other) const;
		bool operator<(const Rectangle &other) const;

		double operator+(const Rectangle &other) const;
		double operator-(const Rectangle &other) const;
		double operator*(const Rectangle &other) const;
		double operator/(const Rectangle &other) const;

		friend ostream &operator<<(ostream &out,const Rectangle &r);



};

#endif //RECTANGLE_NON_TEMPLATE_HPP