#include <bits/stdc++.h>

using namespace std;

long long mem[20][20];
string num;

long long dp(int i, int sum, int digit, bool lim, bool is_num) {
    if (!lim && !is_num && mem[i][sum] != -1) return mem[i][sum];
    if (i == num.length()) return mem[i][sum] = sum;
    long long res = 0;
    for (int d = 0; d <= 9; d++) {
        if (lim && d > num[i] - '0') break;
        res += dp(i + 1, sum + ((!is_num || d) && d == digit), digit, lim && d == num[i] - '0', is_num && d == 0);
    }
    if (!lim && !is_num) mem[i][sum] = res;
    return res;
}

long long work(int digit, long long g) {
    num = to_string(g);
    memset(mem, -1, sizeof mem);
    return dp(0, 0, digit, true, true);
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    long long a, b;
    cin >> a >> b;
    for (int i = 0; i <= 9; i++) cout << work(i, b) - work(i, a - 1) << " ";
    return 0;
}