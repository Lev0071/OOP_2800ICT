#include "SkipList.hpp"

SkipList::SkipList(int maxLevel,float p){
    MAXLVL = maxLevel;
    P=p;
    level=0;

    // Create header node with dummy key -1 and maximum level
    header = make_shared<Node>(-1,MAXLVL);
}

int SkipList::randomLevel() {
    float r = (float)rand() / RAND_MAX;  // 🔹 1. Flip the first coin
    int lvl = 0;

    while (r < P && lvl < MAXLVL) {      // 🔹 2. While coin is heads and below max
        lvl++;                           // 🔹 3. Promote to next level
        r = (float)rand() / RAND_MAX;    // 🔹 4. Flip again
    }

    return lvl;                          // 🔹 5. Return how high we got
}


SkipList::~SkipList(){cout << "skip list destroyed.\n";}

void SkipList::insertElement(int key) {
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
        int rlevel = randomLevel();

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

        cout << "Successfully Inserted key " << key << "\n";
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

//--------------------------------- TEST METHODS BELOW

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



void SkipList::insertElementFixedLevel_2(int key) {
    auto current = header;
    vector<shared_ptr<Node>> update(MAXLVL + 1, nullptr);

       for (int i = level; i >= 0; i--) { // <--*
        while (current->forward[i] && current->forward[i]->getKey() < key) {
            current = current->forward[i];
        }
        update[i] = current; // <--*
        //DEBUG ===============================================
        cout << "DEBUG - UPDATE ++++++++++++++++++ START\n";
        cout << "[debug] update[" << i << "] = ";
        if (update[i]) {
            cout << update[i]->getKey();
        } else {
            cout << "nullptr";
        }
        cout << "\nDEBUG - UPDATE ++++++++++++++++++ END";
        cout << "\n";
        //DEBUG ===============================================
    } // <--*

    current = current->forward[0];

    if (!current || current->getKey() != key) {
        int rlevel = 5;

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

        cout << "Successfully Inserted key " << key << "\n";
    }
}

bool SkipList::searchElement(int key) {
    auto current = header;

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->getKey() < key) {
            current = current->forward[i];
        }
    }

    current = current->forward[0];
    return current && current->getKey() == key;
}

void SkipList::deleteElement(int key) {
    auto current = header;
    vector<shared_ptr<Node>> update(MAXLVL + 1, nullptr);

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->getKey() < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (current && current->getKey() == key) {
        for (int i = 0; i <= level; i++) {
            if (update[i]->forward[i] != current)
                break;
            update[i]->forward[i] = current->forward[i];
        }

        while (level > 0 && !header->forward[level]) {
            level--;
        }

        cout << "Successfully deleted key " << key << "\n";
    }
}


