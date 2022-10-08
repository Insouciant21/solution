#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000;

struct Edge {
    int u, v, w;
};
vector<Edge> edges;
vector<int> E[maxn];
int vx[maxn], W[maxn][maxn];
int d[maxn], c, f[maxn];
int md[maxn], nd[maxn];
int vis[maxn];
void dfs(int u, int fa) {
    for (int e : E[u]) {
        int v = edges[e].v;
        Edge &p = edges[e];
        if (v == fa) continue;
        d[v] = d[u] + p.w;
        f[v] = u;
        if (d[v] > d[c]) c = v;
        dfs(v, u);
    }
}

void dfs3(int u, int fa) {
    nd[u] = d[u];
    for (int e : E[u]) {
        Edge &p = edges[e];
        int v = p.v;
        if (v == fa) continue;
        if (vx[v]) continue;
        d[v] = d[u] + p.w;
        f[v] = u;
        dfs3(v, u);
        nd[u] = max(nd[u], nd[v]);
    }
}

void dfsK(int u, int fa) {
    md[u] = d[u];
    for (int e : E[u]) {
        Edge &p = edges[e];
        int v = p.v;
        if (v == fa) continue;
        if (vis[v]) continue;
        d[v] = d[u] + p.w;
        f[v] = u;
        dfsK(v, u);
        md[u] = max(md[u], md[v]);
    }
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        E[u].push_back(edges.size() - 1);
        edges.push_back({v, u, w});
        E[v].push_back(edges.size() - 1);
        W[v][u] = W[u][v] = w;
    }
    dfs(1, 1);
    d[c] = 0, f[c] = 0, dfs(c, c);
    vector<int> p;
    while (c) {
        p.push_back(c);
        vx[c] = true;
        c = f[c];
    }
    memset(d, 0, sizeof d);
    for (int i : p) dfs3(i, i);
    int ans = 129031203;
    int b = 0, len = 0;
    for (int a = 0; a < p.size(); a++) {
        while (b + 1 < p.size() && len + W[p[b + 1]][p[b]] <= k) b++, len += W[p[b - 1]][p[b]];
        memset(vis, 0, sizeof vis);
        memset(md, 0, sizeof md);
        memset(d, 0, sizeof d);
        int mxm = 0;
        vis[p[a]] = vis[p[b]] = 1;
        for (int i = a + 1; i < b; i++) {
            mxm = max(mxm, nd[p[i]]);
            vis[p[i]] = 1;
        }
        dfsK(p[a], p[a]);
        memset(d, 0, sizeof d);
        dfsK(p[b], p[b]);
        mxm = max(mxm, max(md[p[a]], md[p[b]]));
        ans = min(ans, mxm);
        if (a + 1 != p.size()) len -= W[p[a]][p[a + 1]];
        if (b == p.size() - 1) break;
    }
    cout << ans << endl;
    return 0;
}