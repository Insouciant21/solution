#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e6 + 10;

int a[maxn];
int n;
long long m;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--) {
        vector<int> e[maxn];
        memset(a, 0, sizeof a);
        scanf("%d %lld", &n, &m);
        int mx = 0, px = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] > mx) mx = a[i], px = i;
        }
        for (int i = 1, u, v; i < n; i++) {
            scanf("%d %d", &u, &v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        int nx = 0, np = 0;
        for (int v : e[px])
            if (a[v] > nx || (a[v] == nx && v < np)) nx = a[v], np = v;
        int ans;
        if (!e[px].empty()) {
            long long d = mx - nx;
            if (m < d) ans = px;
            else if (m == d) ans = min(px, np);
            else {
                m -= d;
                ans = (m & 1) ? max(np, px) : min(np, px);
            }
        }
        else ans = px;
        printf("%d\n", ans);
    }
    return 0;
}