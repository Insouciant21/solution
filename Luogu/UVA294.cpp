/*
  Problem: UVA294
  Time: 2020/10/22 18:37:32
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

const int test = 25;
bitset<101> numlist;
int prime[101];
int cnt = 0;

void prepare() {
    numlist[0] = numlist[1] = 1;
    for (int i = 1; i <= 100; i++) {
        if (!numlist[i])
            prime[++cnt] = i;
        for (int j = 1; j <= cnt && i * prime[j] <= 100; j++) {
            numlist[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
long long quickPow(long long a, long long b, long long p) {
    long long res = 1;
    for (; b; b >>= 1, a = a * a % p) {
        if (b & 1)
            res = res * a % p;
    }
    return res;
}

bool millerRabin(long long n) {
    if (n < 2)
        return false;
    if (n == 2 || n == 3)
        return true;
    long long a = n - 1, b = 0;
    while (a % 2 == 0) a /= 2, b++;
    for (int i = 1, j; i <= test; i++) {
        long long x = rand() % (n - 2) + 2, v = quickPow(x, a, n);
        if (v == 1 || v == n - 1)
            continue;
        for (j = 0; j < b; j++) {
            v = v * v % n;
            if (v == n - 1)
                break;
        }
        if (j >= b)
            return false;
    }
    return true;
}

long long solve(long long n) {
    if (millerRabin(n))
        return 2;
    long long res = 1;
    for (int i = 1; i <= cnt && prime[i] <= n / 2; i++) {
        long long cnt = 1;
        while (n % prime[i] == 0) {
            n /= prime[i];
            cnt++;
        }
        res *= cnt;
    }
    if (n > 1)
        res *= 2;
    return res;
}

int main() {
    int t;
    scanf("%d", &t);
    prepare();
    while (t--) {
        long long l, r, ans = 0;
        long long m = 0;
        scanf("%lld %lld", &l, &r);
        for (long long i = l; i <= r; i++) {
            long long p = solve(i);
            if (p > ans) {
                ans = p;
                m = i;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n", l, r, m, ans);
    }
    return 0;
}