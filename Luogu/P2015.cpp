#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;
int n, q, vis[maxn];
int f[maxn][maxn];
struct Edge {
    int v, apples;
    Edge(int a = 0, int b = 0) : v(a), apples(b) {};
};
vector<Edge> e[maxn];

int dp(int u) {
    int p = 0;
    vis[u] = 1;
    for (auto ee : e[u]) {
        int v = ee.v;
        if (vis[v]) continue;
        int sz = dp(v);
        p += sz + 1;
        for (int i = p; i >= 1; i--) {
            for (int j = 0; j <= sz; j++) {
                if (i < j + 1) continue;
                f[u][i] = max(f[u][i], f[u][i - j - 1] + f[v][j] + ee.apples);
            }
        }
    }
    return p;
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> q;
    for (int i = 1, u, v, c; i < n; i++) {
        cin >> u >> v >> c;
        e[u].emplace_back(v, c);
        e[v].emplace_back(u, c);
    }
    dp(1);
    cout << f[1][q] << endl;
    return 0;
}