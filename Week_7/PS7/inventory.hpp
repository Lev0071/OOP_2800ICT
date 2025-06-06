#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <exception>
#include "book.hpp"
#include "exceptions.hpp"

using namespace std; 

class Inventory{
	private:
		vector<Book> books;
	public:
		void addBook(const Book& book){books.push_back(book);}
		void addBook(string title, string author, int stock){
			Book book(title,author,stock);
			books.push_back(book);
		};
		void applyToAllBooks(function<void(Book&)> func){
			for(Book& book:books){
				func(book);
			}
		}
		bool findBook(string title, Book& book){
			for(Book& currentBook:books){
				if(currentBook.getTitle()==title){
					book.setTitle(title);
					book.setAuthor(currentBook.getAuthor());
					book.setStock(currentBook.getStock());
					return true;
				}
			}
			return false;
		}
		void sellBook(string title,int quantity){
			if(quantity <= 0)	throw invalid_argument("Invalid quantity Enterd/Passed");
			for(Book& currentBook:books){
				if(currentBook.getTitle() == title){
					if(currentBook.getStock()<quantity)	throw OutOfStockException(currentBook.getTitle());
					currentBook.setStock(currentBook.getStock()-quantity);
					return; 
				}
			}
			throw OutOfStockException(title);
		}
};
#endif // INVENTORY_H