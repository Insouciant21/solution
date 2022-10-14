#include <bits/stdc++.h>

using namespace std;

const int maxs = 5e3 + 10, maxw = maxs, maxn = maxs;
long long f[maxn][maxw];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, w, s;
    cin >> n >> w >> s;
    long long a[maxn];
    for (int i = 1; i <= n; i++) cin >> a[i], fill_n(f[i], maxw, -1239127389127398);
    fill_n(f[0], maxw, -1239127389127398);
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        deque<long long> p;
        p.push_back(w);
        for (int j = w; j; j--) {
            while (!p.empty() && p.front() > j + s - 1) p.pop_front();
            while (!p.empty() && f[i - 1][p.back()] < f[i - 1][j - 1]) p.pop_back();
            p.push_back(j - 1);
            f[i][j] = f[i - 1][p.front()] + j * a[i];
        }
        /*
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= w; k++) cout << f[j][k] << " ";
            cout << endl;
        }
        cout << endl;
         */
    }
    long long ans = -1238971289371728;
    for (int i = 0; i <= w; i++) ans = max(ans, f[n][i]);
    cout << ans << endl;
    return 0;
}