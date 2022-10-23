#include <bits/stdc++.h>

using namespace std;

const int maxn = 5500;
int a[maxn];
long long f[maxn][maxn];
int n, k, x;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> k >> x;
    if (n / k > x) cout << -1 << endl;
    else {
        for (auto &i : f) fill_n(i, maxn, -1e19);
        for (int i = 1; i <= n; i++) cin >> a[i];
        f[0][0] = 0;
        for (int j = 1; j <= x; j++) {
            deque<int> q;
            for (int i = 1; i <= n; i++) {
                while (!q.empty() && q.front() < i - k) q.pop_front();
                while (!q.empty() && f[i - 1][j - 1] >= f[q.back()][j - 1]) q.pop_back();
                q.push_back(i - 1);
                f[i][j] = f[q.front()][j - 1] + a[i];
            }
        }
        long long ans = -1e18;
        for (int i = n - k + 1; i <= n; i++) ans = max(ans, f[i][x]);
        cout << ans << endl;
    }
    return 0;
}