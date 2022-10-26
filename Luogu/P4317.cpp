#include <bits/stdc++.h>

using namespace std;

const int maxn = 55, mod = 1e7 + 7;
string num;
long long f[maxn][maxn];

long long quickPow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

long long dp(int i, int x, bool lim, bool zero) {
    if (x < 0) return 0;
    if (i == num.length()) {
        if (!x && !zero) return f[i][x] = 1;
        else return f[i][x] = 0;
    }
    if (!lim && !zero && f[i][x] >= 0) return f[i][x];
    long long res = 0;
    for (int d = 0; d <= 1; d++) {
        if (lim and d > num[i] - '0') break;
        if (d == 1 && x == 0) continue;
        res = (res + dp(i + 1, x - (d == 1), lim and d == num[i] - '0', zero && d == 0));
    }
    if (!lim && !zero) f[i][x] = res;
    return res;
}

long long solve(long long n) {
    while (n) {
        num.push_back(char((n & 1) + '0'));
        n >>= 1;
    }
    reverse(num.begin(), num.end());
    long long res = 1;
    for (int i = 1; i < maxn; i++) {
        memset(f, -1, sizeof f);
        res = (res * quickPow(i, dp(0, i, true, true))) % mod;
    }
    return res;
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    long long n;
    scanf("%lld", &n);
    printf("%lld\n", solve(n));
    return 0;
}