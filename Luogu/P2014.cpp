#include <bits/stdc++.h>

using namespace std;

const int maxn = 320;
int f[maxn][maxn];
vector<int> e[maxn];
int n, m, s[maxn];

int dp(int u) {
    int p = 1;
    f[u][1] = s[u];
    for (auto v : e[u]) {
        int sz = dp(v);
        for (int i = min(p, m + 1); i; i--)
            for (int j = 1; j <= sz && i + j <= m + 1; j++) f[u][i + j] = max(f[u][i + j], f[u][i] + f[v][j]);
        p += sz;
    }
    return p;
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1, u; i <= n; i++) {
        cin >> u >> s[i];
        e[u].push_back(i);
    }
    dp(0);
    cout << f[0][m + 1] << endl;
    return 0;
}