#include <bits/stdc++.h>

using namespace std;
int n, m;
const int maxn = 5e4 + 10;
struct Edge {
    int u, v, w;
};
vector<Edge> edges;
vector<int> e[maxn];

void addEdge(int u, int v, int w) {
    e[u].push_back(int(edges.size()));
    edges.push_back({u, v, w});
}
int ans;
multiset<int> s[maxn];
int dfs(int u, int fa, int lim) {
    s[u].clear();
    int val;
    for (int i : e[u]) {
        Edge &r = edges[i];
        if (r.v == fa) continue;
        val = dfs(r.v, u, lim) + r.w;
        if (val >= lim) ans++;
        else s[u].insert(val);
    }
    int len = 0;
    while (!s[u].empty()) {
        int res = *s[u].begin();
        if (s[u].size() == 1) return max(len, res);
        auto it = s[u].lower_bound(lim - res);
        if (it == s[u].begin() && s[u].count(*it) == 1) it++;
        if (it == s[u].end()) {
            len = max(len, res);
            s[u].erase(s[u].find(res));
        }
        else {
            ans++;
            s[u].erase(s[u].find((*it)));
            s[u].erase(s[u].find(res));
        }
    }
    return len;
}

bool check(int mx) {
    ans = 0;
    return dfs(1, 0, mx) >= mx;
}
int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int l = 0, r = 0;
    for (int i = 1, u, v, w; i < n; i++) {
        cin >> u >> v >> w;
        addEdge(u, v, w), addEdge(v, u, w);
        r += w;
    }
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}
