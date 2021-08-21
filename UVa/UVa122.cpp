#include <bits/stdc++.h>

using namespace std;

struct Node {
    int id;
    Node *nw;
    Node *ne;
    explicit Node(int a = 0, Node *b = nullptr, Node *c = nullptr) : id(a), left(b), right(c) {};
};

struct StoreNode {
    int id;
    string path;
};

struct Tree {
    Node *root;
    Tree() { root = new Node; }
    bool insert(int data, const string &path) const {
        Node *p = new Node;
        p->id = data;
        Node *k = root;
        for (int i = 0; i < path.length() - 1; i++) {
            if (path[i] == 'L') {
                if (k->left == nullptr) return false;
                k = k->left;
            }
            else {
                if (k->right == nullptr) return false;
                k = k->right;
            }
        }
        bool ok = false;
        if (path.back() == 'R' && k->right == nullptr) k->right = p, ok = true;
        else if (k->left == nullptr) k->left = p, ok = true;
        return ok;
    }
};

vector<StoreNode> store;

bool solve() {
    sort(store.begin(), store.end(), [](const StoreNode &a, const StoreNode &b) {
        return a.path.length() < b.path.length();
    });
    if (!store[0].path.empty()) return false;
    Tree g {};
    g.root->id = store[0].id;
    for (int i = 1; i < store.size(); i++) {
        bool k = g.insert(store[i].id, store[i].path);
        if (!k) return false;
    }
    queue<Node *> q;
    q.push(g.root);
    while (!q.empty()) {
        Node *now = q.front();
        q.pop();
        if (now != g.root) cout << " ";
        cout << now->id;
        if (now->left != nullptr) q.push(now->left);
        if (now->right != nullptr) q.push(now->right);
    }
    cout << endl;
    return true;
}

void read() {
    string s;
    while (cin >> s) {
        if (s == "()") break;
        int v;
        sscanf(&s[1], "%d", &v);
        int g = int(s.find(','));
        store.push_back({v, s.substr(g + 1, s.length() - g - 2)});
    }
}

int main() {
    while (true) {
        read();
        if (store.empty()) break;
        bool g = solve();
        if (!g) cout << "not complete" << endl;
        store.clear();
    }
    return 0;
}
