#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010, maxv = 20010, mod = 998244353;
int dp[maxn][2 * maxv];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    cin >> n;
    int a[maxn], v = -1;
    for (int i = 1; i <= n; i++) cin >> a[i], v = max(a[i], v);
    for (int i = 1; i <= n; i++) fill_n(dp[i], maxv * 2, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j > 0; j--) {
            int d = a[i] - a[j];
            dp[i][d + v] = (dp[i][d + v] % mod + dp[j][d + v] % mod) % mod;
        }
    }
    int ans = n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 2 * v; j++) ans = (ans % mod + (dp[i][j] - 1) % mod) % mod;
    cout << ans << endl;
    return 0;
}