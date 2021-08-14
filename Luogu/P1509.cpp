/*
  Problem: P1509
  Time: 2020/10/04 18:12:28
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int dp[101][101];
int f[101][101];

int n, m, r;

int rmb[101], rp[101], t[101];
int cnt;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d %d", &rmb[i], &rp[i], &t[i]);
    scanf("%d %d", &m, &r);
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= rmb[i]; j--) {
            for (int k = r; k >= rp[i]; k--) {
                if (dp[j][k] == dp[j - rmb[i]][k - rp[i]] + 1)
                    f[j][k] = min(f[j][k], f[j - rmb[i]][k - rp[i]] + t[i]);
                else if (dp[j][k] < dp[j - rmb[i]][k - rp[i]] + 1) {
                    dp[j][k] = dp[j - rmb[i]][k - rp[i]] + 1;
                    f[j][k] = f[j - rmb[i]][k - rp[i]] + t[i];
                }
            }
        }
    }
    printf("%d\n", f[m][r]);
    return 0;
}