#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e3 + 100;
const int maxc = 1e9;

int n, m;
struct Edge {
    int u, v, w;
};
vector<Edge> edges;
vector<int> e[maxn];

int dis[maxn], cnt[maxn], vis[maxn];

bool spfa(int s) {
    fill_n(dis, maxn, 0x3f3f3f3f);
    dis[s] = 0, vis[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto ide : e[u]) {
            auto &ex = edges[ide];
            int v = ex.v, w = ex.w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] > n) return false;
                if (!vis[v]) q.push(v), vis[v] = 1;
            }
        }
    }
    return true;
}

int dist[maxn];
int s;

struct Node {
    int u;
    int dis;
    bool operator<(Node rhs) const { return dis > rhs.dis; }
};

void dijkstra() {
    memset(vis, 0, sizeof vis);
    dist[s] = 0;
    priority_queue<Node> q;
    q.push({s, 0});
    while (!q.empty()) {
        auto u = q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto ide : e[u]) {
            auto &ex = edges[ide];
            int v = ex.v, w = ex.w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!vis[v]) q.push({v, dist[v]});
            }
        }
    }
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
    }
    for (int i = 1; i <= n; i++) {
        e[0].push_back(int(edges.size()));
        edges.push_back({0, i, 0});
    }
    bool f = spfa(0);
    if (!f) puts("-1");
    else {

        for (auto &ex : edges) ex.w = ex.w + dis[ex.u] - dis[ex.v];
        for (s = 1; s <= n; s++) {
            memset(dist, 0x3f, sizeof dist);
            dijkstra();
            long long res = 0;
            for (int j = 1; j <= n; j++) {
                if (dist[j] >= 0x3f3f3f3f) res += (long long)maxc * j;
                else res += ((long long)dist[j] - dis[s] + dis[j]) * j;
            }
            printf("%lld\n", res);
        }
    }
    return 0;
}
