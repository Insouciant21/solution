#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 210;
const int inf = 0x3f3f3f;

struct Dinic {

    int n, m, s, t;
    struct Edge {
        int u, v;
        ll cap, flow;
    };

    vector<Edge> edges;
    vector<int> G[maxn];

    void addEdge(int u, int v, ll cap) {
        edges.push_back({u, v, cap, 0});
        edges.push_back({v, u, 0, 0});
        int k = int(edges.size());
        G[u].push_back(k - 2);
        G[v].push_back(k - 1);
    }

    int d[maxn];
    bool vis[maxn];

    int cur[maxn];

    bool bfs() {
        memset(vis, 0, sizeof vis);
        fill(d, d + maxn, inf);
        queue<int> q;
        q.push(s);
        vis[s] = true, d[s] = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i : G[u]) {
                Edge &f = edges[i];
                if (!vis[f.v] && f.cap > f.flow) {
                    vis[f.v] = true;
                    d[f.v] = d[u] + 1;
                    q.push(f.v);
                }
            }
        }
        return vis[t];
    }

    ll dfs(int u, ll a) {
        if (u == t || a == 0) return a;
        ll flow = 0, f;
        for (int& i = cur[u]; i < G[u].size(); i++) {
            Edge &e = edges[G[u][i]];
            if (d[u] + 1 == d[e.v] && e.cap - e.flow) {
                f = dfs(e.v, min(a, e.cap - e.flow));
                if (f <= 0) continue;
                e.flow += f;
                edges[G[u][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }

    ll MaxFlow() {
        ll flow = 0;
        while (bfs()) {
            memset(cur, 0, sizeof cur);
            flow += dfs(s, inf);
        }
        return flow;
    }
};

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    Dinic g;
    cin >> g.n >> g.m >> g.s >> g.t;
    for (int i = 0; i < g.m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    cout << g.MaxFlow() << endl;
    return 0;
}