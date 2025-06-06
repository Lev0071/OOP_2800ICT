// thread_ref.cpp
#include <iostream>
#include <string>
#include <thread>
#include <functional> // for std::ref

/*
For multithreading with std::thread,
it's necessary to explicitly bind references using std::ref for parameter
passing;
otherwise, the reference declaration in the parameter is ineffective.
*/

void threadFunc(std::string &str, int &a) {
    str = "change by threadFunc";
    a = 13;
}

int main() {
    std::string str("main");
    int a = 9;

    // Direct call (reference works as expected)
    threadFunc(str, a);
    std::cout << "str = " << str << std::endl;
    std::cout << "a = " << a << std::endl;

    // Reset variables
    str = "main";
    a = 9;

    // Multithreaded call (use std::ref to pass by reference)
    std::thread th(threadFunc, std::ref(str), std::ref(a));
    th.join();

    std::cout << "str = " << str << std::endl;
    std::cout << "a = " << a << std::endl;

    return 0;
}
