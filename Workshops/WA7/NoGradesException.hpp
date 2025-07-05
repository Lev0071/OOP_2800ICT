#ifndef NOGRADES_EXCEPTION_HPP
#define NOGRADES_EXCEPTION_HPP

#include <iostream>                             /*(1)*/
#include <stdexcept>                            /*(2)*/
#include <string>   
#include <exception>
#include <string>
using namespace std;

class NoGradesException: public exception{
    private:
        string message;
    public:
        NoGradesException(const string& msg):message(msg){}
        // Override what() to return the custom message  
        virtual const char* what() const noexcept override{
            return message.c_str();
        }
};

#endif
