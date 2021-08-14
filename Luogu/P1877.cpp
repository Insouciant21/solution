/*
  Problem: P1877
  Time: 2020/10/15 21:51:19
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;
bool dp[51][1010];
int c[51];
int n;
int maxn, st;

int main() {
    cin >> n >> st >> maxn;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    dp[0][st] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = maxn; j >= 0; j--) {
            if (dp[i - 1][j]) {
                if (j + c[i] <= maxn) {
                    dp[i][j + c[i]] = 1;
                }
                if (j - c[i] >= 0) {
                    dp[i][j - c[i]] = 1;
                }
            }
        }
    }
    for (int i = maxn; i >= 1; i--) {
        if (dp[n][i]) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}