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
    int subtreeSum;
    int subtreeCount;
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
        updateMetadata(x->right); // old root, now right child
        updateMetadata(x);        // new root
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

        insert(key <= root->key ? root->left : root->right, key, priority);

        if (root->left && root->left->priority > root->priority)
        {
            right_rotation(root);
        }

        if (root->right && root->right->priority > root->priority)
        {
            left_rotation(root);
        }
    }

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

    void print_treap_2D(shared_ptr<TreapNode<T>> &root)
    {
        int h = height(root);
        vector<string> output(h), linkAbove(h);
        drawNode(output, linkAbove, root, 0, 5, ' ');

        // Create link lines
        for (int i = 1; i < h; i++)
        {
            for (int j = 0; j < linkAbove[i].size(); j++)
            {
                if (linkAbove[i][j] != ' ')
                {
                    int size = output[i - 1].size();
                    if (size < j + 1)
                    {
                        output[i - 1] += string(j + 1 - size, ' ');
                    }
                    int jj = j;
                    if (linkAbove[i][j] == 'L')
                    {
                        while (output[i - 1][jj] == ' ')
                        {
                            jj++;
                        }
                        for (int k = j + 1; k < jj - 1; k++)
                        {
                            output[i - 1][k] = '_';
                        }
                    }
                    else if (linkAbove[i][j] == 'R')
                    {
                        while (output[i - 1][jj] == ' ')
                        {
                            jj--;
                        }
                        for (int k = j - 1; k > jj + 1; k--)
                        {
                            output[i - 1][k] = '_';
                        }
                    }
                    linkAbove[i][j] = '|';
                }
            }
        }

        // Output
        for (int i = 0; i < h; i++)
        {
            if (i)
            {
                cout << linkAbove[i] << '\n';
            }
            cout << output[i] << '\n';
        }
    }

    
    void drawNode(vector<string> &output, vector<string> &linkAbove, shared_ptr<TreapNode<T>> &node, int level, int p, char linkChar)
    {
        if (!node)
            return;

        int h = output.size();
        string SP = " ";

        if (p < 0) // Shunt everything non-blank across
        {
            string extra(-p, ' ');
            for (string &s : output)
                if (!s.empty())
                    s = extra + s;
            for (string &s : linkAbove)
                if (!s.empty())
                    s = extra + s;
        }
        if (level < h - 1)
            p = max(p, (int)output[level + 1].size());
        if (level > 0)
            p = max(p, (int)output[level - 1].size());
        p = max(p, (int)output[level].size());

        // Fill in to left
        if (node->left)
        {
            string leftData = SP + to_string(node->left->key) + "(" + to_string(node->left->priority) + ")" + SP;
            drawNode(output, linkAbove, node->left, level + 1, p - leftData.size(), 'L');
            p = max(p, (int)output[level + 1].size());
        }

        // Enter this data
        int space = p - output[level].size();
        if (space > 0)
        {
            output[level] += string(space, ' ');
        }
        string nodeData = SP + to_string(node->key) + "(" + to_string(node->priority) + ")" + SP;
        output[level] += nodeData;

        // Add vertical link above
        space = p + SP.size() - linkAbove[level].size();
        if (space > 0)
        {
            linkAbove[level] += string(space, ' ');
        }
        linkAbove[level] += linkChar;

        // Fill in to right
        if (node->right)
        {
            drawNode(output, linkAbove, node->right, level + 1, output[level].size(), 'R');
        }
    }

    void updateMetadata(shared_ptr<TreapNode<T>> &root){
        if (!root) return;

        root->subtreeSum = root->key;
        root->subtreeCount = 0;

        if(root->left){
            root->subtreeSum += root->left->subtreeSum;
            root->subtreeCount  += 1 + root->left->subtreeCount ;
        }
        if(root->right){
            root->subtreeSum += root->right->subtreeSum;
            root->subtreeCount  += 1 + root->right->subtreeCount ;
        }
    }

};


// ---------- WARNING: Do not modify the main function! ----------
// ---------- WARNING: Do not modify the main function! ----------
// ---------- WARNING: Do not modify the main function! ----------
int main()
{
    srand(time(nullptr));

    shared_ptr<TreapNode<int>> t = nullptr;

    vector<int> keys    {4, 2, 5, 1, 3};
    vector<int> priority{9, 5, 8, 2, 4};

    for (int i = 0; i < keys.size(); i++)
    {
        t->insert(t, keys.at(i), priority.at(i));
    }

    t->print_treap_2D(t);
    cout << endl;

    return 0;
}
// ---------- WARNING: Do not modify the main function! ----------
// ---------- WARNING: Do not modify the main function! ----------
// ---------- WARNING: Do not modify the main function! ----------

// g++ -std=c++17  run_wa10.cpp -o wa10
