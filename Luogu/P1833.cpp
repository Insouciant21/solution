/*
  Problem: P1833
  Time: 2020/10/04 17:12:52
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = int(1e6) + 1;

int dp[maxn];
int t[maxn], c[maxn];

int n, ti;
int cnt;

int main() {
    int sth, stm, edh, edm;
    scanf("%d:%d %d:%d %d", &sth, &stm, &edh, &edm, &n);
    ti = edh * 60 + edm - sth * 60 - stm;
    for (int i = 1; i <= n; i++) {
        int t1, t2, t3, p = 1;
        scanf("%d %d %d", &t1, &t2, &t3);
        if (t3 == 0)
            t3 = maxn - 2;
        while (t3 - p > 0) {
            t3 -= p;
            t[++cnt] = t1 * p;
            c[cnt] = t2 * p;
            p *= 2;
        }
        t[++cnt] = t1 * t3;
        c[cnt] = t2 * t3;
    }
    for (int i = 1; i <= cnt; i++)
        for (int j = ti; j >= t[i]; j--) dp[j] = max(dp[j], dp[j - t[i]] + c[i]);
    printf("%d\n", dp[ti]);
    return 0;
}