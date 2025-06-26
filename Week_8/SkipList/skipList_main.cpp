#include "SkipList.hpp"

int main(){
    SkipList list(6,0.5f);  // MAXLVL = 6, P = 0.5
    cout << "Skip list initialised.\n";

    return 0;
}

// g++ -std=c++17 skipList_main.cpp SkipList.cpp -o skiplist
