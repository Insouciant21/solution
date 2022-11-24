#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e5 + 10;
int w[maxn];
struct Edge {
    int u, v;
};
vector<Edge> edges;
vector<int> e[maxn];
inline void addEdge(int u, int v) {
    e[u].push_back(int(edges.size()));
    edges.push_back({u, v});
}
inline void addBiEdge(int u, int v) {
    addEdge(u, v);
    addEdge(v, u);
}
int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, Q, k;
    scanf("%d %d %d", &n, &Q, &k);
    for (int i = 1; i <= n; i++) scanf("%d", w + i);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        addBiEdge(u, v);
    }

    return 0;
}
