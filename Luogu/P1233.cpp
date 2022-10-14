#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

bool cmp(const pii &a, const pii &b) {
    if (a.first == b.first) return a.second > b.second;
    else return a.first > b.first;
}

const int maxn = 5010;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    cin >> n;
    pii a[maxn];
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + 1 + n, cmp);
    int f[maxn], ans = 0;
    fill_n(f, maxn, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++)
            if (a[j].second < a[i].second) f[i] = max(f[j] + 1, f[i]);
        ans = max(f[i], ans);
    }
    cout << ans << endl;
    return 0;
}