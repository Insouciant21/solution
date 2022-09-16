#include <bits/stdc++.h>

using namespace std;

const int maxn = 20010;

bool c[maxn], r[maxn], d1[maxn * 3], d2[maxn * 3];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        r[a] = c[b] = true;
        d1[abs(a - n) + abs(b - 1)] = d2[abs(a - 1) + abs(b - 1)] = true;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (r[i]) continue;
        for (int j = 1; j <= m; j++)
            if (!(r[i] || c[j] || d1[abs(i - n) + abs(j - 1)] || d2[abs(i - 1) + abs(j - 1)])) ans++;
    }
    cout << ans << endl;
    return 0;
}