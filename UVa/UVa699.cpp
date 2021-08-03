#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node *left;
    Node *right;
    explicit Node(int a = 0, Node *b = nullptr, Node *c = nullptr) : id(a), left(b), right(c) {};
};

struct Tree {
    Node *root;
    explicit Tree() { root = new Node(); }
};

void build(Node *g, bool right) {
    int v;
    scanf("%d", &v);
    if (v == -1)
        return;
    Node *p = new Node;
    p->id = v;
    if (right)
        g->right = p;
    else
        g->left = p;
    build(p, false);
    build(p, true);
}

map<int, int> res;

void solve(Node *g, int pos) {
    res[pos] += g->id;
    if (g->left != nullptr)
        solve(g->left, pos - 1);
    if (g->right != nullptr)
        solve(g->right, pos + 1);
}

void removeTree(Node *g) {
    if (g == nullptr)
        return;
    removeTree(g->left);
    removeTree(g->right);
    delete g;
}

int main() {
    int root;
    int kase = 0;
    while (++kase) {
        res.clear();
        scanf("%d", &root);
        if (root == -1)
            break;
        Tree g;
        g.root->id = root;
        build(g.root, false);
        build(g.root, true);
        solve(g.root, 0);
        bool s = false;
        printf("Case %d:\n", kase);
        for (auto i : res) {
            printf(s ? " %d" : "%d", i.second);
            s = true;
        }
        printf("\n\n");
        removeTree(g.root);
    }
    return 0;
}
