/*
  Problem: P4446
  Time: 2020/11/14 12:28:41
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll cube[int(1e6) + 2];
bitset<40001> numlist;
int prime[40000];

void prepare() {
    int cnt = 0;
    for (int i = 2; i < 40000; i++) {
        if (!numlist[i])
            prime[++cnt] = i;
        for (int j = 1; j <= cnt && prime[j] * i < 40000; j++) {
            numlist[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
    cnt = 0;
    for (long long p = 1; p * p * p <= (long long)(1e18); p++)
        cube[++cnt] = p * p * p;
}

int main() {
    int t;
    prepare();
    scanf("%d", &t);
    while (t--) {
        long long n;
        scanf("%lld", &n);
        long long ans = 1;
        for (int i = 1; i <= 4203 && prime[i] <= n; i++) {
            int c = 0;
            while (n % prime[i] == 0) {
                n /= prime[i];
                c++;
                if (c == 3) {
                    ans *= prime[i];
                    c = 0;
                }
            }
        }
        ll p = lower_bound(cube + 1, cube + 1000001, n) - cube;
        if (p * p * p == n)
            ans = ans * p;
        printf("%lld\n", ans);
    }
    return 0;
}