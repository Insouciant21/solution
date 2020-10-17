/*
  Problem: P3935
  Time: 2020/10/15 22:08:34
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

long long solve(long long x) {
    long long res = 0;
    for (long long l = 1, r; l <= x; l = r + 1) {
        r = x / (x / l);
        long long len = (r - l + 1) % mod;
        res = (res + (len * (x / l) % mod)) % mod;
    }
    return res;
}

int main() {
    long long a, b;
    long long s1 = 0, s2 = 0;
    cin >> a >> b;
    cout << ((solve(b) - solve(a - 1)) % mod + mod) % mod << endl;
    return 0;
}
