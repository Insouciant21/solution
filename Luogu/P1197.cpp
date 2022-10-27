#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 100;
vector<int> e[maxn];
int n, m, k;
bool attack[maxn];
int f[maxn];

int fa(int x) {
    return f[x] == x ? x : f[x] = fa(f[x]);
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    cin >> k;
    vector<int> ak;
    for (int i = 0, c; i < k; i++) {
        cin >> c;
        attack[c] = true;
        ak.push_back(c);
    }
    int g = 0;
    for (int i = 0; i < n; i++) f[i] = i, g += (!attack[i]);
    stack<int> ans;
    for (int i = 0; i < n; i++) {
        if (attack[i]) continue;
        for (int v : e[i]) {
            if (!attack[i] && !attack[v] && f[fa(i)] != f[fa(v)]) {
                g--;
                f[fa(v)] = f[fa(i)];
            }
        }
    }
    reverse(ak.begin(), ak.end());
    ans.push(g);
    for (int r : ak) {
        g++, attack[r] = false;
        for (int v : e[r])
            if (!attack[v] && fa(r) != fa(v)) f[fa(r)] = f[fa(v)], g--;
        ans.push(g);
    }
    while (!ans.empty()) {
        cout << ans.top() << endl;
        ans.pop();
    }
    return 0;
}