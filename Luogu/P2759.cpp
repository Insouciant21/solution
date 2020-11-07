/*
  Problem: P2759
  Time: 2020/11/04 18:42:28
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    long long l = 0, r = 2147483647;
    long long n;
    scanf("%lld", &n);
    while (l < r) {
        long long mid = (l + r) / 2;
        long long len = mid * log10(mid) + 1;
        if (len < n)
            l = mid + 1;
        else
            r = mid;
    }
    printf("%lld", l);
    return 0;
}
