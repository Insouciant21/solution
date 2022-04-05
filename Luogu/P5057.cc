/*
 *  Problem: P5057.cc
 *  Author: Insouciant21
 *  Date: 2022/4/5
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = int(1e5) * 2 + 100;
int n, m;
int a[maxn];
int f[4 * maxn];
bool b[4 * maxn];

void pushDown(int, int, int);
void xorTree(int, int, int, int, int);
int ansTree(int, int, int, int, int);

int main() {
    scanf("%d %d", &n, &m);
    memset(f, 0, sizeof f);
    memset(b, 0, sizeof b);
    while (m--) {
        int opt, l, r;
        scanf("%d %d", &opt, &l);
        if (opt == 1) {
            scanf("%d", &r);
            xorTree(1, 1, n, l, r);
        }
        else
            printf("%d\n", ansTree(1, 1, n, l, l));
    }
    return 0;
}

void pushDown(int pos, int l, int r) {
    if (!b[pos]) return;
    int ls = pos * 2, rs = pos * 2 + 1;
    int mid = (l + r) >> 1;
    f[ls] = (mid - l + 1) - f[ls], b[ls] = !b[ls];
    f[rs] = (r - mid) - f[rs], b[rs] = !b[rs];
    b[pos] = false;
}

void xorTree(int pos, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        f[pos] = (r - l + 1) - f[pos];
        b[pos] = !b[pos];
        return;
    }
    pushDown(pos, l, r);
    int mid = (l + r) / 2;
    if (x <= mid) xorTree(pos << 1, l, mid, x, y);
    if (y > mid) xorTree(pos << 1 | 1, mid + 1, r, x, y);
    f[pos] = f[pos << 1] + f[pos << 1 | 1];
}

int ansTree(int pos, int l, int r, int x, int y) {
    if (x <= l && r <= y) return f[pos];
    pushDown(pos, l, r);
    int mid = (l + r) >> 1;
    int ret = 0;
    if (x <= mid) ret += ansTree(pos << 1, l, mid, x, y);
    if (y > mid) ret += ansTree(pos << 1 | 1, mid + 1, r, x, y);
    return ret;
}