class Trie {
private:
    struct Node {
        // any property here
        bool isLeaf = true;
        vector<Node *> child = {};

        Node(int _sz) : child(vector<Node *>(_sz, nullptr)) {}
    };

    int sz;
    char st;
    Node *root;

public:

    Trie(int _sz, char _st) {
        sz = _sz, st = _st;
        root = new Node(sz);
    }

    void add(string &s, int i) {
        Node *node = root;
        for (auto &ch: s) {
            if (node->child[ch - st] == nullptr) {
                node->isLeaf = false;
                node->child[ch - st] = new Node(sz);
            }
            node = node->child[ch - st];
        }
    }
    // any function here
    void del(Node *x) {
        for (auto &i: x->child) {
            if (i != nullptr)
                del(i);
            delete x;
        }
    }

    void del() {
        del(root);
    }
};


void Achilles1() { Trie trie = Trie(26, 'a'); }
