#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ctime>

using namespace std;


template <typename T>
class TreapNode
{
private:
    T key;
    int priority;
    shared_ptr<TreapNode<T>> left;
    shared_ptr<TreapNode<T>> right;

public:
    TreapNode() : key(T(0)), priority(rand() % 100), left(nullptr), right(nullptr) {}
    TreapNode(T key) : key(key), priority(rand() % 100), left(nullptr), right(nullptr) {}
    TreapNode(T key, int priority) : key(key), priority(priority%100), left(nullptr), right(nullptr) {}
    ~TreapNode()
    {
        cout << "Key " << key << " destroyed." << endl;
    }

    T getKey() const
    {
        return key;
    }

    int getPriority() const
    {
        return priority;
    }

    void right_rotation(shared_ptr<TreapNode<T>> &x)
    {
        auto y = x->left; // auto y = x-> left;

        auto g = y->right;
        auto b = x->right;

        x->left = g;
        y->right = x;

        x = y;
    }

    void left_rotation(shared_ptr<TreapNode<T>> &y)
    {
        auto x = y->right;

        auto g = x->left;
        auto b = x->right;

        x->left = y;
        y->right = g;

        y = x;
    }

    void insert(shared_ptr<TreapNode<T>> &root, T key)
    {
        if (!root)
        {
            root = make_shared<TreapNode<T>>(key);
            return;
        }

        insert(key <= root->key ? root->left : root->right, key);

        if (root->left && root->left->priority > root->priority)
        {
            right_rotation(root);
        }

        if (root->right && root->right->priority > root->priority)
        {
            left_rotation(root);
        }
    }

    void insert(shared_ptr<TreapNode<T>> &root, T key, int priority)
    {
        if (root == nullptr)
        {
            root = make_shared<TreapNode<T>>(key, priority);
            return;
        }

        // RECURSE with priority!
        if (key <= root->key)
            insert(root->left, key, priority);
        else
            insert(root->right, key, priority);

        if (root->left && root->left->priority > root->priority)
        {
            right_rotation(root);
        }

        if (root->right && root->right->priority > root->priority)
        {
            left_rotation(root);
        }
    }


    // void insert(shared_ptr<TreapNode<T>> &root, T key, int priority)
    // {
    //     if (root == nullptr)
    //     {
    //         root = make_shared<TreapNode<T>>(key, priority);
    //         return;
    //     }

    //     insert(key <= root->key ? root->left : root->right, key);

    //     if (root->left && root->left->priority > root->priority)
    //     {
    //         right_rotation(root);
    //     }

    //     if (root->right && root->right->priority > root->priority)
    //     {
    //         left_rotation(root);
    //     }
    // }

    bool remove(shared_ptr<TreapNode<T>> &root, T key)
    {
        if (!root)
        {
            return false;
        }

        if (key < root->key)
        {
            return remove(root->left, key);
        }
        if (key > root->key)
        {
            return remove(root->right, key);
        }

        if (!root->left && !root->right)
        {
            root.reset();
        }
        else if (!root->left || !root->right)
        {
            shared_ptr<TreapNode<T>> child = (root->left) ? root->left : root->right;
            root = child;
        }
        else
        {
            if (root->left->priority < root->right->priority)
            {
                left_rotation(root);
                remove(root->left, key);
            }
            else
            {
                right_rotation(root);
                remove(root->right, key);
            }
        }

        return true;
    }

    void split(shared_ptr<TreapNode<T>> &t, T key, shared_ptr<TreapNode<T>> &l, shared_ptr<TreapNode<T>> &r)
    {
        int inf = INT_MAX;

        insert(t, key, inf);

        l = t->left;
        r = t->right;
    }

    shared_ptr<TreapNode<T>> search(shared_ptr<TreapNode<T>> &root, T key)
    {
        if (!root || root->key == key)
        {
            return root;
        }
        if (root->key < key)
        {
            return search(root->right, key);
        }
        if (root->key > key)
        {
            return search(root->left, key);
        }
    }

    void heapify(shared_ptr<TreapNode<T>> t)
    {
        if (!t)
        {
            return;
        }

        auto max = t;

        if (t->left && t->left->priority > max->priority)
        {
            max = t->left;
        }
        if (t->right && t->right->priority > max->priority)
        {
            max = t->right;
        }

        if (max != t)
        {
            swap(t->priority, max->priority);
            heapify(max);
        }
    }

    shared_ptr<TreapNode<T>> build(vector<T> &v, int l, int r)
    {
        sort(v.begin() + l, v.begin() + r + 1);

        if (l > r)
            return nullptr;

        int m = (l + r) / 2;

        auto t = make_shared<TreapNode<T>>(v[m]); //
        t->left = build(v, l, m - 1);
        t->right = build(v, m + 1, r);

        heapify(t);
        return t;
    }

    int height(shared_ptr<TreapNode<T>> &node)
    {
        if (!node)
            return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    void print_treap_2D(shared_ptr<TreapNode<T>> node, string prefix = "", bool isLeft = true) {
        if (node == nullptr) return;

        if (node->right) {
            print_treap_2D(node->right, prefix + (isLeft ? "│   " : "    "), false);
        }

        cout << prefix;
        cout << (isLeft ? "└── " : "┌── ");
        cout << node->key << "(" << node->priority << ")" << endl;

        if (node->left) {
            print_treap_2D(node->left, prefix + (isLeft ? "    " : "│   "), true);
        }
    }


    void preorder(shared_ptr<TreapNode<T>> root) {
        if (!root) return;
        cout << root->key << "(" << root->priority << ") ";
        preorder(root->left);
        preorder(root->right);
    }

};

int main()
{
    srand(time(nullptr));

    shared_ptr<TreapNode<int>> t = nullptr;

    vector<pair<int, int>> keys = {
        {5, 90}, {3, 70}, {1, 50}, {4, 60},
        {2, 55}, {9, 85}, {7, 65}, {8, 75},
        {6, 60}, {0, 45}, {10, 80}, {11, 70}
    };

    for (const auto& [key, priority] : keys) {
    t->insert(t, key, priority);
}

    t->print_treap_2D(t);
    cout << endl;

    cout << "Inserting 20" << endl;
    t->insert(t, 20, 95);
    t->print_treap_2D(t);
    cout << endl;

    cout << "Inserting 15" << endl;
    t->insert(t, 15, 78);
    t->print_treap_2D(t);
    cout << endl;

    cout << "Removing 5" << endl;
    t->remove(t, 5);
    t->print_treap_2D(t);
    cout << endl;

    cout << "Searching for 10" << endl;
    auto found = t->search(t, 10);
    if (found)
    {
        cout << "Found: " << found->getKey() << "(" << found->getPriority() << ")" << endl;
    }
    else
    {
        cout << "Not found!" << endl;
    }

    return 0;
}
// g++ -std=c++17  PS10_trace_2.cpp -o PS10_trace_2
// chcp 65001