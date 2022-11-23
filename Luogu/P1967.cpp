#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e4 + 100;
int n, m;
struct Edge {
    int u, v, w;
};
vector<Edge> edges;
vector<int> e[maxn];
inline void addEdge(int u, int v, int w) {
    e[u].push_back(int(edges.size()));
    edges.push_back({u, v, w});
}
inline void addBiEdge(int u, int v, int w) {
    addEdge(u, v, w), addEdge(v, u, w);
}
inline bool operator<(const Edge &lhs, const Edge &rhs) {
    return lhs.w < rhs.w;
}
int fa[maxn];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void kruskal() {
    priority_queue<Edge> q;
    for (auto i : edges) q.push(i);
    for (int i = 1; i <= n; i++) fa[i] = i;
    edges.clear();
    while (!q.empty()) {
        Edge r = q.top();
        q.pop();
        int fx = find(r.u), fy = find(r.v);
        if (fx == fy) continue;
        fa[fy] = fx;
        addBiEdge(r.u, r.v, r.w);
    }
}
int f[31][maxn];
int minv[31][maxn];
int dep[maxn];
void preDfs(int o, int t) {
    for (int i = 1; i < 31; i++) {
        f[i][o] = f[i - 1][f[i - 1][o]];
        minv[i][o] = min(min(minv[i - 1][f[i - 1][o]], minv[i - 1][o]), minv[i][o]);
    }
    for (int i : e[o]) {
        Edge &r = edges[i];
        if (r.v != t) {
            dep[r.v] = dep[o] + 1;
            f[0][r.v] = o;
            minv[0][r.v] = r.w;
            preDfs(r.v, o);
        }
    }
}
int minC = 100120929;
void lca(int x, int y) {
    if (dep[x] > dep[y]) swap(x, y);
    int t = dep[y] - dep[x];
    for (int j = 0; t; j++, t >>= 1)
        if (t & 1) minC = min(minC, minv[j][y]), y = f[j][y];
    if (y == x) return;
    for (int j = 30; j >= 0 && y != x; j--) {
        if (f[j][x] != f[j][y]) {
            minC = min(minC, minv[j][x]);
            minC = min(minC, minv[j][y]);
            x = f[j][x], y = f[j][y];
        }
    }
    minC = min(minC, min(minv[0][x], minv[0][y]));
}
int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    scanf("%d %d", &n, &m);
    for (int i = 1, u, v, w; i <= m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges.push_back({u, v, w});
        edges.push_back({v, u, w});
    }
    kruskal();
    memset(minv, 0x3f, sizeof minv);
    minv[0][1] = 0x3f3f3f3f;
    preDfs(1, 0);
    int q;
    scanf("%d", &q);
    while (q--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (find(x) != find(y)) puts("-1");
        else {
            lca(x, y);
            printf("%d\n", minC);
            minC = 0x3f3f3f3f;
        }
    }
    return 0;
}
