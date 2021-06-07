/*
  Problem: P3926
  Time: 2021/6/7 9:31
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

long long a, c, p, q, r, x;
long long ans = 0;

int main() {
    cin >> a >> c >> p >> q >> r >> x;
    if (a < c) {
        long long k = (c - a) * p;
        if (k > x)
            ans = a + x / p;
        else if (k == x)
            ans = c;
        else if (k + q >= x)
            ans = c;
        else
            ans = (x - k - q) / r + c;
    }
    else if (a == c) {
        if (x >= q)
            ans = c;
        else
            ans = (x - q) / r + c;
    }
    else
        ans = x / r + a;
    cout << ans << endl;
    return 0;
}
