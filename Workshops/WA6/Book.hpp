//Book.hpp
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;
#include <string>
#include "MediaItem.hpp"

class Book:public MediaItem{
	private:
		string author;
		int pageCount;
	public:
		Book(const string& title=" ",int year=0,const string& author=" ",int page=0):MediaItem(title,year),author(author),pageCount(page){}
		void display() const override{ cout << "Author: " << author << ", Pages: " << pageCount;}
};

#endif // BOOK_H

// Output 1: Title: CODE, Year: 2000, Author: Charles Petzold, Pages: 400
// Output 2: Title: Inception, Year: 2010, Size: 1000 MB, Director: Christopher Nolan, Duration: 148 min
// Output 3: Title: Thriller, Year: 1982, Size: 20 MB, Artist: Michael Jackson, Tracks: 9

