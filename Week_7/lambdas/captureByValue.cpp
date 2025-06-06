#include <iostream>

int main()
{
    int x = 5;
    int y = 3;

    auto add = [x, y]() {
        return x + y; // captures x and y by value (copied)
    };

    std::cout << "Result of addition: " << add() << std::endl;

    auto subtract = [&x, &y]() {
        return x - y; // captures x and y by reference (live link)
    };

    std::cout << "Result of subtraction: " << subtract() << std::endl;

    x = 10;
    y = 2;

    std::cout << "Updated result of addition: " << add() << std::endl;
    std::cout << "Updated result of subtraction: " << subtract() << std::endl;

    return 0;
}

/*
Output:
Result of addition: 8            // uses captured values (5 + 3)
Result of subtraction: 2         // uses actual variables (5 - 3)
Updated result of addition: 8    // still uses old values (5 + 3)
Updated result of subtraction: 8 // uses new values (10 - 2)
*/
 