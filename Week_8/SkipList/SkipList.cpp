#include "SkipList.hpp"

SkipList::SkipList(int maxLevel,float p){
    MAXLVL = maxLevel;
    P=p;
    level=0;

    // Create header node with dummy key -1 and maximum level
    header = make_shared<Node>(-1,MAXLVL);
}

SkipList::~SkipList(){cout << "skip list destroyed.\n";}