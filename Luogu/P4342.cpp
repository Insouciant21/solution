#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int f[maxn][maxn], g[maxn][maxn];
    int a[maxn], r[maxn], n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c >> a[i];
        r[i] = r[i + n] = c == 't' ? 1 : -1;
        a[i + n] = a[i];
    }
    int ans = -1238827312;
    vector<int> x;
    for (int rm = 1; rm <= n; rm++) {
        for (int i = 1; i <= 2 * n; i++) fill_n(f[i], maxn, -0x3f3f3f3f), fill_n(g[i], maxn, 0x3f3f3f);
        for (int i = 1; i <= 2 * n; i++) f[i][i] = a[i], g[i][i] = a[i];
        for (int len = 2; len <= n; len++) {
            for (int i = rm; i <= 2 * n; i++) {
                int j = i + len - 1;
                for (int k = i; k < j && k <= rm + n - 1; k++) {
                    if (r[k + 1] == 1)
                        f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j]), g[i][j] = min(g[i][j], g[i][k] + g[k + 1][j]);
                    if (r[k + 1] == -1) {
                        f[i][j] = max(f[i][j], f[i][k] * f[k + 1][j]);
                        f[i][j] = max(f[i][j], g[i][k] * g[k + 1][j]);
                        g[i][j] = min(g[i][j], g[i][k] * g[k + 1][j]);
                        g[i][j] = min(g[i][j], f[i][k] * f[k + 1][j]);
                    }
                }
            }
        }
        if (f[rm][rm + n - 1] > ans) x.clear();
        if (f[rm][rm + n - 1] >= ans) {
            ans = max(ans, f[rm][rm + n - 1]);
            x.push_back(rm);
        }
    }
    cout << ans << endl;
    for (int i : x) cout << i << " ";
    return 0;
}