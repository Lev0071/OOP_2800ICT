// RectangleWithTpp.hpp
#pragma once
#define USE_TEMPLATE

// RectangleHeaderOnly.hpp
#pragma once
#define USE_TEMPLATE

#ifndef RECTANGLE_WITH_TPP_HPP
#define RECTANGLE_WITH_TPP_HPP

#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Rectangle{
	private:
		T length{},width{};
		string name;
	public:
		Rectangle();
		Rectangle(T length,T width,string name);

		~Rectangle();

		string getName() const;
		T getLength() const;
		T getWidth() const;
		T getArea() const;

		void setLength(T length);
		void setWidth(T width);
		void setName(const string& name);

	    // 🔁 Cross-type comparison and arithmetic
	    template<typename U>
	    bool operator==(const Rectangle<U>& other) const;

	    template<typename U>
	    bool operator>(const Rectangle<U>& other) const;

	    template<typename U>
	    bool operator<(const Rectangle<U>& other) const;

	    template<typename U>
	    auto operator+(const Rectangle<U>& other) const;

	    template<typename U>
	    auto operator-(const Rectangle<U>& other) const;

	    template<typename U>
	    auto operator*(const Rectangle<U>& other) const;

	    template<typename U>
	    auto operator/(const Rectangle<U>& other) const;

	    // ✅ Output operator for same type
	    template<typename W>
	    friend ostream& operator<<(ostream& out, const Rectangle<W>& r);


};
#include "Rectangle.tpp"
#endif //RECTANGLE_WITH_TPP_HPP