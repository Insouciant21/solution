#include <bits/stdc++.h>

using namespace std;

int n, m, s;
const int maxn = 5e5 + 10;
struct Edge {
    int u, v;
    int LCA;
};
vector<Edge> e[maxn];
vector<Edge> qe;
vector<int> queryEdge[maxn];

int fa[maxn], cnt[maxn];
int vis[maxn];

int find(int x) {
    return fa[x] == x ? x : find(x);
}

void tarjan(int u) {
    fa[u] = u, vis[u] = 1;
    for (auto ex : e[u]) {
        if (!vis[ex.v]) {
            tarjan(ex.v);
            fa[ex.v] = u;
        }
    }
    for (auto x : queryEdge[u]) {
        auto &ex = qe[x];
        if (vis[ex.v]) qe[x ^ 1].LCA = ex.LCA = find(ex.v);
    }
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
        cnt[v]++;
    }
    for (int i = 0, u, v; i < m; i++) {
        scanf("%d %d", &u, &v);
        queryEdge[u].push_back(int(qe.size()));
        qe.push_back({u, v});
        queryEdge[v].push_back(int(qe.size()));
        qe.push_back({v, u});
    }
    int c = 0;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        if (cnt[i] == 0) c = i;
    }
    tarjan(c);
    for (int i = 0; i < qe.size(); i += 2) cout << qe[i].LCA << endl;
    return 0;
}
