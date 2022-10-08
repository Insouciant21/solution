#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
vector<int> E[maxn];
int d[maxn], c, cnt = 0, f[maxn];
int md[maxn];
void dfs(int u, int fa) {
    for (int v : E[u]) {
        if (v == fa) continue;
        d[v] = d[u] + 1;
        f[v] = u;
        if (d[v] > d[c]) c = v;
        dfs(v, u);
    }
}

void dfsK(int u, int fa) {
    md[u] = d[u];
    for (int v : E[u]) {
        if (v == fa) continue;
        d[v] = d[u] + 1;
        dfsK(v, u);
        md[u] = max(md[u], md[v]);
    }
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    for (int i = 0, u, v; i < n; i++) {
        cin >> u >> v;
        E[u].push_back(v), E[v].push_back(u);
    }
    dfs(1, 1);
    d[c] = 0, f[c] = 0, cnt = 1, dfs(c, c);
    vector<int> p;
    while (c) {
        p.push_back(c);
        c = f[c];
    }
    int r = p[p.size() / 2];
    memset(d, 0, sizeof d);
    dfsK(r, r);
    int ans = 0;
    for (int i = 1; i <= n; i++) md[i] = md[i] - d[i];
    sort(md + 1, md + 1 + n,greater<int>());
    for (int i = k + 1; i <= n; i++) ans = max(ans, md[i]+1);
    cout << ans << endl;
    return 0;
}