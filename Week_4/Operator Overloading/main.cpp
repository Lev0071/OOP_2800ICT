// main.cpp
#include <iostream>
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

 #include "RectangleNonTemplate.hpp" // g++ main.cpp RectangleNonTemplate.cpp -o main // g++ -std=c++2b main.cpp RectangleNonTemplate.cpp -o main
// #include "RectangleHeaderOnly.hpp" // g++ main.cpp -o main // g++ -std=c++2b main.cpp -o main
// #include "RectangleWithTpp.hpp" // g++ -std=c++2b main.cpp -o main

using namespace std;

int main(){
    cout<<"Creating rectanle<double>(5.4,9.3)"<<endl;
    //Rectangle<float> rect_1(5.4,9.3); // will not work with RectangleNonTemplate.hpp, a concrete class
    Rectangle rect_1(5.4,9.3);

    cout<<"Creating rectanle<double>(15.7,23.9)"<<endl;
    //Rectangle<double> rect_2(15.7,23.9); // will not work with RectangleNonTemplate.hpp, a concrete class
    Rectangle rect_2(15.7,23.9);

    cout<<"Displaying Rectangles"<<endl;
    cout<<rect_1<<endl;
    cout<<rect_2<<endl;

    cout<<boolalpha;
    cout<<"Area comparison:"<<endl;
    cout<<"rect_1 == rect_2 ? "<<(rect_1 == rect_2)<<endl;
    cout<<"rect_1 > rect_2 ?  "<<(rect_1 > rect_2)<<endl;
    cout<<"rect_1 < rect_2 ?  "<<(rect_1 < rect_2)<<endl;
    cout<<"rect_1 + rect_2 ?  "<<(rect_1 + rect_2)<<endl;
    cout<<"rect_1 - rect_2 ?  "<<(rect_1 - rect_2)<<endl;
    cout<<"rect_1 * rect_2 ?  "<<(rect_1 * rect_2)<<endl;
    cout<<"rect_1 / rect_2 ?  "<<(rect_1 / rect_2)<<endl;

    cout<<"\nEnd of Program\n";
    return 0;
}