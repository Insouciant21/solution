/*
 *  Problem: UVa11992
 *  Author: Insouciant21
 *  Date: 2022/4/24
 */

#include <bits/stdc++.h>

using namespace std;

struct SegTree {
    long long sum = 0;
    long long maximum = 0;
    long long minimum = 0;
    long long setv = -1, addv = 0;
};

SegTree f[21][5 * int(1e5) + 10];

void pushDown(int pos, SegTree *p, int l, int r);
void buildTree(int l, int r, int pos, SegTree *p) {
    if (l == r) {
        p[pos].sum = p[pos].maximum = p[pos].minimum = 0;
        p[pos].setv = -1, p[pos].addv = 0;
        return;
    }
    int m = (l + r) / 2;
    buildTree(l, m, pos * 2, p);
    buildTree(m + 1, r, pos * 2 + 1, p);
    p[pos].sum = p[pos].maximum = p[pos].minimum = 0;
    p[pos].setv = -1, p[pos].addv = 0;
}

void addTree(int l, int r, int x, int y, int pos, SegTree *p, long long v);
void setTree(int l, int r, int x, int y, int pos, SegTree *p, long long v);

long long queryMin(int l, int r, int x, int y, int pos, SegTree *p);
long long queryMax(int l, int r, int x, int y, int pos, SegTree *p);
long long querySum(int l, int r, int x, int y, int pos, SegTree *p);

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int r, c, m;
    while (scanf("%d %d %d", &r, &c, &m) == 3) {
        memset(f, 0, sizeof f);
        for (int i = 1; i < 21; i++) {
            buildTree(1, c, 1, f[i]);
        }
        while (m--) {
            int o;
            int x1, y1, x2, y2;
            scanf("%d %d %d %d %d", &o, &x1, &y1, &x2, &y2);
            int v;
            switch (o) {
                case 1:
                    scanf("%d", &v);
                    for (int i = x1; i <= x2; i++) addTree(1, c, y1, y2, 1, f[i], v);
                    break;
                case 2:
                    scanf("%d", &v);
                    for (int i = x1; i <= x2; i++) setTree(1, c, y1, y2, 1, f[i], v);
                    break;
                default:
                    long long m1 = numeric_limits<int>::max(), m2 = numeric_limits<int>::min(), sum = 0;
                    for (int i = x1; i <= x2; i++) {
                        m1 = min(m1, queryMin(1, c, y1, y2, 1, f[i]));
                        m2 = max(m2, queryMax(1, c, y1, y2, 1, f[i]));
                        sum += querySum(1, c, y1, y2, 1, f[i]);
                    }
                    printf("%lld %lld %lld\n", sum, m1, m2);
                    break;
            }
        }
    }
    return 0;
}

void pushDown(int pos, SegTree *p, int l, int r) {
    int ls = pos * 2, rs = pos * 2 + 1;
    int m = (l + r) / 2;
    if (p[pos].setv >= 0) {
        p[ls].sum = p[pos].setv * (m - l + 1), p[rs].sum = p[pos].setv * (r - m);
        p[ls].maximum = p[ls].minimum = p[pos].setv;
        p[rs].maximum = p[rs].minimum = p[pos].setv;
        p[ls].setv = p[rs].setv = p[pos].setv;
        p[ls].addv = p[rs].addv = 0;
        p[pos].setv = -1;
    }
    if (p[pos].addv > 0) {
        p[ls].sum += p[pos].addv * (m - l + 1), p[rs].sum += p[pos].addv * (r - m);
        p[ls].maximum += p[pos].addv, p[ls].minimum += p[pos].addv;
        p[rs].maximum += p[pos].addv, p[rs].minimum += p[pos].addv;
        p[ls].addv += p[pos].addv, p[rs].addv += p[pos].addv;
        p[pos].addv = 0;
    }
}

void setTree(int l, int r, int x, int y, int pos, SegTree *p, long long v) {
    if (x <= l && r <= y) {
        p[pos].sum = v * (r - l + 1);
        p[pos].maximum = p[pos].minimum = v;
        p[pos].setv = v;
        p[pos].addv = 0;
        return;
    }
    pushDown(pos, p, l, r);
    int m = (l + r) / 2;
    if (x <= m) setTree(l, m, x, y, pos * 2, p, v);
    if (m < y) setTree(m + 1, r, x, y, pos * 2 + 1, p, v);
    p[pos].sum = p[pos * 2].sum + p[pos * 2 + 1].sum;
    p[pos].maximum = max(p[pos * 2].maximum, p[pos * 2 + 1].maximum);
    p[pos].minimum = min(p[pos * 2].minimum, p[pos * 2 + 1].minimum);
}

void addTree(int l, int r, int x, int y, int pos, SegTree *p, long long v) {
    if (x <= l && r <= y) {
        p[pos].sum += v * (r - l + 1);
        p[pos].maximum += v;
        p[pos].minimum += v;
        p[pos].addv += v;
        return;
    }
    pushDown(pos, p, l, r);
    int m = (l + r) / 2;
    if (x <= m) addTree(l, m, x, y, pos * 2, p, v);
    if (m < y) addTree(m + 1, r, x, y, pos * 2 + 1, p, v);
    p[pos].sum = p[pos * 2].sum + p[pos * 2 + 1].sum;
    p[pos].maximum = max(p[pos * 2].maximum, p[pos * 2 + 1].maximum);
    p[pos].minimum = min(p[pos * 2].minimum, p[pos * 2 + 1].minimum);
}

long long queryMin(int l, int r, int x, int y, int pos, SegTree *p) {
    if (x <= l && r <= y) return p[pos].minimum;
    pushDown(pos, p, l, r);
    int m = (l + r) / 2;
    long long ans = numeric_limits<int>::max();
    if (x <= m) ans = min(ans, queryMin(l, m, x, y, pos * 2, p));
    if (m < y) ans = min(ans, queryMin(m + 1, r, x, y, pos * 2 + 1, p));
    return ans;
}

long long queryMax(int l, int r, int x, int y, int pos, SegTree *p) {
    if (x <= l && r <= y) return p[pos].maximum;
    pushDown(pos, p, l, r);
    int m = (l + r) / 2;
    long long ans = numeric_limits<int>::min();
    if (x <= m) ans = max(ans, queryMax(l, m, x, y, pos * 2, p));
    if (m < y) ans = max(ans, queryMax(m + 1, r, x, y, pos * 2 + 1, p));
    return ans;
}

long long querySum(int l, int r, int x, int y, int pos, SegTree *p) {
    if (x <= l && r <= y) return p[pos].sum;
    pushDown(pos, p, l, r);
    int m = (l + r) / 2;
    long long ans = 0;
    if (x <= m) ans += querySum(l, m, x, y, pos * 2, p);
    if (m < y) ans += querySum(m + 1, r, x, y, pos * 2 + 1, p);
    return ans;
}
