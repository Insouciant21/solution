#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e3 + 10;
struct Point {
    int x, y;
} a[maxn];
struct Edge {
    int u, v;
    double w;
};
double dist(const Point &lhs, const Point &rhs) {
    return hypot(lhs.x - rhs.x, lhs.y - rhs.y);
}
vector<Edge> edges;
vector<int> e[maxn];
void addEdge(int u, int v) {
    e[u].push_back(int(edges.size()));
    edges.push_back({u, v, dist(a[u], a[v])});
}
int fa[maxn];
int find(int x) {
    if (fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}
struct cmp {
    bool operator()(const Edge &lhs, const Edge &rhs) { return lhs.w > rhs.w; }
};
int n, k;
double kruskal() {
    priority_queue<Edge, vector<Edge>, cmp> q;
    for (auto &edge : edges) q.push(edge);
    int cnt = 0;
    while (!q.empty()) {
        Edge r = q.top();
        q.pop();
        int fx = find(r.u), fy = find(r.v);
        if (fx == fy) continue;
        fa[fy] = fx;
        cnt++;
        if (cnt == n - k + 1) return r.w;
    }
    return 0;
}
int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d %d", &a[i].x, &a[i].y);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        for (int j = i + 1; j <= n; j++) addEdge(i, j);
    }
    printf("%.2lf\n", kruskal());
    return 0;
}
