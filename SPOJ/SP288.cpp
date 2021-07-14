/*
  Problem: SP288
  Time: 2020/11/14 12:14:23
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

mt19937 g(rand());

ll mul(ll a, ll b, ll p) {
    ll res = 0;
    while (b) {
        if (b & 1)
            res = (res + a) % p;
        a = (a + a) % p;
        b >>= 1;
    }
    return res;
}

ll quickPow(ll a, ll b, ll p) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = mul(res, a, p);
        a = mul(a, a, p);
        b >>= 1;
    }
    return res;
}

bool miller_rabin(ll a, ll n) {
    ll m = n - 1, q = 0;
    while (!(m & 1)) {
        m >>= 1;
        q++;
    }
    ll v = quickPow(a, m, n);
    if (v == 1 || v == n - 1)
        return true;
    for (int i = 0; i < q; i++) {
        if (v == n - 1)
            return true;
        v = mul(v, v, n);
    }
    return false;
}

bool prime_test(ll n) {
    srand(time(NULL));
    if (n == 2)
        return true;
    if (n < 2 || !(n & 1))
        return false;
    for (int i = 0; i < 16; i++) {
        ll a = g() % (n - 1) + 1;
        if (!miller_rabin(a, n))
            return false;
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long p = 0;
        scanf("%lld", &p);
        printf((prime_test(p)) ? "YES\n" : "NO\n");
    }
    return 0;
}