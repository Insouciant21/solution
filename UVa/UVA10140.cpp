#include <bits/stdc++.h>

using namespace std;

long long prime[int(1e6) + 1];

long long quickPow(long long a, long long b, long long p) {
    long long res = 1;
    while (b) {
        if (b & 1)
            res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}

bool millerRabin(long long n) {
    if (n < 2)
        return false;
    if (n == 2 || n == 3)
        return true;
    long long a = n - 1, b = 0;
    while (a % 2 == 0)
        a /= 2, b++;
    for (int i = 1, j; i <= 25; i++) {
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

int main() {
    int l, r;
    while (scanf("%d %d", &l, &r) != EOF) {
        int cnt = 0;
        for (long long i = l; i <= r; i++) {
            if (millerRabin(i))
                prime[++cnt] = i;
        }
        if (cnt <= 1) {
            printf("There are no adjacent primes.\n");
            continue;
        }
        pair<int, int> a, b;
        int maxd = 0, mind = 0x3f3f3f;
        for (int i = 1; i < cnt; i++) {
            long long dist = prime[i + 1] - prime[i];
            if (dist > maxd) {
                maxd = dist;
                b.first = prime[i];
                b.second = prime[i + 1];
            }
            if (dist < mind) {
                mind = dist;
                a.first = prime[i];
                a.second = prime[i + 1];
            }
        }
        printf("%d,%d are closest, %d,%d are most distant.\n", a.first, a.second, b.first, b.second);
        memset(prime, 0, sizeof(prime));
    }
    return 0;
}