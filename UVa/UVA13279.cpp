// Status: NULL

#include <bits/stdc++.h>

using namespace std;

const int MOD = 100000007;

map<int, long long> p;

int n;

void factor(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                x /= i;
                cnt++;
            }
            p[i] += cnt * (n - x + 1LL);
        }
    }
    if (x > 1)
        p[x] += (n - x + 1LL);
}

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; i++) factor(i);
        long long ans = 1;
        for (auto &iter : p) ans = ans * (iter.second + 1) % MOD;
        printf("%lld\n", ans);
        p.clear();
    }
    return 0;
}