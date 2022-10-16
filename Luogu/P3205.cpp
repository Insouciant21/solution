#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010, mod = 19650827;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int f[maxn][maxn], g[maxn][maxn];
    int a[maxn], n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], f[i][i] = 1;
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n; i++) {
            int j = i + len - 1;
            f[i][j] = (f[i + 1][j] * (a[i] < a[i + 1]) + g[i + 1][j] * (a[i] < a[j])) % mod;
            g[i][j] = (f[i][j - 1] * (a[i] < a[j]) + g[i][j - 1] * (a[j] > a[j - 1])) % mod;
        }
    }
    cout << (f[1][n] + g[1][n]) % mod;
    return 0;
}