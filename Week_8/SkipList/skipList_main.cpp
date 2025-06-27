#include "SkipList.hpp"

int main(){
    // SkipList list(6,0.5f);  // MAXLVL = 6, P = 0.5
    // cout << "Skip list initialised.\n";

    // cout << "Height of the head is: " << list

    //########## TEST ##########
    SkipList list(2, 0.5f);

    // Manually insert keys with the levels shown in the diagram
    list.insertElementFixedLevel(5, 0);
    list.insertElementFixedLevel(25, 0);
    list.insertElementFixedLevel(30, 0);
    list.insertElementFixedLevel(31, 2);  // appears at L2, L1, L0
    list.insertElementFixedLevel(42, 0);
    list.insertElementFixedLevel(58, 0);
    list.insertElementFixedLevel(62, 0);
    list.insertElementFixedLevel(69, 2);  // appears at L2, L1, L0

    cout << "Skip list built:\n";
    list.printAscii();
    //########## TEST ##########

    return 0;
}

// g++ -std=c++17 skipList_main.cpp SkipList.cpp -o skiplist
