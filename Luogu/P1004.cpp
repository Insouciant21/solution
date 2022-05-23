#include <bits/stdc++.h>

using namespace std;

const int maxn = 900;
const int inf = int(2e9);

int n;
int g[10][10];

struct MCMF {
    struct Edge {
        int u, v, w, cap, flow;
    };
    vector<Edge> edges;
    vector<int> G[maxn];

    void addEdge(int u, int v, int cap, int w) {
        edges.push_back({u, v, w, cap, 0});
        edges.push_back({v, u, -w, 0, 0});
        int m = int(edges.size());
        G[u].push_back(m - 2);
        G[v].push_back(m - 1);
    }

    int d[maxn] {};
    int inq[maxn] {};

    int p[maxn] {}, a[maxn] {};

    bool BF(int s, int t, int &flow, int &cost) {
        fill_n(d, maxn, inf);
        fill_n(inq, maxn, 0);
        d[s] = 0, inq[s] = 1, p[s] = 0, a[s] = inf;

        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (auto i : G[u]) {
                Edge &e = edges[i];
                if (e.cap > e.flow && d[e.v] > d[u] + e.w) {
                    d[e.v] = d[u] + e.w;
                    p[e.v] = i, a[e.v] = min(a[u], e.cap - e.flow);
                    if (!inq[e.v]) q.push(e.v), inq[e.v] = 1;
                }
            }
        }
        if (d[t] == inf) return false;
        flow += a[t];
        cost += a[t] * d[t];
        int u = t;
        while (u != s) {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
            u = edges[p[u]].u;
        }
        return true;
    }

    int mcmf(int s, int t) {
        int flow = 0, cost = 0;
        while (BF(s, t, flow, cost)) {};
        return cost;
    }
};

MCMF c;

int idx(int i, int j, int m) {
    int id = n * (i - 1) + j - 1;
    if (m) id += n * n;
    return id;
}

void buildGraph() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int in = idx(i, j, 0), out = idx(i, j, 1);
            c.addEdge(in, out, 1, -g[i][j]);
            c.addEdge(in, out, 1, 0);
            if (i != n) c.addEdge(out, idx(i + 1, j, 0), 1, 0);
            if (j != n) c.addEdge(out, idx(i, j + 1, 0), 1, 0);
        }
    }
    c.addEdge(200, 0, 2, 0);
    c.addEdge(idx(n, n, 1), 201, 2, 0);
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n;
    int x, y, k;
    memset(g, 0, sizeof g);
    while (cin >> x >> y >> k) {
        if (x == y && y == k && x == 0) break;
        g[x][y] = k;
    }
    buildGraph();
    int e = c.mcmf(200, 201);
    cout << -e << endl;
    return 0;
}