// 又学到了

#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int v;
    int c;
};

vector<vector<Edge>> graph;

int n, m;

int d[100001];
bool vis[100001];
vector<int> ans;

void bfsEnd() {
    memset(vis, 0, sizeof vis);
    queue<int> q;
    q.push(n);
    d[n] = 0;
    vis[n] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == 1) break;
        for (auto &i : graph[u]) {
            if (vis[i.v]) continue;
            q.push(i.v);
            d[i.v] = d[u] + 1;
            vis[i.v] = true;
        }
    }
}

void bfsStart() {
    memset(vis, 0, sizeof vis);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    for (int step = d[n]; step < d[1]; step++) {
        int minc = numeric_limits<int>::max();
        int f = int(q.size());
        for (int i = 0; i < f; i++) {
            int u = q.front();
            q.pop();
            for (auto e : graph[u])
                if (d[u] == d[e.v] + 1) minc = min(minc, e.c);
            q.push(u);
        }
        ans.push_back(minc);
        for (int i = 0; i < f; i++) {
            int u = q.front();
            q.pop();
            for (auto e : graph[u])
                if (d[u] == d[e.v] + 1 && !vis[e.v] && e.c == minc) q.push(e.v), vis[e.v] = true;
        }
    }
}

int main() {
    while (scanf("%d %d", &n, &m) == 2) {
        graph.clear(), ans.clear();
        memset(d, 0, sizeof d);
        graph.resize(n + 1);
        for (int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            Edge t0 {}, t1 {};
            t0.v = a, t1.v = b;
            t0.c = t1.c = c;
            graph[a].push_back(t1);
            graph[b].push_back(t0);
        }
        bfsEnd();
        printf("%d\n", d[1]);
        bfsStart();
        for (int i = 0; i < ans.size(); i++) printf(i == 0 ? "%d" : " %d", ans[i]);
        printf("\n");
    }
    return 0;
}
