#include <bits/stdc++.h>

using namespace std;

const int maxn = 510;

int n, m;
int s[maxn], d[maxn];
int f[maxn][maxn], dp[maxn][maxn];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 2; i <= n; i++) cin >> d[i], s[i] = s[i - 1] + d[i];
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            int mid = (l + r) >> 1;
            for (int k = l; k <= r; k++) f[l][r] += abs(s[mid] - s[k]);
        }
    }
    memset(dp, 0, sizeof dp);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i; j++) dp[i][j] = 0x3f3f3f;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            for (int k = j - 1; k <= i; k++) dp[i][j] = min(dp[i][j], dp[k][j - 1] + f[k + 1][i]);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}