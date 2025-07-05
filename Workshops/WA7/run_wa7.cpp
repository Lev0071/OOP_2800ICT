#include <iostream>

#include <iomanip>
#include "Student.hpp"
#include "StudentManager.hpp"
#include "NoGradesException.hpp"

// class NoGradesException; // Forward declaration
// class Student; // Forward declaration
// class StudentManager; // Forward declaration


// ---------- WARNING: Do not modify the main function! ----------
// ---------- WARNING: Do not modify the main function! ----------
// ---------- WARNING: Do not modify the main function! ----------
int main()
{
    Student alice("Alice");
    Student bob("Bob");
    Student charlie("Charlie");

    std::cout << "Output 1: \n";
    try
    {
        alice.addGrade(85.5);
        alice.addGrade(90.25);
        alice.addGrade(75.0);

        bob.addGrade(-10);
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what() << "\n";
    }

    try
    {
        std::cout << bob.averageGrade() << "\n";
    }
    catch (const NoGradesException &e)
    {
        std::cout << e.what() << "\n";
    }

    try
    {
        charlie.addGrade(30.4);
        charlie.addGrade(54.6);
    }
    catch (...)
    {
        std::cout << "Error adding grade to Charlie\n";
    }

    std::cout << "\nOutput 2: \n";
    StudentManager manager;
    manager();
    std::cout << std::setw(30) << std::setfill('-') << "\n";
    manager.filterFailingStudents();
    std::cout << std::setw(30) << std::setfill('-') << "\n";
    manager.printTopStudents(2);

    std::cout << "\nOutput 3: \n";
    Student kevin("Kevin");
    kevin.addGrade(50.0);
    kevin.addGrade(60.0);
    manager.addStudent(alice);
    manager.addStudent(bob);
    manager.addStudent(charlie);
    manager.addStudent(kevin);

    manager();
    std::cout << std::setw(30) << std::setfill('-') << "\n";
    manager.filterFailingStudents();
    std::cout << std::setw(30) << std::setfill('-') << "\n";
    manager.printTopStudents(2);

    return 0;
}
// ---------- WARNING: Do not modify the main function! ----------
// ---------- WARNING: Do not modify the main function! ----------
// ---------- WARNING: Do not modify the main function! ----------

// g++ -std=c++17  run_wa7.cpp -o WA7