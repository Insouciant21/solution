#include <bits/stdc++.h>

using namespace std;

const int maxn = 2010;
long long f[maxn][maxn];
int n, k, vis[maxn];
struct Edge {
    int v, w;
    Edge(int a = 0, int b = 0) : v(a), w(b) {};
};
vector<Edge> e[maxn];

int dp(int u) {
    int p = 1;
    vis[u] = 1;
    fill_n(f[u], maxn, -1);
    f[u][0] = f[u][1] = 0;
    for (auto ee : e[u]) {
        int v = ee.v;
        if (vis[v]) continue;
        int sz = dp(v);
        p += sz;
        for (int i = min(p, k); i >= 0; i--) {
            if (f[u][i] != -1)
                f[u][i] += f[v][0] + sz * (n - k - sz) * ee.w;
            for (int j = min(i, sz); j; j--) {
                if (i < j) continue;
                if (f[u][i - j] == -1) continue;
                long long mx = j * (k - j) + (sz - j) * (n - k - sz + j);
                f[u][i] = max(f[u][i], f[u][i - j] + f[v][j] + mx * ee.w);
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
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }
    dp(1);
    cout << f[1][k];
    return 0;
}