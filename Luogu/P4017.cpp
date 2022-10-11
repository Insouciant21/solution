#include <bits/stdc++.h>

using namespace std;

const int maxn = 5010;
const int mod = 80112002;

struct Edge {
    int u, v;
};
vector<Edge> e;
vector<int> edges[maxn];

int n, m;

int in[maxn];
int f[maxn];

void topoSort(vector<int> &L) {
    queue<int> S;
    for (int i = 1; i <= n; i++)
        if (!in[i]) S.push(i), f[i] = 1;
    while (!S.empty()) {
        int r = S.front();
        S.pop(), L.push_back(r);
        for (int i : edges[r]) {
            int v = e[i].v;
            if (--in[v] == 0) S.push(v);
        }
    }
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        edges[u].push_back(int(e.size()));
        e.push_back({u, v});
        in[v]++;
    }
    vector<int> L;
    topoSort(L);
    for (int i = 0; i < n; i++) {
        for (int k : edges[L[i]]) {
            int v = e[k].v;
            f[v] = (f[v] % mod + f[L[i]] % mod) % mod;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (edges[i].empty()) ans = (ans % mod + f[i] % mod) % mod;
    cout << ans << endl;
    return 0;
}