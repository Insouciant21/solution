/*
  Problem: P2424
  Time: 2020/10/22 19:47:33
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

long long solve(long long n) {
    long long res = 0;
    for (long long l = 1, r; l <= n; l = r + 1) {
        r = n / (n / l);
        res += (n / l) * (r - l + 1) * (l + r) / 2;
    }
    return res;
}

int main() {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    printf("%lld\n", solve(y) - solve(x - 1));
    return 0;
}