#include <bits/stdc++.h>

using namespace std;
const int maxn = 5010;
struct Edge {
    int u, v, w;
};
vector<Edge> edges;
vector<int> e[maxn];
int n, m;
int fa[maxn];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
bool operator<(const Edge &lhs, const Edge &rhs) {
    return lhs.w > rhs.w;
}
int kruskal() {
    priority_queue<Edge> q;
    for (auto &i : edges) q.push(i);
    int ans = 0;
    while (!q.empty()) {
        Edge r = q.top();
        q.pop();
        int fx = find(r.u), fy = find(r.v);
        if (fx == fy) continue;
        ans += r.w;
        fa[fy] = fx;
    }
    for (int i = 2, pre = find(1); i <= n; i++)
        if (find(i) != pre) ans = -1;
    return ans;
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    scanf("%d %d", &n, &m);
    for (int i = 1, u, v, w; i <= m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        e[u].push_back(int(edges.size()));
        edges.push_back({u, v, w});
        e[v].push_back(int(edges.size()));
        edges.push_back({v, u, w});
    }
    for (int i = 1; i <= n; i++) fa[i] = i;
    int ans = kruskal();
    if (ans != -1) printf("%d\n", ans);
    else puts("orz");
    return 0;
}
