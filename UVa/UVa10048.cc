#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;

long long G[maxn][maxn];
long long d[maxn][maxn];

const long long inf = numeric_limits<long long>::max();

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int c, s, q;
    for (int kase = 1;; kase++) {
        cin >> c >> s >> q;
        if (c == s && s == q && c == 0) break;
        if (kase != 1) puts("");
        printf("Case #%d\n", kase);
        memset(G, 0, sizeof G);
        for (int i = 1; i <= c; i++)
            for (int j = 1; j <= c; j++) d[i][j] = (i == j) ? 0 : inf;
        for (int i = 0; i < s; i++) {
            long long u, v, w;
            scanf("%lld %lld %lld", &u, &v, &w);
            G[u][v] = G[v][u] = d[u][v] = d[v][u] = w;
        }
        for (int k = 1; k <= c; k++)
            for (int i = 1; i <= c; i++)
                for (int j = 1; j <= c; j++) d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
        while (q--) {
            int x, y;
            scanf("%d %d", &x, &y);
            long long &f = d[x][y];
            if (f == inf) puts("no path");
            else printf("%lld\n", f);
        }
    }
    return 0;
}