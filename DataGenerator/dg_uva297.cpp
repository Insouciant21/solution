#include <bits/stdc++.h>

using namespace std;

random_device rd;
mt19937_64 gen(rd());
uniform_int_distribution<int> l(1, 2147483647);
uniform_int_distribution<int> h(2, 5);

struct Node {
    char value;
    Node *l1, *l2;
    Node *r1, *r2;
    explicit Node(char i = 0, Node *u = nullptr, Node *y = nullptr, Node *g = nullptr, Node *c = nullptr) : value(i), l1(u), l2(y), r1(g), r2(c) {};
};

void make(Node *g, int depth) {
    g = new Node;
    if (depth != 5) {
        g->value = 'p';
        cout << g->value;
        make(g->l1, depth + 1);
        make(g->l2, depth + 1);
        make(g->r1, depth + 1);
        make(g->r2, depth + 1);
    }
    if (depth == 5) {
        g->value = (l(gen) % h(gen) == 0 ? 'f' : 'e');
        cout << g->value;
        return;
    }
}

void removeTree(Node *g) {
    if (g == nullptr) return;
    removeTree(g->l1);
    removeTree(g->l2);
    removeTree(g->r1);
    removeTree(g->r2);
    delete g;
}

int main() {
    freopen("uva297.in", "w", stdout);
    cout << 10000 << endl;
    for (int i = 0; i < 10000; i++) {
        Node *root = nullptr;
        make(root, 1);
        removeTree(root);
        cout << endl;
        root = nullptr;
        make(root, 1);
        removeTree(root);
        cout << endl;
    }
    return 0;
}
