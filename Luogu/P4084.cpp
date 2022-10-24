#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 100, mod = 1e9 + 7;
vector<int> e[maxn];
int n, k, c[maxn];
int f[maxn][4], vis[maxn];

void dp(int u) {
    vis[u] = 1;
    for (int i = 1; i <= 3; i++) {
        if (f[u][i]) {
            for (int j = 1; j < i; j++) f[u][j] = 0;
            break;
        }
        f[u][i] = 1;
    }
    for (int v : e[u]) {
        if (vis[v]) continue;
        dp(v);
        f[u][1] = (f[u][1] * (f[v][3] + f[v][2]) % mod) % mod;
        f[u][2] = (f[u][2] * (f[v][3] + f[v][1]) % mod) % mod;
        f[u][3] = (f[u][3] * (f[v][1] + f[v][2]) % mod) % mod;
    }
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    scanf("%d %d", &n, &k);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        e[u].push_back(v), e[v].push_back(u);
    }
    for (int i = 1, t, v; i <= k; i++) {
        scanf("%d %d", &v, &t);
        f[v][t] = 1;
    }
    dp(1);
    printf("%d\n", (f[1][1] % mod + f[1][2] % mod + f[1][3] % mod) % mod);
    return 0;
}