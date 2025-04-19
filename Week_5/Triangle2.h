#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include <memory>
using namespace std;

class Triangle {
private:
    shared_ptr<double> x = make_shared<double>(0.0);
    shared_ptr<double> y = make_shared<double>(0.0);
    shared_ptr<double> z = make_shared<double>(0.0);
    double side1, side2, side3;

public:
    Triangle(); // default constructor
    Triangle(double x, double y, double z, double s1, double s2, double s3); // parameterized constructor
    Triangle(const Triangle &other); // copy constructor
    Triangle(Triangle &&other); // move constructor

    Triangle &operator=(const Triangle &other); // copy assignment
    Triangle &operator=(Triangle &&other); // move assignment

    void setx(double x);
    void sety(double y);
    void setz(double z);
    void setside1(double s1);
    void setside2(double s2);
    void setside3(double s3);
    void setsides(double s1, double s2, double s3);

    friend ostream &operator<<(ostream &out, const Triangle &InputObj);
};

#endif // TRIANGLE_H
