/*
  Problem: P1832
  Time: 2020/10/04 18:38:55
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

bitset<1111> numlist;

long long dp[1001];

int n;

void prework() {
    numlist[0] = numlist[1] = 1;
    for (int i = 2; i <= 1110; i++)
        if (!numlist[i])
            for (int j = 2; i * j <= 1110; j++) numlist[i * j] = 1;
}

int main() {
    prework();
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (numlist[i])
            continue;
        for (int j = i; j <= n; j++) dp[j] += dp[j - i];
    }
    cout << dp[n] << endl;
    return 0;
}