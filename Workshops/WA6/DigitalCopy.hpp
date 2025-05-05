//DigitalCopy.hpp
#ifndef DIGITALCOPY_H
#define DIGITALCOPY_H

#include <iostream>
using namespace std;

class DigitalCopy{
	protected:
		double size;
	public:
		DigitalCopy(double size=0){this->size=size;}
		virtual void showDownloadDetails() const{}
};
#endif // DIGITALCOPY_H

// Output 1: Title: CODE, Year: 2000, Author: Charles Petzold, Pages: 400
// Output 2: Title: Inception, Year: 2010, Size: 1000 MB, Director: Christopher Nolan, Duration: 148 min
// Output 3: Title: Thriller, Year: 1982, Size: 20 MB, Artist: Michael Jackson, Tracks: 9