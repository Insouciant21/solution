#include <bits/stdc++.h>

using namespace std;
const int maxn = 1010, modp = int(1e9) + 7;
int v[maxn], w[maxn];
int f[maxn];
int cnt[maxn];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, V;
    cin >> n >> V;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    fill_n(cnt, sizeof cnt / sizeof(int), 1);
    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= v[i]; j--) {
            int t = f[j - v[i]] + w[i];
            if (t > f[j]) f[j] = t, cnt[j] = cnt[j - v[i]];
            else if (t == f[j]) cnt[j] = (cnt[j] + cnt[j - v[i]]) % modp;
        }
    }
    cout << cnt[V] << endl;
    return 0;
}