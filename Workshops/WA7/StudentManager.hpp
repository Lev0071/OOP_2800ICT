#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <iomanip>  // for std::setprecision


#include "Student.hpp"
using namespace  std;

bool isZero(const pair<Student,double>& avGrade) {
    return avGrade.second == 0.0;
}

bool topGradesFirst(const pair<Student,double>& a,const pair<Student,double>& b){
    return a.second > b.second;
}

class StudentManager{
    private:
        vector<Student> students;
    public:
        StudentManager():students() {}
        void operator()() const {
            cout << "Student Management System" << endl;
            if(students.empty()){
                cout << "None." << endl;
            }else{
                for(auto student:students){
                if(student.hasGrades()){
                    cout << student.getName() << " : " << fixed << setprecision(2) << student.averageGrade() << endl;
                }else{
                    cout << student.getName() << " : " << "No grades available" << endl;
                }
            }
            }
        } 

        void addStudent(const Student& student){students.push_back(student);}
        void filterFailingStudents() const {
            int failCount = 0;
            cout << "Failing students:" << endl;
            for(const Student& student : students){
                if(student.hasGrades() && student.averageGrade()<50.0){
                    cout << " - " << student.getName() << endl;
                    failCount++; 
                }
            }
            if(failCount == 0){
                cout << "None" << endl;
            }
        }

        void printTopStudents(int n) const {
            vector<pair<Student,double>> averages;
            for(const Student& student:students){
                if (student.hasGrades()){
                    averages.push_back(make_pair(student,student.averageGrade()));
                }
            }
            auto removeEnd = remove_if(averages.begin(), averages.end(), isZero);
            averages.erase(removeEnd,averages.end());
            sort(averages.begin(), averages.end(), topGradesFirst);

            if(averages.empty()){
                cout << "None." << endl;
            }else{
                for(auto it = averages.begin(); it != averages.end() && it != averages.begin() + n; ++it){
                    cout << it->first.getName() << " : " << fixed << setprecision(2) << it->second << endl;
                }
            }
        };
};