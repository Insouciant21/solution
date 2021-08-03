/*
  Problem: P1832
  Time: 2020/10/04 18:38:55
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

bitset<1111> numList;

long long dp[1001];

int n;

void preWork() {
    numList[0] = numList[1] = 1;
    for (int i = 2; i <= 1110; i++)
        if (!numList[i])
            for (int j = 2; i * j <= 1110; j++)
                numList[i * j] = 1;
}

int main() {
    preWork();
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (numList[i]) continue;
        for (int j = i; j <= n; j++) dp[j] += dp[j - i];
    }
    cout << dp[n] << endl;
    return 0;
}