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
};