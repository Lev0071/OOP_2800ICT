#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <stdexcept>

#include "exceptions.hpp"
using namespace std; 

class Book;  // ✅ Add this line before approveSale declaration
void approveSale(int quantity, const Book& book);
void approveRestock(int quantity);


class Book{
private:
	string title;
	string author;
	int stock;
public:
	Book();
	Book(string tit, string auth, int st):title(tit),author(auth),stock(st){}
	//Book(const )

	//Methods
	int getStock() const {return stock;}
	string getTitle() const {return title;}
	void setTitle(string t){title=t;}
	string getAuthor() const {return author;}
	void setAuthor(string a){author=a;}
	void setStock(int s){stock=s;}
	~Book(){ cout << "Destructor called for "<< title << " object!..Check with management if this is a discontinued product" << endl;}
	void sell(int quantity){
		try{
			approveSale(quantity,*this);
			stock -= quantity;;
		}catch(const exception &e){ // or catch(const OutOfStockException &e) but "invalid_argument" will be an issue
			cerr << e.what() << endl;
		}
	}
	void restock(int quantity){
		try{
			approveRestock(quantity);
			stock += quantity;
		} catch(const exception &e){
        cerr << e.what() << endl;
    	}
	}
};

void approveSale(int quantity, const Book& book) {
    if (quantity <= 0) {
        if (book.getStock() <= 0) {
            throw OutOfStockException(book.getTitle());
        } else {
            throw invalid_argument("Invalid quantity entered.");
        }
    } else if (quantity > book.getStock()) {
        throw OutOfStockException(book.getTitle());
    }
}

void approveRestock(int quantity){
	if(quantity <= 0){throw invalid_argument("Invalid restock quantity");}
}

#endif // BOOK_H