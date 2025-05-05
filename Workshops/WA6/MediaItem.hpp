//MediaItem.hpp
#ifndef MEDIAITEM_H
#define MEDIAITEM_H

#include <iostream>
#include <string>
using namespace std;

class MediaItem{
	private:
		string 	title;
		int 	releaseYear;
	public:
		MediaItem(const string& title=" ",int year=0):title(title),releaseYear(year){}
		virtual void display()const=0;
		//virtual void display(){cout << "Media Item ( title: " << title << " ,year: " << releaseYear << ")" << endl;}

		friend ostream &operator<<(ostream &out,const MediaItem &mem){out << "Title: " << mem.title << ", Year: " << mem.releaseYear << ", ";mem.display();return out;}
    };

#endif // MEDIAITEM_H