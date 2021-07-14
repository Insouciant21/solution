/*
  Problem: CF70A
  Time: 2020/10/02 13:33:38
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int n;
long long ans = 1;

const int modp = int(1e6) + 3;

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        ans *= 3;
        ans %= modp;
    }
    printf("%lld\n", ans);
    return 0;
}