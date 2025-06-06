#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <stdexcept>
using namespace std; 

void approveSale(int quantity);
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

Book Class
----------
Members:
- title
- author
- stock

Methods:
- Constructor
- sell(int quantity): throws std::invalid_argument if quantity <= 0, throws OutOfStockException if quantity > stock
- restock(int quantity): throws std::invalid_argument if quantity <= 0
- getStock(): returns current stock
- getTitle(): returns book title
- Destructor: prints a message for debugging (stack unwinding observation)


OutOfStockException Class
-------------------------
- Inherits from std::exception
- Constructor accepts book title and creates a custom error message
- Stores message in private std::string
- Overrides what() to return message as const char*


LowStockChecker Functor
-----------------------
- Constructor takes a stock threshold value
- operator()(Book): returns true if Book's stock is less than threshold


Inventory Class
---------------
- Stores: std::vector<Book>

Methods:
- addBook(Book): adds a book to the inventory
- sellBook(title, quantity): finds and sells book, handles exceptions if not found or stock insufficient
- restockBook(title, quantity): finds and restocks a book
- findBook(title, Book&): if found, copies book into provided reference and returns true, else returns false
- applyToAllBooks(function): applies a passed function (functor or lambda) to each book
- listLowStockBooks(threshold): prints books below a given stock threshold (not used in provided main)
