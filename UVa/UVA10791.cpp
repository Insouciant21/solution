#include <bits/stdc++.h>

using namespace std;

long long solve(int n) {
    if (n == 1) return 2;
    long long ans = 0;
    int maxp = int(round(sqrt(n)));
    int cnt = 0;
    for (int i = 2; i <= maxp; i++) {
        if (n % i) continue;
        int c = 1;
        while (n % i == 0) n /= i, c *= i;
        ans += c, cnt++;
    }
    if (n > 1) ans += n, cnt++;
    if (cnt <= 1) ans++;
    return ans;
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, kase = 0;
    while (scanf("%d", &n) == 1 && n != 0) printf("Case %d: %lld\n", ++kase, solve(n));
    return 0;
}
