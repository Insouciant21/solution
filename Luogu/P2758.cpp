#include <bits/stdc++.h>

using namespace std;

const int maxn = 2010;

int dp[maxn][maxn];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    string a, b;
    cin >> a >> b;
    for (int i = 0; i <= a.size(); i++) dp[i][0] = i;
    for (int i = 0; i <= b.size(); i++) dp[0][i] = i;
    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
    }
    cout << dp[a.length()][b.length()] << endl;
    return 0;
}