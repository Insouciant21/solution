#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

map<long long, long long> f;

long long quickPow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

long long fib(long long n) {
    if (n <= 2) return 1;
    if (!f.count(n)) {
        long long fn, fn1, res;
        if (n % 2 == 0) {
            fn = fib(n / 2);
            fn1 = fib(n / 2 + 1);
            res = fn % MOD * (2 * fn1 % MOD - fn) % MOD;
        }
        else {
            fn = fib(n / 2);
            fn1 = fib((n + 1) / 2);
            res = (quickPow(fn, 2) + quickPow(fn1, 2)) % MOD;
        }
        f[n] = (res + MOD) % MOD;
    }
    return f[n];
}

int main() {
    long long n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}
