#include <iostream>
#include <vector>
#include <memory>
#include <cstring> // memset
#include <cstdlib> // rand
#include <climits>
#include <ctime>
#include <string>

using namespace std;

template<typename T,typename U>
class Node
{
private:
    T key; // key
    U value; // Value

public:
    vector<shared_ptr<Node<T, U>>> forward;

    Node(T k,U val, int level) : key(k), value(val),forward(level + 1, nullptr) {}

    T getKey() const { return key; }
    U getValue() const { return value; }

    ~Node()
    {
        cout << "Node(key: " << key << " ,value: " << value << ")"<< " destroyed.\n";
    }
};

template<typename T,typename U>
class SkipList
{
private:
    int MAXLVL; // Maximum level of the skip list
    float P;    // Probability of node promotion to higher levels (typically 0.5).
    int level;
    shared_ptr<Node<T, U>> header;

public:
    SkipList(int, float);
    U searchElement (T) const;
    void insertElement(T,U);
    bool deleteElement(T);
    void displayList() const;
    int randomLevel();
    ~SkipList()
    {
        cout << "skip list destroyed.\n";
    }
};

template<typename T, typename U>
SkipList<T, U>::SkipList(int MAXLVL, float P) : MAXLVL(MAXLVL), P(P), level(0)
{
    header = make_shared<Node<T, U>>(INT_MIN,U{}, MAXLVL);
}

template<typename T, typename U>
int SkipList<T, U>::randomLevel()
{
    // rand() generates an integer in the range [0, RAND_MAX]
    float r = (float)rand() / RAND_MAX;
    int lvl = 0;
    while (r < P && lvl < MAXLVL)
    {
        lvl++;
        r = (float)rand() / RAND_MAX;
    }
    return lvl;
}

template<typename T, typename U>
U SkipList<T, U>::searchElement  (T key) const{
    auto current = header;
    cout << "Search Path:" << endl;
    for (int i = level; i >= 0; i--)
    {
        while (current->forward[i] && current->forward[i]->getKey() < key)
        {
            current = current->forward[i];
        }
    }
    current = current->forward[0];

    return (current && current->getKey() == key)? current->getValue():"NOT FOUND";
}

template<typename T, typename U>
void SkipList<T, U>::insertElement(T key, U value)
{
    auto current = header;
    vector<shared_ptr<Node<T, U>>> update(MAXLVL + 1, nullptr);
    for (int i = level; i >= 0; i--)
    {
        while (current->forward[i] && current->forward[i]->getKey() < key)
        {
            current = current->forward[i];
        }
        update[i] = current;
    }
    current = current->forward[0];
    if (!current || current->getKey() != key)
    {
        int rlevel = randomLevel();
        if (rlevel > level)
        {
            for (int i = level + 1; i <= rlevel; i++)
            {
                update[i] = header;
            }
            level = rlevel;
        }
        auto n = make_shared<Node<T,U>>(key, value, rlevel);
        for (int i = 0; i <= rlevel; i++)
        {
            n->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = n;
        }
        cout << "Successfully Inserted key " << key << "\n";
    }
}

template<typename T, typename U>
bool SkipList<T, U>::deleteElement(T key)
{
    auto current = header;
    vector<shared_ptr<Node<T, U>>> update(MAXLVL + 1, nullptr);
    for (int i = level; i >= 0; i--)
    {
        while (current->forward[i] && current->forward[i]->getKey() < key)
        {
            current = current->forward[i];
        }
        update[i] = current;
    }
    current = current->forward[0];

    if (current && current->getKey() == key)
    {
        for (int i = 0; i <= level; i++)
        {
            if (update[i]->forward[i] != current)
                break;
            update[i]->forward[i] = current->forward[i];
        }
        while (level > 0 && !header->forward[level])
        {
            level--;
        }
        cout << "Successfully deleted key " << key << "\n";
        return true;
    }
    return false;
}

template<typename T, typename U>
void SkipList<T, U>::displayList() const {
    for (int i = level; i >= 0; i--) {
        auto node = header;
        cout << "L" << i << ": ";
        while (node) {
            if (node == header)
                cout << "Hd";
            else
                cout << "-> (K: " << node->getKey() << " : V: " << node->getValue();
            if (node->forward[i])
                cout << " ── ";
            node = node->forward[i];
        }
        cout << "\n";
    }
}

class LogSystem{
    private:
        //SkipList<int,string> logs; 
        SkipList<int,string> logs{6, 0.5};

    public:
        //LogSystem() : logs(6, 0.5) {}
        void insert(int timestamp,const string& message){logs.insertElement(timestamp,message);}
        string search(int timestamp){ return logs.searchElement(timestamp); }
        bool remove(int timestamp){ return logs.deleteElement(timestamp); }
        void display(){logs.displayList();}
};


int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    LogSystem logSys;
    logSys.insert(1620000001, "System started");
    logSys.insert(1620000012, "User logged in");
    logSys.insert(1620000020, "Error detected");

    cout << "Search 1620000012: " << logSys.search(1620000012) << "\n";
    cout << "Search 1620000999: " << logSys.search(1620000999) << "\n";
    cout << "Search 1620000020: " << logSys.search(1620000999) << "\n";


    logSys.display();

    cout << "Remove 1620000020: " << (logSys.remove(1620000020) ? "Deleted" : "Not Found") << "\n";
    logSys.display();

    return 0;
}

// g++ -std=c++17 skip_list_.cpp -o PS9
// chcp 65001