#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    cin >> n;
    int sum[maxn];
    memset(sum, 0, sizeof sum);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        sum[i] = sum[i - 1] + ((a == 0) ? -1 : a);
    }
    map<int, pair<int, int>> k;
    for (int i = 1; i <= n; i++) {
        if (!k.count(sum[i])) k[sum[i]] = make_pair(i, i);
        else k[sum[i]].second = max(k[sum[i]].second, i);
    }
    k[0].first = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, k[sum[i]].second - k[sum[i]].first);
    }
    cout << ans << endl;
    return 0;
}