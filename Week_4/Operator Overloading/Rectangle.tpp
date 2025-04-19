template <typename T>
Rectangle<T>::Rectangle() : length{0}, width{0}{}

template <typename T>
Rectangle<T>::Rectangle(T length, T width)
    : length(length), width(width){
    cout << "Parameterized constructor called!" << endl;
}

template <typename T>
Rectangle<T>::~Rectangle() {
    cout << "Destructor called!" << endl;
}

template <typename T>
auto Rectangle<T>::getLength() const{ return length; }
template <typename T>
auto Rectangle<T>::getWidth() const{ return width; }
template <typename T>
auto Rectangle<T>::getArea() const{ return length*width; }

template <typename T>
void Rectangle<T>::setLength(T length){this->length=length;}
template <typename T>
void Rectangle<T>::setWidth(T width){this->width=width;}

template <typename T>
bool Rectangle<T>::operator==(const Rectangle<T> &other)const{return getArea() == other.getArea();}
template <typename T>
bool Rectangle<T>::operator>(const Rectangle<T> &other)const{return getArea() > other.getArea();}
template <typename T>
bool Rectangle<T>::operator<(const Rectangle<T> &other)const{return getArea() < other.getArea();}

template <typename T>
auto Rectangle<T>::operator+(const Rectangle<T> &other) const{return getArea() + other.getArea();}
template <typename T>
auto Rectangle<T>::operator-(const Rectangle<T> &other) const{return getArea() - other.getArea();}
template <typename T>
auto Rectangle<T>::operator/(const Rectangle<T> &other) const{return getArea() / other.getArea();}
template <typename T>
auto Rectangle<T>::operator*(const Rectangle<T> &other) const{return getArea() * other.getArea();}

template <typename T>
ostream &operator<<(ostream &out,const Rectangle<T> &r){
    out << "Rectangle(Length= "<< r.getLength()
        << ",Width= " << r.getWidth()
        << "Area= "<< r.getArea() 
        <<")";
    return out;
}