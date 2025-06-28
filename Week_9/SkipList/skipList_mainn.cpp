#include "SkipList.hpp"
using namespace std;

int main(){
    SkipList list(6, 0.5f);

    list.insertElement(10);
    list.insertElement(20);
    list.insertElement(30);
    list.insertElement(50);

    list.printAscii();   

    cout << "Search 20: " << (list.searchElement(20) ? "Found" : "Not Found") << endl;
    cout << "Search 40: " << (list.searchElement(40) ? "Found" : "Not Found") << endl;

    list.deleteElement(20);
    list.printAscii(); 

    list.deleteElement(50);
    list.printAscii();

    list.insertElement(5);
    list.printAscii();



}

// g++ -std=c++17 skipList_mainn.cpp SkipList.cpp -o skiplist
