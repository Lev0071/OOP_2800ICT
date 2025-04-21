// Rectangle_OUT.cpp
#include <iostream>
#include <string>
#include "Rectangle_OUT.hpp" 
using namespace std;

Rectangle::~Rectangle(){cout << name << " object destroyed.";}

//setters
void Rectangle::setWidth(double w){width = w;}
void Rectangle::setLength(double l){length = l;}
void Rectangle::setName(const string &n){name = n;}
//getters
string Rectangle::getName() const {return name;}
double Rectangle::getWidth() const {return width;}
double Rectangle::getLength() const {return length;}
double Rectangle::getArea() const { return length * width;}