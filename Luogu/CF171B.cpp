/*
  Problem: CF171B
  Time: 2020/10/16 21:34:20
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a;
    cin >> a;
    int ans = 1;
    for (int i = 2; i <= a; i++) ans += (i - 1) * 12;
    cout << ans << endl;
    return 0;
}