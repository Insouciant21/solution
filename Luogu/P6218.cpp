#include <bits/stdc++.h>

using namespace std;

const int maxn = 40;

int mem[maxn][maxn][maxn];
string s;

int dp(int i, bool lim, bool zero, int cnt1, int cnt2) {
    if (!lim && !zero && mem[i][cnt1][cnt2] != -1) return mem[i][cnt1][cnt2];
    if (i == s.length()) return mem[i][cnt1][cnt2] = (cnt1 >= cnt2);
    int res = 0;
    for (int d = 0; d <= 1; d++) {
        if (lim && d > s[i] - '0') break;
        res += dp(i + 1, lim && d == s[i] - '0', zero && d == 0, cnt1 + ((d == 0) && !zero), cnt2 + (d == 1));
    }
    if (!lim && !zero) mem[i][cnt1][cnt2] = res;
    return res;
}

int solve(int g) {
    s.clear();
    while (g) {
        s.push_back(char((g & 1) + '0'));
        g >>= 1;
    }
    reverse(s.begin(), s.end());
    memset(mem, -1, sizeof mem);
    return dp(0, true, true, 0, 0);
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int l, r;
    cin >> l >> r;
    cout << solve(r) - solve(l - 1) << endl;
    return 0;
}