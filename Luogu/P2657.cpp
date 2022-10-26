#include <bits/stdc++.h>

using namespace std;

const int maxn = 19;
int f[maxn][maxn];
string num;

int dp(int i, int last, bool lim, bool zero) {
    if (!lim and !zero and f[i][last] != -1) return f[i][last];
    if (i == num.length()) return !zero;
    int res = 0;
    for (int d = 0; d <= 9; d++) {
        if (lim && d > num[i] - '0') break;
        if (!zero && abs(d - last) < 2) continue;
        res += dp(i + 1, d, lim and d == num[i] - '0', zero && d == 0);
    }
    if (!lim and !zero) f[i][last] = res;
    return res;
}

int solve(int x) {
    num = to_string(x);
    memset(f, -1, sizeof f);
    return dp(0, 0, true, true);
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", solve(b) - solve(a - 1));
    return 0;
}