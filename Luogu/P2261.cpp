/*
  Problem: P2261
  Time: 2020/10/11 09:54:54
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

long long n, k;

int main() {
    scanf("%lld %lld", &n, &k);
    long long ans = n * k;
    long long res = 0;
    for (long long l = 1, r; l <= min(n, k); l = r + 1) {
        r = min(k / (k / l), n);
        res += (k / l) * (l + r) * (r + 1 - l) / 2;
    }
    printf("%lld\n", ans - res);
    return 0;
}