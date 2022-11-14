#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e3 + 100;

int n, m;
struct Edge {
    int u, v, w;
};
vector<Edge> edges;
vector<int> e[maxn];

void addEdge(int u, int v, int w) {
    e[u].push_back(int(edges.size()));
    edges.push_back({u, v, w});
}

int dis[maxn], vis[maxn], cnt[maxn];

bool spfa(int s) {
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
                if (cnt[v] >= n) return false;
                if (!vis[v]) q.push(v), vis[v] = 1;
            }
        }
    }
    return true;
}

void initialize() {
    memset(dis, 0x3f, sizeof dis);
    memset(cnt, 0, sizeof cnt);
    memset(vis, 0, sizeof vis);
    edges.clear();
    memset(e, 0, sizeof e);
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--) {
        initialize();
        scanf("%d %d", &n, &m);
        for (int i = 1, u, v, w; i <= m; i++) {
            scanf("%d %d %d", &u, &v, &w);
            if (w < 0) addEdge(u, v, w);
            else addEdge(u, v, w), addEdge(v, u, w);
        }
        bool f = spfa(1);
        if (f) puts("NO");
        else puts("YES");
    }
    return 0;
}
