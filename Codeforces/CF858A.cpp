/*
  Problem: CF858A
  Time: 2020/10/02 20:28:31
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

long long n, k;

int main() {
    scanf("%I64d %I64d", &n, &k);
    long long p = 1;
    for (int i = 1; i <= k; i++)
        p *= 10;
    long long x = n * p;
    long long g = __gcd(p, n);
    x /= g;
    printf("%I64d\n", x);
    return 0;
}