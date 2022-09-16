#include <bits/stdc++.h>

using namespace std;

const int maxn = 100080;

struct Splay {
    struct Node {
        Node *fa, *ch[2], **root;
        int x, size, cnt;
        Node(Node **root, Node *fa, int x) : root(root), fa(fa), x(x), cnt(1), size(1) { ch[0] = ch[1] = nullptr; }

        int get() { return this == fa->ch[1]; }

        void maintain() {
            size = cnt;
            if (ch[0]) size += ch[0]->size;
            if (ch[1]) size += ch[1]->size;
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
            old->maintain();
            maintain();
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
        if (*v != nullptr) (*v)->cnt++, (*v)->size++;
        else *v = new Node(&root, fa, x);
        (*v)->splay();
        return root;
    }

    Node *find(int x) const {
        Node *v = root;
        while (v != nullptr && v->x != x) v = v->ch[x > v->x];
        if (v) v->splay();
        return v;
    }

    static void erase(Node *v) {
        Node *p = v->pred(), *s = v->succ();
        p->splay();
        s->splay(p);
        if (v->size > 1) v->size--, v->cnt--;
        else {
            delete s->ch[0];
            s->ch[0] = nullptr;
        }
        s->size--, p->size--;
    }

    void erase(int x) const {
        Node *v = find(x);
        if (!v) return;
        erase(v);
    }

    int pred(int x) {
        Node *v = find(x);
        if (v) return v->pred()->x;
        else {
            v = insert(x);
            int ans = v->pred()->x;
            erase(x);
            return ans;
        }
    }

    int succ(int x) {
        Node *v = find(x);
        if (v) return v->succ()->x;
        else {
            v = insert(x);
            int ans = v->succ()->x;
            erase(x);
            return ans;
        }
    }

    int rank(int x) {
        Node *v = find(x);
        if (v) return v->rank();
        else {
            v = insert(x);
            int res = v->rank();
            erase(v);
            return res;
        }
    }

    int kth(int x) const {
        Node *v = root;
        while (!(x >= v->rank() && x < v->rank() + v->cnt)) {
            if (x < v->rank()) v = v->ch[0];
            else x -= v->rank() + v->cnt, v = v->ch[1];
        }
        v->splay();
        return v->x;
    }

    Splay() : root(nullptr) {
        insert(INT_MAX);
        insert(INT_MIN);
    }
} splay;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        splay.insert(x);
    }
    int last = 0;
    int ans = 0;
    while (m--) {
        int opt, c;
        cin >> opt >> c;
        c = c ^ last;
        // cout << c << " " << last << endl;
        if (opt == 1) splay.insert(c);
        if (opt == 2) splay.erase(c);
        if (opt == 3) last = splay.rank(c);
        if (opt == 4) last = splay.kth(c);
        if (opt == 5) last = splay.pred(c);
        if (opt == 6) last = splay.succ(c);
        if (opt != 1 && opt != 2) ans = ans ^ last;
    }
    cout << ans << endl;
    return 0;
}