#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node *ch[2] = {nullptr, nullptr};
    int r {};
    int v {};
    int cmp(int x) const {
        if (x == v) return -1;
        return x < v ? 0 : 1;
    }
};

mt19937 mt((random_device()()));
uniform_int_distribution<int> g(1, 100000);

void rotate(Node *&o, int d) {
    Node *k = o->ch[d ^ 1];
    o->ch[d ^ 1] = k->ch[d];
    k->ch[d] = o, o = k;
}

void insert(Node *&o, int x) {
    if (o == nullptr) {
        o = new Node;
        o->v = x, o->r = g(mt);
    }
    else {
        int d = o->cmp(x);
        insert(o->ch[d], x);
        if (o->ch[d]->r > o->r) rotate(o, d ^ 1);
    }
}

void remove(Node *&o, int x) {
    int d = o->cmp(x);
    if (d == -1) {
        if (o->ch[0] == o->ch[1] && o->ch[0] == nullptr) {
            delete o;
            o = nullptr;
        }
        else if (o->ch[0] == nullptr) o = o->ch[1];
        else if (o->ch[1] == nullptr) o = o->ch[0];
        else {
            int d2 = (o->ch[0]->r > o->ch[1]->r ? 1 : 0);
            rotate(o, d2);
            remove(o->ch[d2], x);
        }
    }
    else remove(o->ch[d], x);
}

int queryF(Node *o, int x) {
    if (o == nullptr) return -0x3f3f3f;
    if (o->v >= x) return queryF(o->ch[0], x);
    else return max(o->v, queryF(o->ch[1], x));
}

int queryB(Node *o, int x) {
    if (o == nullptr) return 0x3f3f3f;
    if (o->v <= x) return queryB(o->ch[1], x);
    else return min(o->v, queryB(o->ch[0], x));
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    Node *root = new Node;
    int n;
    cin >> n;
    bool first = false;
    while (n--) {
        int opt, x;
        cin >> opt >> x;
        if (!first && (opt == 1 || opt == 2)) {
            root->v = x, root->r = g(mt), first = true;
            continue;
        }
        switch (opt) {
            case 1: insert(root, x); break;
            case 2: remove(root, x); break;
            case 3: cout << queryF(root, x) << endl; break;
            default: cout << queryB(root, x) << endl; break;
        }
    }
    return 0;
}