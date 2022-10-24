#include <bits/stdc++.h>

using namespace std;

const int maxn = 1600;
int n, k[maxn], vis[maxn], root = 0;
vector<int> e[maxn];

long long f[maxn][3];

void dp(int u) {
    vis[u] = 1;
    f[u][0] = f[u][2] = 0, f[u][1] = k[u];
    int d = 0;
    long long md = 12312312311;
    for (int v : e[u]) {
        if (vis[v]) continue;
        dp(v);
        f[u][2] += min(f[v][1], f[v][0]);
        f[u][1] += min(f[v][1], min(f[v][0], f[v][2]));
        f[u][0] += min(f[v][1], f[v][0]);
        if (f[v][1] < f[v][0]) d++;
        md = min(f[v][1] - f[v][0], md);
    }
    if (!d) f[u][0] += md;
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1, m, x, c; i <= n; i++) {
        scanf("%d %d %d", &x, &m, &c);
        k[x] = m;
        while (c--) {
            scanf("%d", &m);
            e[x].push_back(m);
            vis[m]++;
        }
    }
    for (int i = 1; i <= n && !root; i++)
        if (!vis[i]) root = i;
    fill_n(vis, maxn, 0);
    dp(root);
    printf("%lld", min(f[root][0], f[root][1]));
    return 0;
}