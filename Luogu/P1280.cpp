#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;

struct Edge {
    int u, v, w;
};

int n, k, dp[maxn];
vector<Edge> e;
vector<int> px[maxn];
// int w[maxn][maxn];

int DP(int u) {
    if (dp[u] > 0) return dp[u];
    for (int t : px[u]) {
        int v = e[t].v;
        dp[u] = max(dp[u], DP(v) + e[t].w);
    }
    return dp[u];
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> k;
    // memset(w, 0x3f, sizeof w);
    for (int i = 1; i <= k; i++) {
        int p, t;
        cin >> p >> t;
        px[p - 1].push_back(int(e.size()));
        e.push_back({p - 1, p + t - 1, 0});
    }
    for (int i = 0; i < n; i++)
        if (px[i].empty()) px[i].push_back(int(e.size())), e.push_back({i, i + 1, 1});
    cout << DP(0) << endl;
    return 0;
}