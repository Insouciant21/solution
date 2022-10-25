#include <bits/stdc++.h>

using namespace std;

long long mem[20][20];
string s;

long long dp(int i, bool is_limit, bool is_num, long long sum) {
    if (i == s.length()) return mem[i][sum] = sum;
    if (!is_limit && is_num && mem[i][sum] >= 0) return mem[i][sum];
    long long res = 0;
    if (!is_num) res += dp(i + 1, false, false, sum);
    int up = (is_limit) ? s[i] - '0' : 9;
    for (int d = 1 - is_num; d <= up; d++) {
        res += dp(i + 1, is_limit and d == s[i] - '0', true);
    }
    if (!is_limit && is_num) mem[i] = res;
    return res;
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    long long a, b;
    cin >> a >> b;
    s = to_string(a - 1);
    memset(mem, -1, sizeof mem);
    long long k = dp(0, true, false);
    memset(mem, -1, sizeof mem);
    s = to_string(b);
    cout << dp(0, true, false) - k << endl;
    return 0;
}