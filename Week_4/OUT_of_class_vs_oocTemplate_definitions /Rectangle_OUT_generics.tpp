// Rectangle_OUT.tpp
#include <iostream>
#include <string>
#include "Rectangle_OUT_tss_generics.hpp" 


template<typename T1,typename T2,typename T3>
Rectangle<T1,T2,T3>::~Rectangle(){cout << name << " object destroyed.";}

//setters
template<typename T1, typename T2, typename T3>
void Rectangle<T1,T2,T3>::setWidth(double w){width = w;}

template<typename T1, typename T2, typename T3>
void Rectangle<T1,T2,T3>::setLength(double l){length = l;}

template<typename T1, typename T2, typename T3>
void Rectangle<T1,T2,T3>::setName(const string &n){name = n;}


//getters
template<typename T1, typename T2, typename T3>
std::string Rectangle<T1,T2,T3>::getName() const {return name;}

template<typename T1, typename T2, typename T3>
T1 Rectangle<T1,T2,T3>::getWidth() const {return width;}

template<typename T1, typename T2, typename T3>
T2 Rectangle<T1,T2,T3>::getLength() const {return length;}

template<typename T1, typename T2, typename T3>
T3 Rectangle<T1,T2,T3>::getArea() const { return static_cast<T3>(length) * static_cast<T3>(width);}