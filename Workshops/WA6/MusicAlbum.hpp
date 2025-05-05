//MusicAlbum.hpp
#ifndef MUSICALBUM_H
#define MUSICALBUM_H

#include <iostream>
using namespace std;
#include "MediaItem.hpp"
#include "DigitalCopy.hpp"

class MusicAlbum:public MediaItem,public DigitalCopy{
	private:
		string artist;
		int trackCount;
	public:
		MusicAlbum(const string& title=" ",int releaseYear=0,const string& artist=" ",double trackCount=0,int size=0):MediaItem(title,releaseYear),DigitalCopy(size),artist(artist),trackCount(trackCount){}
		void display() const override{showDownloadDetails();cout << "Artist: " << artist << ", Tracks: " << trackCount << endl;}
		
		void showDownloadDetails() const override{ cout << "Size: " << size << " MB, ";}
};
#endif // MUSICALBUM_H

// Output 1: Title: CODE, Year: 2000, Author: Charles Petzold, Pages: 400
// Output 2: Title: Inception, Year: 2010, Size: 1000 MB, Director: Christopher Nolan, Duration: 148 min
// Output 3: Title: Thriller, Year: 1982, Size: 20 MB, Artist: Michael Jackson, Tracks: 9

//Movie(const string& title=" ",int releaseYear=0,const string& director=" ",int duration=0,double size=0):MediaItem(title,releaseYear),DigitalCopy(size){this->director=director,this->duration=duration}

