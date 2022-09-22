#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

int f[maxn];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> a;
    int l = maxn - 1, r = -1;
    for (int i = 0, t; i < n; i++) {
        cin >> t;
        a.push_back(t);
        if (t == 2) l = min(l, i);
        if (t == 3) r = i;
        f[i] = (i == 0 ? 0 : f[i - 1]) + (t == 1);
    }
    int ans = f[n - 1];
    if (l != maxn - 1) ans = max(ans, f[n - 1] - f[l] + 1);
    if (r != -1) ans = max(ans, f[r] + 1);
    if (l != maxn - 1 && r != -1) ans = max(ans, (r < l) ? 0 : f[r] - f[l] + 2);
    cout << ans << endl;
    return 0;
}