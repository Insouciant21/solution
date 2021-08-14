/*
  Problem: CF1139A
  Time: 2021/6/19 16:29
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string k;
    long long ans = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        if ((k[i] - '0') % 2 == 0) ans += i + 1;
    }
    cout << ans << endl;
    return 0;
}
