#include "SkipList.hpp"

int main(){

    //########## TEST ##########
    SkipList list(2, 0.5f);

    cout << "Skip list built:\n";
    list.printAscii();

    // Manually insert keys with the levels shown in the diagram
    list.insertElementFixedLevel(5, 0);
    list.insertElementFixedLevel(25, 0);
    list.insertElementFixedLevel(30, 0);
    list.insertElementFixedLevel(31, 2);  // appears at L2, L1, L0
    list.insertElementFixedLevel(42, 0);
    list.insertElementFixedLevel(58, 0);
    list.insertElementFixedLevel(62, 0);
    list.insertElementFixedLevel(69, 2);  // appears at L2, L1, L0

    list.insertElementFixedLevel_2(45);

    cout << "Skip list populated:\n";
    list.printAscii();
    //########## TEST ##########

    return 0;
}

// chcp 65001
// g++ -std=c++17 insertTest.cpp SkipList.cpp -o insertTest
