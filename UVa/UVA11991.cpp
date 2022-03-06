#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    // freopen("temp.in", "r", stdin);
    // freopen("temp.out", "w", stdout);
    while (scanf("%d %d", &n, &m) == 2) {
        map<int, vector<int>> p;
        p.clear();
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            p[x].push_back(i);
        }
        for (int i = 0; i < m; i++) {
            int k, v;
            scanf("%d %d", &k, &v);
            if (!p.count(v) || p[v].size() < k) puts("0");
            else printf("%d\n", p[v][k - 1]);
        }
    }
}