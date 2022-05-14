#include <bits/stdc++.h>

using namespace std;

const int maxn = 300;
const int inf = 0x3f3f3f3f;

int t[maxn];

int n, m;

struct Edge {
    int u, v, w;
};

vector<Edge> e;
vector<int> G[maxn];

void addEdge(int u, int v, int w) {
    e.push_back((Edge) {u, v, w});
    e.push_back((Edge) {v, u, w});
    int g = int(e.size());
    G[u].push_back(g - 2);
    G[v].push_back(g - 1);
}

int d[maxn][maxn];

int lt = 0;

void floyd(int k) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) scanf("%d", &t[i]);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }
    int q;
    scanf("%d", &q);
    memset(d, 0x3f, sizeof d);
    for (int i = 0; i < n; i++) d[i][i] = 0;
    for (int i = 0; i < n; i++) {
        for (int j : G[i]) {
            Edge &f = e[j];
            int u = f.u, v = f.v, w = f.w;
            d[u][v] = w;
        }
    }
    while (q--) {
        int x, y, T;
        scanf("%d %d %d", &x, &y, &T);
        for (; lt < n; lt++) {
            if (t[lt] > T) break;
            floyd(lt);
        }
        printf("%d\n", (((t[x] > T || t[y] > T) || d[x][y] == inf) ? -1 : d[x][y]));
    }
}
