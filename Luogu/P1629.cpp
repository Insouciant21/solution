#include <bits/stdc++.h>

using namespace std;

const int maxn = 1100;
const int inf = 0x3f3f3f;

struct Edge {
    int u, v, w;
};

vector<Edge> e;
vector<int> G[maxn];

int n, m;

void addEdge(int u, int v, int w) {
    e.push_back({u, v, w});
    G[u].push_back(int(e.size() - 1));
}

int d[maxn][maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }
    memset(d, 0x3f, sizeof d);
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j : G[i]) {
            Edge &f = e[j];
            d[f.u][f.v] = min(d[f.u][f.v], f.w);
        }
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    long long ans = 0;
    for (int i = 1; i <= n; i++) ans += (d[1][i] + d[i][1]);
    printf("%lld\n", ans);
}