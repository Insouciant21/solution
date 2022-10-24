#include <bits/stdc++.h>

using namespace std;

const int maxn = 6e3 + 10;
int n, r[maxn], vis[maxn];
vector<int> e[maxn];
int f[maxn][2];

void dp(int u) {
    vis[u] = 1;
    int cnt = 0;
    f[u][0] = 0, f[u][1] = r[u];
    for (int v : e[u]) {
        if (vis[v]) continue;
        cnt++;
        dp(v);
        f[u][0] += max(f[v][0], f[v][1]);
        f[u][1] += f[v][0];
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", r + i);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        e[v].push_back(u);
        vis[u]++;
    }
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            c = i;
            break;
        }
    }
    memset(vis, 0, sizeof vis);
    dp(c);
    printf("%d\n", max(f[c][0], f[c][1]));
}