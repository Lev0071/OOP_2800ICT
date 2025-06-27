#include "SkipList.hpp"

SkipList::SkipList(int maxLevel,float p){
    MAXLVL = maxLevel;
    P=p;
    level=0;

    // Create header node with dummy key -1 and maximum level
    header = make_shared<Node>(-1,MAXLVL);
}

SkipList::~SkipList(){cout << "skip list destroyed.\n";}

void SkipList::insertElementFixedLevel(int key, int fixedLevel) {
    auto current = header;
    vector<shared_ptr<Node>> update(MAXLVL + 1, nullptr);

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->getKey() < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (!current || current->getKey() != key) {
        int rlevel = fixedLevel;

        if (rlevel > level) {
            for (int i = level + 1; i <= rlevel; i++) {
                update[i] = header;
            }
            level = rlevel;
        }

        auto n = make_shared<Node>(key, rlevel);
        for (int i = 0; i <= rlevel; i++) {
            n->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = n;
        }
    }
}

void SkipList::printAscii() const {
    for (int i = level; i >= 0; i--) {
        auto node = header;
        cout << "L" << i << ": ";
        while (node) {
            if (node == header)
                cout << "Hd";
            else
                cout << "-> " << node->getKey();
            if (node->forward[i])
                cout << " ── ";
            node = node->forward[i];
        }
        cout << "\n";
    }
}
