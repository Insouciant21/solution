/*
  Problem: SP22403
  Time: 2020/11/07 08:59:16
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

const int modp = 1000000007;
int prime[int(5e4) + 1];
int cnt;

void prepare_table() {
    const int maxn = 5e4 + 1;
    bitset<int(5e4) + 1> a;
    for (int i = 2; i < maxn; i++) {
        if (!a[i]) prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] < maxn; j++) {
            a[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int get_exp(int n, int p) {
    long long ans = 0;
    while (n) {
        ans += n / p;
        n /= p;
    }
    return ans % modp;
}

int main() {
    int T;
    prepare_table();
    scanf("%d", &T);
    while (T--) {
        int n;
        int ans = 1;
        scanf("%d", &n);
        for (int i = 1; prime[i] <= n && i <= cnt; i++) {
            ans = ans % modp * (get_exp(n, prime[i]) + 1LL) % modp;
        }
        printf("%d\n", ans);
    }
    return 0;
}