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
    memset(fa, 0, sizeof fa);
}
int sz[maxn], dep[maxn], hson[maxn];
int top[maxn], dfn[maxn], rk[maxn];
void preDfs(int o) {
    hson[o] = -1, sz[o] = 1;
    for (int i : e[o]) {
        Edge &r = edges[i];
        if (!dep[r.v]) {
            dep[r.v] = dep[o] + 1;
            fa[r.v] = o;
            preDfs(r.v);
            sz[o] += sz[r.v];
            if (hson[o] == -1 || sz[r.v] > sz[hson[o]]) hson[o] = r.v;
        }
    }
}
void dfs(int o,int t){

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
    preDfs(1),
    return 0;
}
