#include <bits/stdc++.h>

using namespace std;

const int maxm = 100, mod = 1e6 + 7, maxn = maxm;
int f[maxm * 2], vis[maxm];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    int a[maxn];
    for (int i = 1; i <= n; i++) cin >> a[i];
    fill_n(f, maxm * 2, 0);
    f[0] = 1, vis[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 0; j--) {
            if (!vis[j]) continue;
            for (int k = a[i]; k >= 1; k--) f[j + k] = (f[j + k] % mod + f[j] % mod) % mod;
        }
        for (int j = 0; j <= m; j++) {
            if (!vis[j]) continue;
            for (int k = 1; k <= a[i]; k++) vis[j + k] = true;
        }
    }
    cout << f[m] << endl;
    return 0;
}