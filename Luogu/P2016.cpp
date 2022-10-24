#include <bits/stdc++.h>

using namespace std;

const int maxn = 1600;
int n;
struct Edge {
    int u, v;
};
vector<int> e[maxn];
int vis[maxn];
int f[maxn][2];

void dp(int u) {
    int cnt = 0;
    int ans1 = 0, ans2 = 1;
    vis[u] = true;
    for (int i : e[u]) {
        if (vis[i]) continue;
        cnt++;
        dp(i);
        ans1 += f[i][1], ans2 += min(f[i][0], f[i][1]);
    }
    if (cnt) f[u][0] = ans1, f[u][1] = ans2;
    else f[u][0] = 0, f[u][1] = 1;
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 0, k, c, d; i < n; i++) {
        cin >> k >> c;
        while (c--) {
            cin >> d;
            e[k].push_back(d);
            e[d].push_back(k);
        }
    }
    dp(0);
    cout << min(f[0][0], f[0][1]);
    return 0;
}