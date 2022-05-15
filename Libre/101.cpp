#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 101;
const int inf = 0x3f3f3f;

struct Dinic {
    int s, t;
    int n, m;

    struct Edge {
        int u, v;
        ll cap, flow;
    };

    vector<Edge> edges;
    vector<int> G[maxn];

    void addEdge(int u, int v, ll cap) {
        edges.push_back({u, v, cap, 0});
        edges.push_back({v, u, 0, 0});
        int b = edges.size();
        G[u].push_back(b - 2);
        G[v].push_back(b - 1);
    }

    int d[maxn];
    bool vis[maxn];
    int cur[maxn];

    bool BFS() {
        queue<int> q;
        q.push(s);
        memset(vis, 0, sizeof vis);
        fill(d, d + maxn, inf);
        d[s] = 0, vis[s] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i : G[u]) {
                Edge &e = edges[i];
                if (e.cap - e.flow > 0 && !vis[e.v]) {
                    d[e.v] = d[u] + 1;
                    vis[e.v] = true;
                    q.push(e.v);
                }
            }
        }
        return vis[t];
    }

    ll dfs(int u, ll a) {
        if (u == t || a == 0) return a;
        ll flow = 0;
        for (int &i = cur[u]; i < G[u].size(); i++) {
            Edge &e = edges[G[u][i]];
            int v = e.v;
            if (d[v] != d[u] + 1 || e.cap - e.flow <= 0) continue;
            ll k = dfs(v, min(a, e.cap - e.flow));
            if (k <= 0) continue;
            Edge &f = edges[G[u][i] ^ 1];
            e.flow += k, f.flow -= k;
            flow += k, a -= k;
            if (a == 0) break;
        }
        return flow;
    }

    ll MaxFlow() {
        ll ans = 0;
        while (BFS()) {
            memset(cur, 0, sizeof cur);
            ans += dfs(s, inf);
        }
        return ans;
    }
};

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    Dinic g;
    int n, m, s, t;
    cin >> n >> m >> g.s >> g.t;
    for (int i = 0; i < m; i++) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        g.addEdge(u, v, c);
    }
    cout << g.MaxFlow() << endl;
}
