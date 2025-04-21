// mainRectangle_IN.cpp 
#include <iostream> 
#include <string>
#include "Rectangle_IN.hpp" 
using namespace std; 

int main(){
	Rectangle rec1;
	Rectangle rec2;

	rec1.setName("Rectangle 1");
	rec2.setName("Rectangle 2");
	
	cout << "Rectangle 1" << "\n";
	cout << "Name:  " << rec1.getName() <<"\n";
	cout << "Width:  " << rec1.getWidth() <<"\n";
	cout << "Length:  " << rec1.getLength() <<"\n";
	cout << "Area:  " << rec1.getArea() <<"\n";
	cout << "\n\n";
	cout << "Rectangle 1" << "\n";
	cout << "Name:  " << rec1.getName() <<"\n";
	cout << "Width:  " << rec2.getWidth() <<"\n";
	cout << "Length:  " << rec2.getLength() <<"\n";
	cout << "Area:  " << rec2.getArea() <<"\n";
	cout << "\n\n";

	cout << "After setting Reactangle 1 and Reactangle 2" << "\n"; 
	
	rec1.setWidth(5);
	rec1.setLength(10);
	
	rec2.setWidth(15);
	rec2.setLength(20);

	cout << "Rectangle 1" << "\n";
	cout << "Width:  " << rec1.getWidth() <<"\n";
	cout << "Length:  " << rec1.getLength() <<"\n";
	cout << "Area:  " << rec1.getArea() <<"\n";
	cout << "\n\n";
	cout << "Rectangle 1" << "\n";
	cout << "Width:  " << rec2.getWidth() <<"\n";
	cout << "Length:  " << rec2.getLength() <<"\n";
	cout << "Area:  " << rec2.getArea() <<"\n";
	cout << "\n\n";

	return 0;
}



// g++ -std=c++2b mainRectangle_IN.cpp -o mainRectangle_IN
// ./mainRectangle_IN