#include <bits/stdc++.h>

using namespace std;

int n, m;
long long dp[40][40];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m;
    dp[1][0] = 1;
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n ; i++) {
            dp[i][j] = dp[(i - 1 == 0) ? n : i - 1][j - 1] + dp[(i ==n) ? 1 : i + 1][j - 1];
        }
    }
    long long ans = 0;
    cout << dp[1][m] << endl;
    return 0;
}