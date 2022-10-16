#include <bits/stdc++.h>

using namespace std;

const int maxn = 320;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    long long f[maxn][maxn];
    int a[maxn], r[maxn];
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2 * n - 1; i++) r[i] = a[i + 1];
    for (int len = 1; len <= n; len++) {
        for (int i = 1; i <= 2 * n - 1; i++) {
            int j = i + len - 1;
            for (int k = i; k < j; k++) f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + a[i] * r[k] * r[j]);
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[i][i + n - 1]);
    cout << ans << endl;
    return 0;
}