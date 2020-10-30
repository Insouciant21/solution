/*
  Problem: P2388
  Time: 2020/10/26 20:43:21
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    scanf("%d", &n);
    long long cnt = 0;
    for (register int i = 1; i <= n; i++) {
        int p = i;
        int c = 0;
        while (p % 5 == 0) {
            p /= 5;
            c++;
        }
        cnt += c * (n - i + 1LL);
    }
    printf("%lld", cnt);
    return 0;
}