/*
  Problem: P1164
  Time: 2020/10/04 18:30:59
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int dp[10001];

int m, n;
int a[1001];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = m; j >= a[i]; j--) dp[j] = dp[j] + dp[j - a[i]];
    cout << dp[m] << endl;
    return 0;
}