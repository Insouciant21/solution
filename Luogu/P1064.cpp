#include <bits/stdc++.h>

using namespace std;
int n, m;
struct Item {
    int v {}, p {};
    vector<int> q;
} a[70];
int f[70][32000];
void dp(int u, int t) {
    if (t <= 0) return;
    for (int v : a[u].q) {
        for (int k = n - a[v].v; k >= 0; k--) f[v][k] = f[u][k] + a[v].v * a[v].p;
        dp(v, t - a[v].v);
        for (int k = n; k >= a[v].v; k--) f[u][k] = max(f[u][k], f[v][k - a[v].v]);
    }
}
int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m;
    a[0].v = a[0].p = 0;
    for (int i = 1, x; i <= m; i++) {
        cin >> a[i].v >> a[i].p >> x;
        if (x != 0) a[x].q.push_back(i);
        else a[0].q.push_back(i);
    }
    dp(0, n);
    int ans = 0;
    for (int i = 0; i <= n; i++) ans = max(f[0][i], ans);
    cout << ans << endl;
    return 0;
}
