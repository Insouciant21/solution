#include <bits/stdc++.h>

using namespace std;

int n, m;

struct Splay {
    struct Node {
        int x, size, cnt;
        int flip;
        Node *fa, *ch[2] {}, **root;
        Node(Node **root, Node *fa, int x) : root(root), fa(fa), x(x), cnt(1), size(1), flip(0) {
            ch[0] = ch[1] = nullptr;
        }

        int get() { return this == fa->ch[1]; }

        void maintain() {
            size = cnt;
            if (ch[0]) size += ch[0]->size;
            if (ch[1]) size += ch[1]->size;
        }

        void pushdown() {
            if (flip) {
                if (ch[0]) ch[0]->flip ^= 1;
                if (ch[1]) ch[1]->flip ^= 1;
                flip = 0;
                swap(ch[0], ch[1]);
            }
        }

        void rotate() {
            Node *old = fa;
            int d = get();
            fa = old->fa;
            if (old->fa) old->fa->ch[old->get()] = this;
            if (ch[d ^ 1]) ch[d ^ 1]->fa = old;
            old->ch[d] = ch[d ^ 1];
            old->fa = this;
            ch[d ^ 1] = old;
            old->maintain(), maintain();
            if (fa == nullptr) *root = this;
        }

        void splay(Node *target = nullptr) {
            while (fa != target) {
                if (fa->fa == target) rotate();
                else if (get() == fa->get()) fa->rotate(), rotate();
                else rotate(), rotate();
            }
        }

        Node *pred() {
            Node *v = ch[0];
            while (v->ch[1]) v = v->ch[1];
            return v;
        }

        Node *succ() {
            Node *v = ch[1];
            while (v->ch[0]) v = v->ch[0];
            return v;
        }

        int rank() { return ch[0] ? ch[0]->size : 0; }
    } * root;

    Node *insert(int x) {
        Node **v = &root, *fa = nullptr;
        while (*v != nullptr && (*v)->x != x) {
            fa = *v;
            fa->size++;
            v = &fa->ch[x > fa->x];
        }
        if (*v) (*v)->size++, (*v)->cnt++;
        else (*v) = new Node(&root, fa, x);
        (*v)->splay();
        return root;
    }

    Node *find(int x) const {
        Node *v = root;
        while (v != nullptr && v->x != x) v = v->ch[v->x > x];
        if (v) v->splay();
        return v;
    }

    Node *kth(int x) const {
        Node *v = root;
        while (!(x >= v->rank() && x < v->rank() + v->cnt)) {
            if (x < v->rank()) v = v->ch[0];
            else x -= v->rank() + v->cnt, v = v->ch[1];
        }
        v->splay();
        return v;
    }

    void reverse(int l, int r) {
        Node *u = kth(l - 1), *v = kth(r + 1);
        u->splay(), v->splay(u);
        root->ch[1]->ch[0]->flip = 1;
    }

    Splay() : root(nullptr) { insert(INT_MAX), insert(INT_MIN); }

    void print(Node *point) {
        if (point) {
            point->pushdown();
            print(point->ch[0]);
            if (point->x >= 1 && point->x <= n + 10) cout << point->x << " ";
            print(point->ch[1]);
        }
    }
} splay;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; i++) splay.insert(i);
    while (m--) {
        int l, r;
        cin >> l >> r;
        splay.reverse(l, r);
    }
    splay.print(splay.root);
    return 0;
}