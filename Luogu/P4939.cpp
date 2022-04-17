#include <bits/stdc++.h>

using namespace std;

int n, m;
const int maxn = int(1e7) + 100;
int f[maxn * 3];

void pushDown(int);
void insertTree(int, int, int, int, int);
int query(int, int, int, int);

int main() {
    memset(f, 0, sizeof f);
    scanf("%d %d", &n, &m);
    while (m--) {
        int opt;
        scanf("%d", &opt);
        if (!opt) {
            int x, y;
            scanf("%d %d", &x, &y);
            insertTree(1, 1, n, x, y);
        }
        else {
            int d;
            scanf("%d", &d);
            printf("%d\n", query(1, 1, n, d));
        }
    }
}

void insertTree(int pos, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        f[pos]++;
        return;
    }
    int m = (l + r) >> 1;
    if (x <= m) insertTree(pos << 1, l, m, x, y);
    if (y > m) insertTree(pos << 1 | 1, m + 1, r, x, y);
}

int query(int pos, int l, int r, int d) {
    if (l == r) return f[pos];
    int m = (l + r) >> 1;
    if (m >= d)
        return f[pos] + query(pos << 1, l, m, d);
    else
        return f[pos] + query(pos << 1 | 1, m + 1, r, d);
}
