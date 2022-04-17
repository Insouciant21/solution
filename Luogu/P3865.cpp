#include <bits/stdc++.h>
using namespace std;

int n, m;
const int maxn = int(1e5) + 100;
int logn[maxn];
int st[maxn][21];
int a[maxn];

void buildTable() {
    logn[1] = 0, logn[2] = 1;
    for (int i = 3; i < maxn; i++) logn[i] = logn[i / 2] + 1;
    for (int i = 1; i <= n; i++) st[i][0] = a[i];
    for (int j = 1; j <= 21; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++) st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

inline int query(int l, int r) {
    int s = logn[r - l + 1];
    return max(st[l][s], st[r - (1 << s) + 1][s]);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    buildTable();
    while (m--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", query(l, r));
    }
    return 0;
}
