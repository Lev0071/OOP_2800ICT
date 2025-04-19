// car.hpp
#ifndef CAR_HPP
#define CAR_HPP

#include <memory>
#include <iostream>
#include <cstring> // for strcpy, strlen

using namespace std;

class Car {
private:
    char* brand;
    int year;

public:
    // Constructor
    Car(const char* brandName, int y) : year(y) {
        brand = new char[strlen(brandName) + 1];
        strcpy(brand, brandName);
    }

    // TODO: Implement a copy constructor here
    //Copy constructor (Deep Copy)
    Car(const Car& otherCar){
        brand = new char[strlen(otherCar.brand) + 1];
        strcpy(brand, otherCar.brand);
        year = otherCar.year;
    }

    // Destructor
    ~Car() {
        delete[] brand;
    }

    void showInfo() const {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }

    void setBrand(const char* newBrand) {
        delete[] brand;
        brand = new char[strlen(newBrand) + 1];
        strcpy(brand, newBrand);
    }

    void setYear(const int newY) {
        year = newY;
    }
};

#endif // CAR_HPP