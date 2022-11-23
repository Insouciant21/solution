#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e4 + 100;
int n;
struct Edge {
    int u, v;
};
vector<Edge> edges;
vector<int> e[maxn];
void addEdge(int u, int v) {
    e[u].push_back(int(edges.size()));
    edges.push_back({u, v});
}
int c[maxn], f[maxn];
int in[maxn];
int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d %d", &x, c + i);
        while (scanf("%d", &x) == 1 && x) addEdge(x, i), in[i]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        f[i] = c[i];
        if (!in[i]) q.push(i);
    }
    vector<int> L;
    while (!q.empty()) {
        int r = q.front();
        q.pop();
        L.push_back(r);
        for (auto i : e[r]) {
            Edge &ex = edges[i];
            if (--in[ex.v] == 0) q.push(ex.v);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int ed : e[i]) {
            Edge &ex = edges[ed];
            f[ex.v] = max(f[ex.v], c[ex.v] + f[i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
         ans = max(ans, f[i]);
    cout << ans << endl;
    return 0;
}
