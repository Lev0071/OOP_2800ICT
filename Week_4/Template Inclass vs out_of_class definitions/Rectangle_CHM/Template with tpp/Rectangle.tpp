#include<iostream>
using namespace std;

template<typename T1,typename T2,typename T3>
Rectangle<T1,T2,T3>::~Rectangle(){cout<<name<<" destroyed\n";}

template<typename T1,typename T2,typename T3>
void Rectangle<T1,T2,T3>::setName(const string& s){name = s;}

template<typename T1,typename T2,typename T3>
void Rectangle<T1,T2,T3>::setWidth(T2 w){width =w;}

template<typename T1,typename T2,typename T3>
void Rectangle<T1,T2,T3>::setLength(T3 l){length =l;}

template<typename T1,typename T2,typename T3>
string Rectangle<T1,T2,T3>::getName() const {return name;}

template<typename T1,typename T2,typename T3>
T1 Rectangle<T1,T2,T3>::getWidth() const {return width;}

template<typename T1,typename T2,typename T3>
T2 Rectangle<T1,T2,T3>::getLength() const{return length;}

template<typename T1,typename T2,typename T3>
T3 Rectangle<T1,T2,T3>::getArea() const{ return static_cast<T3>(width) * static_cast<T3>(length); };








