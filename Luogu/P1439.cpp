#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int n;
int dp[maxn];
int a[maxn], b[maxn];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < 2; i++) {
        int *p = (i) ? b : a;
        for (int j = 1; j <= n; j++) scanf("%d", p + j);
    }
    int L[maxn], s[maxn];
    for (int i = 1; i <= n; i++) s[b[i]] = i;
    for (int i = 1; i <= n; i++) L[i] = s[a[i]];
    int g[maxn];
    for (int i = 0; i <= n; i++) g[i] = 0x3f3f3f;
    for (int i = 1; i <= n; i++) {
        int k = int(lower_bound(g + 1, g + 1 + n, L[i]) - g);
        dp[i] = max(dp[i - 1], k);
        g[k] = min(L[i], g[k]);
    }
    printf("%d\n", dp[n]);
    return 0;
}