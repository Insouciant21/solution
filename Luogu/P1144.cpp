#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1000100;
const int p = 100003;

int n, m;

struct Edge {
    int u, v;
};

vector<Edge> e;
vector<int> G[maxn];

void addEdge(int u, int v) {
    e.push_back({u, v});
    e.push_back({v, u});
    int f = int(e.size());
    G[u].push_back(f - 2);
    G[v].push_back(f - 1);
}

ll ans[maxn];
ll d[maxn];
bool vis[maxn];

void bfs(int s) {
    queue<int> q;
    memset(vis, 0, sizeof vis);
    d[s] = 0, ans[s] = 1, vis[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i : G[u]) {
            Edge &f = e[i];
            int v = f.v;
            if (!vis[v]) {
                vis[v] = true, d[v] = d[u] + 1;
                q.push(v);
            }
            if (d[v] == d[u] + 1) ans[v] = (ans[v] + ans[u]) % p;
        }
    }
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    bfs(1);
    for (int i = 1; i <= n; i++) printf("%lld\n", ans[i]);
    return 0;
}