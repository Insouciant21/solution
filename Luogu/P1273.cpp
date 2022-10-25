#include <bits/stdc++.h>

using namespace std;

const int maxn = 3100;
int f[maxn][maxn * 10];
int n, m, w[maxn];
struct Edge {
    int v, cost;
    explicit Edge(int a = 0, int b = 0) : v(a), cost(b) {};
};
vector<Edge> e[maxn];

int dp(int u) {
    int p = 0;
    if (u >= n - m + 1) f[u][1] = w[u], f[u][0] = 0, p = 1;
    for (auto ee : e[u]) {
        int sz = dp(ee.v);
        p += sz;
        for (int i = p; i >= 0; i--) {
            for (int j = 1; j <= sz; j++) {
                if (i - j < 0) continue;
                f[u][i] = max(f[u][i], f[u][i - j] + f[ee.v][j] - ee.cost);
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
    memset(f, 0xcf, sizeof f);
    cin >> n >> m;
    for (int i = 1, k, v, s; i <= n - m; i++) {
        cin >> k;
        while (k--) {
            cin >> v >> s;
            e[i].emplace_back(v, s);
        }
        f[i][0] = 0;
    }
    for (int i = n - m + 1; i <= n; i++) {
        cin >> w[i];
        f[i][0] = 0;
    }
    dp(1);
    for (int i = m; i >= 0; i--) {
        if (f[1][i] >= 0) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}