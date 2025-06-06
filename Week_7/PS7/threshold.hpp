#ifndef THRESHOLD_H
#define THRESHOLD_H

#include <string>
#include <exception>
using namespace std; 

class LowStockChecker{
	private:
		int threshold;
	public:
		LowStockChecker(int th):threshold(th){}

		bool operator()(const Book& book)const{
			return book.getStock() < threshold;
		}

};

#endif // THRESHOLD_H