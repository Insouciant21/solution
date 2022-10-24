#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 100;
vector<int> e[maxn];
int vis[maxn], d[maxn], res = -1, c = -1;
int f[maxn];

void dfs(int u) {
    vis[u] = 1;
    if (d[u] > res) c = u, res = d[u];
    for (int v : e[u]) {
        if (vis[v]) continue;
        d[v] = d[u] + 1;
        dfs(v);
    }
}

void dp(int u) {
    int cnt = 0, ans = -1;
    vis[u] = 1;
    for (int v : e[u]) {
        if (vis[v]) continue;
        cnt++;
        dp(v);
        ans = max(ans, f[v]);
    }
    if (cnt) f[u] = ans + cnt;
    else f[u] = 1;
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    d[1] = 0;
    dfs(1);
    memset(vis, 0, sizeof vis);
    dfs(c);
    memset(vis, 0, sizeof vis);
    dp(c);
    res = -1;
    for (int i = 1; i <= n; i++) res = max(res, f[i]);
    cout << res << endl;
    return 0;
}