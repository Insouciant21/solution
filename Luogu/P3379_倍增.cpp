#include <bits/stdc++.h>

using namespace std;

int n, m, s;
const int maxn = 5e5 + 10;
struct Edge {
    int u, v;
    int LCA;
};
vector<Edge> e[maxn];
int fa[32][maxn];
int dep[maxn];

void dfs(int root, int last) {
    fa[0][root] = last;
    dep[root] = dep[last] + 1;
    for (int i = 1; i < 31; i++) fa[i][root] = fa[i - 1][fa[i - 1][root]];
    for (auto ex : e[root]) {
        if (ex.v == last) continue;
        dfs(ex.v, root);
    }
}

int lca(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    int t = dep[y] - dep[x];
    for (int j = 0; t; t >>= 1, j++)
        if (t & 1) y = fa[j][y];
    if (y == x) return x;
    for (int j = 31; j >= 0 && y != x; j--)
        if (fa[j][x] != fa[j][y]) x = fa[j][x], y = fa[j][y];
    return fa[0][x];
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        e[u].push_back({u, v});
        e[v].push_back({v, u});
    }
    dfs(s, 0);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        printf("%d\n", lca(u, v));
    }
    return 0;
}