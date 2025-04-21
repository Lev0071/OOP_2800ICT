// main.cpp

#include <iostream>
using namespace std;
/*
✅ Summary Table
----------------------------------------------------------------------------------------------------------------------------
| Include Line in main.cpp                  | Files Needed                            | Extra Notes                        |
|-------------------------------------------|-----------------------------------------|------------------------------------|
| #include "Rectangle.hpp" (non-template)   | Rectangle.hpp + Rectangle.cpp           | Must use plain Rectangle           |
| #include "RectangleHeaderOnly.hpp"        | RectangleHeaderOnly.hpp                 | Templates; header-only             |
| #include "Rectangle.hpp" (with .tpp)      | Rectangle.hpp + Rectangle.tpp           | Templates; header + tpp            |
----------------------------------------------------------------------------------------------------------------------------
*/
// Uncomment one of the following based on which version to tesst

 #include "RectangleNonTemplate.hpp" // g++ -std=c++2b main.cpp RectangleNonTemplate.cpp -o main
// #include "RectangleHeaderOnly.hpp" // g++ -std=c++2b main.cpp -o main
// #include "RectangleWithTpp.hpp" // g++ -std=c++2b main.cpp -o main

int main(){
	// cout << "Creating rectangle..." << endl;

	#ifdef USE_TEMPLATE
		cout<<"Creating rectanle<double>(5.4,9.3)"<<endl;
		Rectangle<float> rect_1(5.4,9.3,"Rectangle_1");
		cout<<"Creating rectanle<double>(15.7,23.9)"<<endl;
		Rectangle<double> rect_2(15.7,23.9,"Rectangle_2");
	#elif defined(USE_NON_TEMPLATE)
		cout<<"Creating rectanle<double>(5.4,9.3)"<<endl;
		Rectangle rect_1(5.4,9.3,"Rectangle_1");
		cout<<"Creating rectanle<double>(15.7,23.9)"<<endl;
		Rectangle rect_2(15.7,23.9,"Rectangle_2");
	#else
		#error "No rectangle type defined!"
	#endif

	cout<<"Displaying Rectangles"<<endl;
    cout<<rect_1<<endl;
    cout<<rect_2<<endl;

    cout<<boolalpha; // stream manipulator that tells the stream to print bool values as true/false rahter than 1/0

    cout<<"Area Comparison:"<<endl;
    cout<<"rect_1 == rect_2 ? " << (rect_1 == rect_2) << endl;
    cout<<"rect_1 > rect_2 ? " << (rect_1 > rect_2) << endl;
    cout<<"rect_1 < rect_2 ? " << (rect_1 < rect_2) << endl;
    cout<<"rect_1 + rect_2 ? " << (rect_1 + rect_2) << endl;
    cout<<"rect_1 - rect_2 ? " << (rect_1 - rect_2) << endl;
    cout<<"rect_1 * rect_2 ? " << (rect_1 * rect_2) << endl;
    cout<<"rect_1 / rect_2 ? " << (rect_1 == rect_2) << endl;

    cout<<"\n End of Program \n";
    return 0;
}

/*
✅ Compile Commands for Each Version
-------------------------------------

// 🧱 Non-template Rectangle (RectangleNonTemplate.hpp + .cpp)
g++ -std=c++2b main.cpp RectangleNonTemplate.cpp -o main

// 📦 Template Header-Only (RectangleHeaderOnly.hpp only)
g++ -std=c++2b main.cpp -o main

// ⚙️ Template with TPP (RectangleWithTpp.hpp + RectangleWithTpp.tpp)
// Make sure RectangleWithTpp.hpp includes: #include "RectangleWithTpp.tpp"
g++ -std=c++2b main.cpp -o main

*/