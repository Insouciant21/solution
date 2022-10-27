#include <bits/stdc++.h>

using namespace std;

long long n, m;

long long f[300000][200];
string s;

long long dp(int i, int mask, long long g, bool zero) {
    if (!zero && f[mask][g] >= 0) return f[mask][g];
    if (i == s.length()) return f[mask][g] = !g;
    long long res = 0;
    bool vis[20] = {false};
    for (int d = 0; d < s.length(); d++) {
        if (((mask >> d) & 1)) continue;
        if (i == 0 && s[d] == '0') continue;
        if (vis[s[d] - '0']) continue;
        vis[s[d] - '0'] = true;
        res += dp(i + 1, mask | (1 << d), (g * 10 + s[d] - '0') % m, zero && s[d] == '0');
    }
    if (!zero) f[mask][g] = res;
    return res;
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m;
    s = to_string(n);
    sort(s.begin(), s.end());
    memset(f, -1, sizeof f);
    cout << dp(0, 0, 0, true);
    return 0;
}