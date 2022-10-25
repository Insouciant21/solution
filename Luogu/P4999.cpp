#include <bits/stdc++.h>

using namespace std;

const int maxLen = 20, mod = 1e9 + 7;
long long f[maxLen][maxLen][2][2];
string num;

long long dp(int i, int sum, int digit, bool lim, bool zero) {
    if (f[i][sum][lim][zero] != -1) return f[i][sum][lim][zero];
    if (i == num.length()) return f[i][sum][lim][zero] = sum;
    long long res = 0;
    for (int d = 0; d <= 9; d++) {
        if (lim && d > num[i] - '0') break;
        res += dp(i + 1, sum + ((!zero || d) && d == digit), digit, lim && d == num[i] - '0', zero && d == 0);
    }
    return f[i][sum][lim][zero] = res;
}

long long solve(long long g) {
    num = to_string(g);
    long long res = 0;
    for (int i = 1; i <= 9; i++) {
        memset(f, -1, sizeof f);
        long long k = dp(0, 0, i, true, true) % mod;
        res = (res % mod + k * i % mod) % mod;
    }
    return res;
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        long long l, r;
        cin >> l >> r;
        cout << (solve(r) - solve(l - 1) + 10LL * mod) % mod << endl;
    }
    return 0;
}