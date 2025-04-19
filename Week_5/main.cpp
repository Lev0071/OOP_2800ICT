#include "Triangle.h"
#include <iostream>
#include <memory>
using namespace std;

int main(){
    // 1. default constructor
    Triangle t1;
    cout << "1. default constructor" << endl;
    cout << "t1: " << t1 << endl;
    cout << "\n\n";

    // 2. parameterized constructor
    Triangle t2(1.1, 2.2, 3.3, 4.4, 5.5, 6.6);
    cout << "2. parameterized constructor" << endl;
    cout << "t2: " << t2 << endl;
    cout << "\n\n";

    // 3. Copy t2 into t3 using the copy constructor
    Triangle t3 = t2; // Triangle t3(t2);
    cout << "3. Copy t2 into t3 using the copy constructor" << endl;
    cout << "t3: " << t3 << endl;
    cout << "\n\n";

    // 4. Move t2 into t4 using the move constructor
    cout << "4. Move t2 into t4 using the move constructor" << endl;
    cout << "Before the move" << endl;
    cout << "t2: " << t2 << endl;
    Triangle t4 = move(t2);
    cout << "t2 (after move, possibly in a 'moved-from' state): " << t2 << endl;
    cout << "t2: " << t2 << endl;
    cout << "t4: " << t4 << endl;
    cout << "\n\n";

    //5. Assign t3 into t5 using the copy assignment operator
    Triangle t5;
    t5 = t3;
    cout << "5. Assign t3 into t5 using the copy assignment operator" << endl;
    cout << "t3: " << t3 << endl;
    cout << "t5: " << t5 << endl;
    cout << "\n\n";

    //6. Move t4 into t6 using the move assignment operator
    Triangle t6;
    t6 = move(t4);
    cout << "6. Move t4 into t6 using the move assignment operator" << endl;
    cout << "t2: " << t2 << endl;
    cout << "t4: " << t4 << endl;
    cout << "\n\n";

    //7. Use the setter methods to modify t1
    cout << "7. Use the setter methods to modify t1" << endl;
    cout << "Before changes to t1" << endl;
    cout << "t1: " << t1 << endl;   
    t1.setside1(9.9);
    t1.setside2(8.8);
    t1.setside3(7.7);
    cout << "After changes to t1" << endl;
    cout << "t1: " << t1 << endl;
    cout << "\n\n";

    //  8. Use setsides() to modify t5 in one line
    cout << "8. Use setsides() to modify t5 in one line" << endl;
    cout << "Before changes to t5" << endl;
    cout << "t5: " << t5 << endl;
    t5.setsides(30,20,10);
    cout << "After changes to t5" << endl;
    cout << "t5: " << t5 << endl;
    cout << "\n\n";

    // 9. Use setx(), sety(), setz() to update the pointer values of a Triangle object
    cout << "9. Use setx(), sety(), setz() to update the pointer values of a Triangle object" << endl;
    cout << "Before pointer updates to t1" << endl;
    cout << "t1: " << t1 << endl;

    t1.setx(99.9);
    t1.sety(88.8);
    t1.setz(77.7);

    cout << "After pointer updates to t1" << endl;
    cout << "t1: " << t1 << endl;
    cout << "\n\n";
}

// g++ -std=c++2b main.cpp Triangle.cpp -o week5Tri
// ./week5Tri