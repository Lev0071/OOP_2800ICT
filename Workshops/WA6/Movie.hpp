//Movie.hpp
#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
using namespace std;
#include "MediaItem.hpp"
#include "DigitalCopy.hpp"

class Movie:public MediaItem,public DigitalCopy{
	private:
		string director;
		int duration;
	public:
		Movie(const string& title=" ",int releaseYear=0,const string& director=" ",int duration=0,double size=0):MediaItem(title,releaseYear),DigitalCopy(size),director(director),duration(duration){}
		void display() const override{showDownloadDetails();cout<< "Director: " << director << ", Duration: " << duration << " min";}
		
		void showDownloadDetails() const override{ cout << "Size: " << size << " MB, ";}
};
#endif // MOVIE_H

// Output 1: Title: CODE, Year: 2000, Author: Charles Petzold, Pages: 400
// Output 2: Title: Inception, Year: 2010, Size: 1000 MB, Director: Christopher Nolan, Duration: 148 min
// Output 3: Title: Thriller, Year: 1982, Size: 20 MB, Artist: Michael Jackson, Tracks: 9

//Movie(const string& title=" ",int releaseYear=0,const string& director=" ",int duration=0,double size=0):MediaItem(title,releaseYear),DigitalCopy(size){this->director=director,this->duration=duration}
