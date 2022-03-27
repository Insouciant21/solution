// Insouciant at 20:08
// Status:
// Problem: P3373.cc

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> a;

struct SegTree {
    ll v {};
    ll mul = 1;
    ll add = 0;
};

vector<SegTree> f;

int p;

inline void init(int x) {
    a.resize(x + 100);
    f.resize(x * 10 + 100);
}

void buildTree(int pos, int l, int r);
void pushDown(int fa, int l, int r);
void mulTree(int pos, int l, int r, int x, int y, int k);
void addTree(int pos, int l, int r, int x, int y, int k);
ll getAns(int pos, int l, int r, int x, int y);

int main() {
    int n, m;
    scanf("%d %d %d", &n, &m, &p);
    init(n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    buildTree(1, 1, n);
    while (m--) {
        int c;
        scanf("%d", &c);
        int x, y, k;
        switch (c) {
            case 1:
                scanf("%d %d %d", &x, &y, &k);
                mulTree(1, 1, n, x, y, k);
                break;
            case 2:
                scanf("%d %d %d", &x, &y, &k);
                addTree(1, 1, n, x, y, k);
                break;
            default:
                scanf("%d %d", &x, &y);
                printf("%lld\n", getAns(1, 1, n, x, y));
                break;
        }
    }
    return 0;
}

void buildTree(int pos, int l, int r) {
    f[pos].add = 0, f[pos].mul = 1;
    if (l == r) {
        f[pos].v = a[l];
        return;
    }
    int m = (l + r) / 2;
    buildTree(pos * 2, l, m);
    buildTree(pos * 2 + 1, m + 1, r);
    f[pos].v = (f[pos * 2].v + f[pos * 2 + 1].v) % p;
}

void pushDown(int fa, int l, int r) {
    int ls = fa * 2, rs = fa * 2 + 1;
    int m = (l + r) / 2;
    f[ls].v = (f[ls].v * f[fa].mul % p + f[fa].add * (m - l + 1) % p) % p,
    f[rs].v = (f[rs].v * f[fa].mul % p + f[fa].add * (r - m) % p) % p;
    f[ls].mul = (f[ls].mul * f[fa].mul) % p, f[rs].mul = (f[rs].mul * f[fa].mul) % p;
    f[ls].add = (f[ls].add * f[fa].mul % p + f[fa].add) % p, f[rs].add = (f[rs].add * f[fa].mul % p + f[fa].add) % p;
    f[fa].add = 0, f[fa].mul = 1;
}

void addTree(int pos, int l, int r, int x, int y, int k) {
    if (x <= l && y >= r) {
        f[pos].v = (f[pos].v + (r - l + 1) * k) % p;
        f[pos].add = (f[pos].add + k) % p;
        return;
    }
    int m = (l + r) / 2;
    pushDown(pos, l, r);
    if (x <= m) addTree(pos * 2, l, m, x, y, k);
    if (y > m) addTree(pos * 2 + 1, m + 1, r, x, y, k);
    f[pos].v = (f[pos * 2].v + f[pos * 2 + 1].v) % p;
}

void mulTree(int pos, int l, int r, int x, int y, int k) {
    if (x <= l && y >= r) {
        f[pos].v = f[pos].v * k % p;
        f[pos].mul = f[pos].mul * k % p;
        f[pos].add = f[pos].add * k % p;
        return;
    }
    int m = (l + r) / 2;
    pushDown(pos, l, r);
    if (x <= m) mulTree(pos * 2, l, m, x, y, k);
    if (y > m) mulTree(pos * 2 + 1, m + 1, r, x, y, k);
    f[pos].v = (f[pos * 2].v + f[pos * 2 + 1].v) % p;
}

ll getAns(int pos, int l, int r, int x, int y) {
    if (x <= l && r <= y) return f[pos].v % p;
    int m = (l + r) / 2;
    ll ret = 0;
    pushDown(pos, l, r);
    if (x <= m) ret += getAns(pos * 2, l, m, x, y);
    if (y > m) ret += getAns(pos * 2 + 1, m + 1, r, x, y);
    return ret % p;
}