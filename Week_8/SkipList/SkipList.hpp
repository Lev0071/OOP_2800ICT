#include "Node.hpp"
#pragma once
class SkipList {
private:
    int MAXLVL;   // Maximum level of the skip list
    float P;      // Probability of node promotion to higher levels (typically 0.5)
    int level;    // Current level of skip list
    shared_ptr<Node> header;

public:
    SkipList(int, float);
    bool searchElement(int);
    void insertElement(int);
    void deleteElement(int);
    void displayList();
    int randomLevel();

    ~SkipList();
};