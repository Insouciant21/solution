#include <bits/stdc++.h>

using namespace std;

const int maxn = int(1e4) + 100;
const int inf = numeric_limits<int>::max();

struct Edge {
    int u, v, w;
};

vector<Edge> e;
vector<int> G[maxn];

int n, m, s;

void addEdge(int u, int v, int w) {
    e.push_back({u, v, w});
    G[u].push_back(int(e.size()) - 1);
}

int ans[maxn];

struct HeapNode {
    int dist, u;
    bool operator<(const HeapNode &rhs) const { return dist > rhs.dist; }
};

bool done[maxn];

void dijkstra() {
    memset(done, 0, sizeof done);
    for (int i = 1; i <= n; i++) ans[i] = (i == s) ? 0 : inf;
    priority_queue<HeapNode> q;
    q.push((HeapNode) {0, s});
    while (!q.empty()) {
        HeapNode x = q.top();
        q.pop();
        int u = x.u;
        if (done[u]) continue;
        done[u] = true;
        for (int i = 0; i < G[u].size(); i++) {
            Edge &f = e[G[u][i]];
            int v = f.v, w = f.w;
            if (ans[v] > ans[u] + w) {
                ans[v] = ans[u] + w;
                q.push({ans[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}

int main() {
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    dijkstra();
}