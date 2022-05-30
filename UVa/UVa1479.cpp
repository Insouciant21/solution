#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f;
const int maxn = 20100;

struct Treap {
    struct Node {
        Node *ch[2] {};
        int v, r;
        int s;

        explicit Node(int c = 0) {
            r = rand();
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

    Node *root;

    Treap() { root = nullptr; }

    static void rotate(Node *&o, int d) {
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

    int kth(Node *o, int k) {
        if (o == nullptr || k <= 0 || k > o->s) return 0;
        int s = (o->ch[1] == nullptr ? 0 : o->ch[1]->s);
        if (k == s + 1) return o->v;
        else if (k <= s) return kth(o->ch[1], k);
        else return kth(o->ch[0], k - s - 1);
    }

    void merge(Node *&k) {
        if (k->ch[0] != nullptr) merge(k->ch[0]);
        if (k->ch[1] != nullptr) merge(k->ch[1]);
        insert(root, k->v);
    }
};

Treap s[maxn];

struct Edge {
    int u, v;
};

struct Operation {
    int type;
    int p1, p2;
};

int fa[maxn];

int findset(int f) {
    return (f != fa[f]) ? fa[f] = findset(fa[f]) : f;
}

void addEdge(int u, int v) {
    int x = findset(u), y = findset(v);
    if (x != y) {
        if (s[x].root->s < s[y].root->s) {
            fa[x] = y;
            s[y].merge(s[x].root);
        }
        else {
            fa[y] = x;
            s[x].merge(s[y].root);
        }
    }
}

int w[maxn];
Edge p[65000];
Operation k[600000];
bool removed[65000];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    int kase = 0;
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && n == m) break;
        memset(w, 0, sizeof w);
        memset(p, 0, sizeof p);
        memset(k, 0, sizeof k);
        for (int i = 1; i <= n; i++) cin >> w[i];
        for (int i = 1; i <= m; i++) cin >> p[i].u >> p[i].v;
        memset(removed, 0, sizeof removed);
        memset(fa, 0, sizeof fa);
        memset(s, 0, sizeof s);
        int cn = 0;
        while (true) {
            char c;
            int v, x = -1, l;
            cin >> c;
            if (c == 'E') break;
            cin >> v;
            if (c == 'C') {
                cin >> l;
                x = w[v];
                w[v] = l;
                c = 1;
            }
            else if (c == 'D') removed[v] = true, c = -1;
            else if (c == 'Q') cin >> x, c = 0;
            k[++cn] = {c, v, x};
        }
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
            s[i].root = new Treap::Node(w[i]);
        }

        for (int i = 1; i <= m; i++)
            if (!removed[i]) addEdge(p[i].u, p[i].v);

        double res = 0;
        int cnt = 0;
        for (int i = cn; i > 0; i--) {
            if (k[i].type == -1) addEdge(p[k[i].p1].u, p[k[i].p1].v);
            if (k[i].type == 0) {
                cnt++;
                int x = findset(k[i].p1);
                res += s[x].kth(s[x].root, k[i].p2);
            }
            if (k[i].type == 1) {
                int x = findset(k[i].p1);
                s[x].remove(s[x].root, w[k[i].p1]);
                s[x].insert(s[x].root, k[i].p2);
                w[k[i].p1] = k[i].p2;
            }
        }
        cout << "Case " << ++kase << ": " << fixed << setprecision(6) << res / cnt << endl;
    }

    return 0;
}