#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;
int fail[maxn], succ[maxn], use[maxn];
long long dp[maxn];
int n, x;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> fail[i] >> succ[i] >> use[i];
    for (int i = 1; i <= n; i++) {
        for (int j = x; j >= 0; j--) {
            if (j >= use[i]) dp[j] = max(dp[j] + fail[i], dp[j - use[i]] + succ[i]);
            else dp[j] += fail[i];
        }
    }
    cout << dp[x] * 5 << endl;
    return 0;
}