/*
  Problem: SP4942
  Time: 2020/11/14 09:20:37
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

void factor(long long n) {
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                cnt++;
                n /= i;
            }
            printf("%lld^%d ", i, cnt);
        }
    }
    if (n > 1)
        printf("%lld^1", n);
    printf("\n");
}

int main() {
    while (true) {
        long long n;
        scanf("%lld", &n);
        if (!n)
            break;
        factor(n);
    }
    return 0;
}