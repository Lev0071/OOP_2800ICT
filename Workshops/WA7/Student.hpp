#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include "NoGradesException.hpp"

using namespace std;

class Student{
    private:
        string name;
        vector<double> grades;
    public:
        Student(string nm):name(nm){}

        void addGrade(double grade){
            if(grade <0 || grade > 100){
                throw invalid_argument("Invalid grade. Must be between 0.0 and 100.0");
            }else{
                grades.push_back(grade);
            }
        }

        double averageGrade() const {
            if(!hasGrades()){
                ostringstream oss;
                oss << name << ": No grades available.";
                string message = oss.str();
                throw NoGradesException(message);
            } else {
                return (accumulate(grades.begin(), grades.end(), 0.0))/grades.size();
            }
        }

        string getName() const {return name;}

        bool hasGrades() const { return !grades.empty();}

        //~Student(){ cout << "Student: " << name << "removed from record..." << endl;}
};