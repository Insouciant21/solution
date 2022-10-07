#include <bits/stdc++.h>

using namespace std;

const int modp = 998244353;
const int maxn = 1e5 + 10;

long long quickPow(long long a, int e) {
    long long res = 1;
    while (e) {
        if (e & 1) res = res * a % modp;
        a = a * a % modp;
        e >>= 1;
    }
    return res;
}

inline long long c(int n, int m) {
    if (n < m) return 0;
    if (m > n - m) m = n - m;
    long long a = 1, b = 1;
    for (int i = 0; i < m; i++) {
        a = (a * (n - i)) % modp;
        b = (b * (i + 1)) % modp;
    }
    return a * quickPow(b, modp - 2) % modp;
}

long long lucas(int n, int m) {
    if (m == 0) return 1;
    return lucas(n / modp, m / modp) * c(n % modp, m % modp) % modp;
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    cin >> n;
    if (n == 1) cout << 0 << endl;
    else {
        long long ans = quickPow(2, n - 2);
        if (!(n & 1)) ans -= lucas(n - 2, n / 2 - 1);
        cout << (ans + modp) % modp << endl;
    }
    return 0;
}