#include <bits/stdc++.h>

using namespace std;

const int maxn = 10010;

int n, c;
vector<int> E[maxn];

int vis[maxn];
int d[maxn];

void dfs(int u, int fa) {
    for (int v : E[u]) {
        if (v == fa) continue;
        d[v] = d[u] + 1;
        if (d[v] > d[c]) c = v;
        dfs(v, u);
    }
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 0, u, v; i < n; i++) {
        cin >> u >> v;
        E[u].push_back(v), E[v].push_back(u);
    }
    dfs(1, 0);
    d[c] = 0, dfs(c, 0);
    cout << d[c] << endl;
    return 0;
}