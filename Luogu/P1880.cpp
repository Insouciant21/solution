#include <bits/stdc++.h>

using namespace std;

const int maxn = 101;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    cin >> n;
    int a[maxn], sum[maxn];
    long long f[maxn][maxn], g[maxn][maxn];
    memset(f, 0, sizeof f), memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2 * n - 1; i++) sum[i] = sum[i - 1] + a[i], g[i][i] = 0;
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= 2 * n - 1; i++) {
            int j = i + len - 1;
            long long mxm = -1, mins = 0x3f3f3f3f3f3f3f;
            for (int k = i; k < j; k++) {
                mxm = max(mxm, f[i][k] + f[k + 1][j]);
                mins = min(mins, g[i][k] + g[k + 1][j]);
            }
            f[i][j] = mxm + sum[j] - sum[i - 1], g[i][j] = mins + sum[j] - sum[i - 1];
        }
    }
    long long ans = 0x3f3f3f3f3f3f;
    for (int i = 1; i <= n; i++) ans = min(ans, g[i][i + n - 1]);
    cout << ans << endl;
    ans = -1;
    for (int i = 1; i <= n; i++) ans = max(ans, f[i][i + n - 1]);
    cout << ans << endl;
    return 0;
}