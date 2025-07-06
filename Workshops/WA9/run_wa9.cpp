#include <iostream>
#include <vector>
#include <memory>
#include <cstring>
#include <cstdlib> 
#include <climits>
#include <ctime>
#include <string>

using namespace std;



template <typename K, typename V>
class Node {
private:
    K key;
    V value;
public:
    vector<shared_ptr<Node<K, V>>> forward;

    Node(K k, V v, int level) : key(k), value(v),forward(level + 1, nullptr) {}

    K getKey() const { return key; }
    V getValue() const {return value; }
    void setValue(const V& val) { value = val; }
};

template <typename K, typename V>
class SkipList {
private:
    int MAXLVL;
    float P;
    int level;
    shared_ptr<Node<K, V>> header;

public:
    SkipList(int=5, float=0.5f);
    bool searchElement(K, V&) const;
    void insertElement(K, V, int rlevel = -1);
    bool deleteElement(K);
    void displayList() const;
    void displayList_2() const;
    int randomLevel();
    vector<pair<K, V>> rangeQuery(K low, K high) const;

};

template <typename K, typename V>
void SkipList<K, V>::displayList_2() const {
    for (int i = level; i >= 0; i--) {
        auto node = header;
        cout << "L" << i << ": ";
        while (node) {
            if (node == header)
                cout << "Hd" << "-> (K: " << node->getKey() << " : V: " << node->getValue() << ")";
            else
                cout << "-> (K: " << node->getKey() << " : V: " << node->getValue()<< ")";
            if (node->forward[i])
                cout << " ── ";
            node = node->forward[i];
        }
        cout << "\n";
    }
}

template <typename K, typename V>
vector<pair<K, V>> SkipList<K, V>::rangeQuery(K low, K high) const{
    vector<pair<K, V>> results;
    auto current = header;
    for (int i = level; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->getKey() <low) {
            current = current->forward[i];
        }
    }
    current = current->forward[0];
    while (current && current->getKey() <=high) {
            results.emplace_back(current->getKey(),current->getValue());
            // better than results.push_back(make_pair{current->forward[i]->getKey(),current->forward[i]->getValue()})
            current = current->forward[0];
        }
    return results;
}

template <typename K, typename V>
SkipList<K, V>::SkipList(int MAXLVL, float P) : MAXLVL(MAXLVL), P(P), level(0) {
    header = make_shared<Node<K, V>>(K(), V(), MAXLVL);
}

template <typename K, typename V>
int SkipList<K, V>::randomLevel() {
    float r = (float)rand() / RAND_MAX;
    int lvl = 0;
    while (r < P && lvl < MAXLVL) {
        lvl++;
        r = (float)rand() / RAND_MAX;
    }
    return lvl;
}

template <typename K, typename V>
bool SkipList<K, V>::searchElement(K key, V& value) const {
    auto current = header;
    for (int i = level; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->getKey() < key) {
            current = current->forward[i];
        }
    }
    current = current->forward[0];
    if (current && current->getKey() == key) {
        value = current->getValue();
        return true;
    }
    return false;
}

template <typename K, typename V>
void SkipList<K, V>::insertElement(K key, V value, int rlevel) {
    auto current = header;
    vector<shared_ptr<Node<K, V>>> update(MAXLVL + 1, nullptr);

    for (int i = level; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->getKey() < key) {
            current = current->forward[i];
        }
        update[i] = current;
    }
    current = current->forward[0];
    if (current && current->getKey() == key) {
        current->setValue(value); 
        return;
    }

    if (rlevel == -1) {
        rlevel = randomLevel();
    }
    
    if (rlevel > level) {
        for (int i = level + 1; i <= rlevel; i++) {
            update[i] = header;
        }
        level = rlevel;
    }
    auto n = make_shared<Node<K, V>>(key, value, rlevel);
    for (int i = 0; i <= rlevel; i++) {
        n->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = n;
    }
    // cout << "Successfully Inserted key " << key << "\n";
}

template <typename K, typename V>
bool SkipList<K, V>::deleteElement(K key) {
    auto current = header;
    vector<shared_ptr<Node<K, V>>> update(MAXLVL + 1, nullptr);
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
        // cout << "Successfully deleted key " << key << "\n";
        return true;
    }
    return false;
}

template <typename K, typename V>
void SkipList<K, V>::displayList() const {
    auto node = header->forward[0];
    while (node) {
        cout << "(" << node->getKey() << ": " << node->getValue() << ")\n";
        node = node->forward[0];
    }
}



// Main for testing rangeQuery

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    SkipList<int, string> skipList;
    //skipList.displayList_2();
    skipList.insertElement(1, "Banana_0");
    skipList.insertElement(5, "Apple");
    skipList.insertElement(7, "Apple_1");
    skipList.insertElement(10, "Banana_1");
    skipList.insertElement(20, "Date");
    skipList.insertElement(23, "Elderberry");
    skipList.insertElement(15, "Cherry");
    skipList.insertElement(25, "Elderberry_1");
    skipList.insertElement(30, "Fig");
    skipList.insertElement(60, "Fig_1");
    //---------------------------------------------
    // skipList.insertElement(1, "Banana_0", 1);
    // skipList.displayList_2();
    // skipList.insertElement(5, "Apple", 2);
    // skipList.insertElement(7, "Apple_1", 1);
    // skipList.insertElement(10, "Banana_1", 2);
    // skipList.insertElement(20, "Date", 3);
    // skipList.insertElement(23, "Elderberry", 2);
    // skipList.insertElement(15, "Cherry", 1);
    // skipList.insertElement(25, "Elderberry_1", 2);
    // skipList.insertElement(30, "Fig", 1);
    // skipList.insertElement(60, "Fig_1", 3);

    cout << "\nFull SkipList:\n";
    skipList.displayList();
    //skipList.displayList_2();

    cout << "\nRange Query [25, 60]:\n";
    auto results = skipList.rangeQuery(25, 60);
    for (const auto& [k, v] : results) {
        cout << k << " => " << v << endl;
    }

    return 0;
}

// chcp 65001
// g++ -std=c++17  run_wa9.cpp -o wa9