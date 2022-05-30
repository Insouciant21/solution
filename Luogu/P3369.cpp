#include <bits/stdc++.h>

using namespace std;

const int inf = numeric_limits<int>::max();

struct Node {
    Node *ch[2] {};
    int v, r;
    int s;

    Node(int c = 0) {
        mt19937 rng((random_device()()));
        uniform_int_distribution<int> g(1, inf);
        r = g(rng);
        v = c, s = 1;
        ch[0] = ch[1] = nullptr;
    }

    int cmp(int x) const {
        if (v == x) return -1;
        else return x < v ? 0 : 1;
    }

    void maintain() {
        s = 1;
        if (ch[0] != nullptr) s += ch[0]->s;
        if (ch[1] != nullptr) s += ch[1]->s;
    }
};

void rotate(Node *&o, int d) {
    Node *k = o->ch[d ^ 1];
    o->ch[d ^ 1] = k->ch[d];
    k->ch[d] = o;
    o->maintain(), k->maintain();
    o = k;
}

void insert(Node *&o, int v) {
    if (o == nullptr) o = new Node(v);
    else {
        int d = (v < o->v ? 0 : 1);
        insert(o->ch[d], v);
        if (o->ch[d]->r > o->r) rotate(o, d ^ 1);
    }
    o->maintain();
}

void remove(Node *&o, int v) {
    int d = o->cmp(v);
    if (d == -1) {
        if (o->ch[0] != nullptr && o->ch[1] != nullptr) {
            int d2 = (o->ch[0]->r > o->ch[1]->r ? 0 : 1);
            rotate(o, d2);
            remove(o->ch[d2], v);
        }
        else {
            if (o->ch[0] == nullptr && o->ch[1] == o->ch[0]) delete o, o = nullptr;
            else if (o->ch[0] == nullptr) o = o->ch[1];
            else o = o->ch[0];
        }
    }
    else remove(o->ch[d], v);
    if (o != nullptr) o->maintain();
}

int rk(Node *o, int x) {
    if (o == nullptr) return 1;
    if (x <= o->v) return rk(o->ch[0], x);
    return (o->ch[0] == nullptr ? 0 : o->ch[0]->s) + 1 + rk(o->ch[1], x);
}

int kth(Node *o, int k) {
    if (o == nullptr || k <= 0 || k > o->s) return 0;
    int s = (o->ch[0] == nullptr ? 0 : o->ch[0]->s);
    if (k == s + 1) return o->v;
    else if (k <= s) kth(o->ch[0], k);
    else kth(o->ch[1], k - s - 1);
}

int findFront(Node *o, int x) {
    if (o == nullptr) return -inf;
    if (x <= o->v) return findFront(o->ch[0], x);
    return max(o->v, findFront(o->ch[1], x));
}

int findBack(Node *o, int x) {
    if (o == nullptr) return inf;
    if (x >= o->v) return findBack(o->ch[1], x);
    return min(o->v, findBack(o->ch[0], x));
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    cin >> n;
    Node *root = new Node(inf);
    while (n--) {
        int opt, x;
        cin >> opt >> x;
        switch (opt) {
            case 1: insert(root, x); break;
            case 2: remove(root, x); break;
            case 3: cout << rk(root, x) << endl; break;
            case 4: cout << kth(root, x) << endl; break;
            case 5: cout << findFront(root, x) << endl; break;
            default: cout << findBack(root, x) << endl; break;
        }
    }
    return 0;
}