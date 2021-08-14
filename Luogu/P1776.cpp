/*
  Problem: P1776
  Time: 2020/10/04 16:20:18
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int dp[int(1e5) + 10];

int n, W;
int v[int(1e5) + 10];
int w[int(1e5) + 10];

int main() {
    register int cnt = 1;
    scanf("%d %d", &n, &W);
    for (register int i = 1; i <= n; i++) {
        int c = 1;
        int t1, t2, t3;
        scanf("%d %d %d", &t1, &t2, &t3);
        while (t3 - c > 0) {
            t3 -= c;
            v[++cnt] = c * t1;
            w[cnt] = c * t2;
            c *= 2;
        }
        v[++cnt] = t3 * t1;
        w[cnt] = t3 * t2;
    }
    for (register int i = 1; i <= cnt; i++)
        for (register int j = W; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    printf("%d\n", dp[W]);
    return 0;
}