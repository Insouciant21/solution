#include <bits/stdc++.h>

using namespace std;

string num;
long long f[14][4][2][10][13];

long long dp(int i, int e84, bool repeated, bool lim, int last, int lastn) {
    if (!lim && f[i][e84][repeated][last][lastn] >= 0) return f[i][e84][repeated][last][lastn];
    if (i == num.length()) return f[i][e84][repeated][last][lastn] = repeated || lastn >= 3;
    long long res = 0;
    for (int d = ((i == 0) ? 1 : 0); d <= 9; d++) {
        if (lim and d > num[i] - '0') break;
        if (e84 == 1 && d == 8) continue;
        if (e84 == 2 && d == 4) continue;
        int g = e84;
        if (!g && d == 4) g = 1;
        if (!g && d == 8) g = 2;
        res += dp(i + 1, g, repeated || lastn >= 3, lim && d == num[i] - '0', d, d == last ? lastn + 1 : 1);
    }
    if (!lim) f[i][e84][repeated][last][lastn] = res;
    return res;
}

long long solve(long long n) {
    num = to_string(n);
    memset(f, -1, sizeof f);
    if (num.length() == 12) num = to_string(n - 1);
    if (num.length() == 10) return 0;
    return dp(0, 0, false, true, 0, 0);
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    long long l, r;
    scanf("%lld %lld", &l, &r);
    printf("%lld\n", solve(r) - solve(l - 1));
    return 0;
}