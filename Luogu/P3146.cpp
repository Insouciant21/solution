#include <bits/stdc++.h>

using namespace std;

const int maxn = 260;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int f[maxn][maxn];
    int a[maxn], n;
    cin >> n;
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[i][i] = a[i];
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n; i++) {
            int j = i + len - 1;
            for (int k = i; k < j && k <= n; k++) {
                if (f[i][k] == f[k + 1][j]) f[i][j] = max(f[i][j], f[i][k] + 1);
                // else f[i][j] = max(f[i][k], f[k + 1][j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) ans = max(ans, f[i][j]);
    }
    cout << ans << endl;
    return 0;
}