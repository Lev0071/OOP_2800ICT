#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>
#include <exception>
using namespace std; 

class OutOfStockException:public exception{
	private:
		string message;
	public:
		OutOfStockException(const string& title):message("Out of stock for book: " + title){}
		const char* what() const noexcept override{
			return message.c_str();
		}

};

#endif // EXCEPTIONS_H

