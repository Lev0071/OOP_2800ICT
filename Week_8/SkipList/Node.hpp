#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Node {
private:
    int key;

public:
    vector<shared_ptr<Node>> forward;

    Node(int k, int level) : key(k), forward(level + 1, nullptr) {}

    int getKey() const { return key; }

    ~Node() {
        cout << "key " << key << " destroyed.\n";
    }
};