/*
  Problem: P2563
  Time: 2020/11/27 20:07:38
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

long long dp[201];
int prime[201];

bool judge(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int n, cnt = 0;
    for (int i = 1; i <= 200; i++)
        if (judge(i)) prime[++cnt] = i;
    while (~scanf("%d", &n)) {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= cnt; i++)
            for (int j = prime[i]; j <= 200; j++)
                dp[j] = dp[j] + dp[j - prime[i]];
        printf("%lld\n", dp[n]);
    }
    return 0;
}