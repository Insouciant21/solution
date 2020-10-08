/*
  Problem: P1510
  Time: 2020/10/04 21:06:18
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int v, n, c;

int dp[10001];
int p[10001], m[10001];

int main() {
    cin >> v >> n >> c;
    for (int i = 1; i <= n; i++) cin >> p[i] >> m[i];
    for (int i = 1; i <= n; i++) {
        for (int j = c; j >= m[i]; j--) {
            dp[j] = max(dp[j], dp[j - m[i]] + p[i]);
        }
    }
    for (int i = 1; i <= c; i++) {
        if (dp[i] > v) {
            cout << c - i << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;
    return 0;
}